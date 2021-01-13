#define _CRT_SECURE_NO_WARNINGS
#define MY_ERROR (-101)
#include <iostream>
#include <string>
#include "RPC_lab2_interface_h.h"

int GetFileSize(std::string pathToFile)
{
	FILE* p_file = NULL;
	p_file = fopen(pathToFile.c_str(), "rb");
	if (p_file == NULL)
	{
		printf("fopen error");
		return MY_ERROR;
	}
	fseek(p_file, 0, SEEK_END);
	int size = ftell(p_file);
	fclose(p_file);
	return size;
}

int RPC_login(
	/* [in] */ handle_t IdHandle,
	/* [string][in] */ unsigned char* username,
	/* [string][in] */ unsigned char* password)
{
	// IdHandle is a handel to token of logged-on user
	int status = LogonUserA((LPCSTR)username, ".", (LPCSTR)password, LOGON32_LOGON_INTERACTIVE, LOGON32_PROVIDER_DEFAULT, &IdHandle);
	if (status == 0)
	{
		status = GetLastError();
		printf("LogonUserA error");
		return status;
	}

	//function lets the calling thread impersonate the security context of a logged-on user. 
	//The user is represented by a token handle.
	status = ImpersonateLoggedOnUser(IdHandle);
	if (status == 0)
	{
		status = GetLastError();
		printf("ImpersonateLoggedOnUser error");
		return status;
	}

	printf("Successfully logined: %s\n", username);
	return ERROR_SUCCESS;
}

void RPC_logout(void)
{
	//function terminates the impersonation of a client application.
	int status = RevertToSelf();
	if (status == 0)
	{
		RPC_exit();
	}
}

void RPC_exit(void)
{
	RPC_STATUS status;

	RevertToSelf();

	status = RpcMgmtStopServerListening(NULL);
	if (status)
		exit(status);

	status = RpcServerUnregisterIf(NULL, NULL, 0);
	if (status)
		exit(status);
}

// Server functions.
int RPC_download(
	/* [string][in] */ const unsigned char* pathToFile,
	/* [size_is][out][in] */ unsigned char* data,
	/* [out][in] */ unsigned int* sizePayload,
	/* [out][in] */ unsigned int* fileFullSize)
{
	static FILE* fileOnServer = NULL;
	static int fileSize = 0;
	static size_t sizeTransferredData = 0;

	if (fileOnServer == NULL)
	{
		fileSize = GetFileSize((char*)pathToFile);
		if (fileSize <= 0)
		{
			printf("GetFileSize error");
			return -1;
		}

		fileOnServer = fopen((const char*)pathToFile, "rb");
		if (fileOnServer == NULL)
		{
			printf("fopen error");
			return -1;
		}
	}

	size_t res = fread(data, sizeof(BYTE), IO_BUF_SIZE, fileOnServer);
	if (res <= 0)
	{
		printf("fread error");
		fclose(fileOnServer);
		fileOnServer = NULL;
		return -1;
	}

	*sizePayload = res;
	*fileFullSize = fileSize;

	sizeTransferredData += res;

	if (sizeTransferredData == fileSize)
	{
		fclose(fileOnServer);
		fileOnServer = NULL;
	}

	return 0;
}

int RPC_upload(
	/* [string][in] */ const unsigned char* pathToFile,
	/* [in] */ int sizePayload,
	/* [size_is][in] */ unsigned char* data,
	/* [in] */ unsigned int fileFullSize)
{
	static FILE* fileOnServer = NULL;
	static unsigned int fileSize = 0;
	static unsigned int sizeReceivedData = 0;

	if (fileSize == 0)
	{
		fileOnServer = fopen((const char*)pathToFile, "wb");
		if (fileOnServer == NULL)
		{
			printf("fopen error");
			return -1;
		}

		fileSize = fileFullSize;
		sizeReceivedData = 0;
	}

	fwrite(data, sizeof(BYTE), sizePayload, fileOnServer);
	sizeReceivedData += sizePayload;

	if (sizeReceivedData == (size_t)fileSize)
	{
		fileSize = 0;
		fclose(fileOnServer);
	}

	return 0;
}

int RPC_delete(
	/* [string][in] */ const unsigned char* pathToFile)
{
	int err = remove((const char*)pathToFile);
	if (err != 0) 
	{
		err = errno;

		if (err == EACCES)
		{
			printf("Access is denied\n");
		}
		else if (err == ENOENT)
		{
			printf("Path is incorrect\n");
		}
		else
		{
			printf("remove error");
		}

		return err;
	}

	return err;
}

RPC_STATUS CALLBACK SecurityCallback(RPC_IF_HANDLE /*hInterface*/, void* /*pBindingHandle*/)
{
	return RPC_S_OK;
}

// Memory allocation function for RPC.
// The runtime uses these two functions for allocating/deallocating
// enough memory to pass the string to the server.
void* __RPC_USER midl_user_allocate(size_t size)
{
	return malloc(size);
}

// Memory deallocation function for RPC.
void __RPC_USER midl_user_free(void* p)
{
	free(p);
}

int main()
{
	RPC_STATUS status;

	// Uses the protocol combined with the endpoint for receiving
	// remote procedure calls.
	status = RpcServerUseProtseqEpA(
		(RPC_CSTR)("ncacn_ip_tcp"), // Use TCP/IP protocol.
		RPC_C_PROTSEQ_MAX_REQS_DEFAULT, // Backlog queue length for TCP/IP.
		(RPC_CSTR)("9000"),         // TCP/IP port to use.
		NULL);                          // No security.

	printf("Server is running.\nPort 9000\n");

	if (status)
		exit(status);

	// Registers the Example1 interface.
	status = RpcServerRegisterIf2(
		RPC_lab2_interface_v1_0_s_ifspec,               // Interface to register.
		NULL,											    // Use the MIDL generated entry-point vector.
		NULL,											    // Use the MIDL generated entry-point vector.
		RPC_IF_ALLOW_CALLBACKS_WITH_NO_AUTH,			    // Forces use of security callback.
		RPC_C_LISTEN_MAX_CALLS_DEFAULT,						// Use default number of concurrent calls.
		(unsigned)-1,										// Infinite max size of incoming data blocks.
		SecurityCallback);									// Naive security callback.

	if (status)
		exit(status);

	RPC_BINDING_VECTOR* binding_vector = NULL;
	// Function returns the binding handles over which remote procedure calls can be received.
	status = RpcServerInqBindings(&binding_vector);
	if (status)
	{
		printf("RpcServerInqBindings error");
		exit(status);
	}

	// The RpcEpRegister function adds to or replaces server address information in the local endpoint-map database.
	status = RpcEpRegisterA(RPC_lab2_interface_v1_0_s_ifspec, binding_vector, NULL, NULL);
	if (status)
	{
		printf("RpcEpRegisterA error");
		exit(status);
	}

	// Start to listen for remote procedure
	// calls for all registered interfaces.
	// This call will not return until
	// RpcMgmtStopServerListening is called.
	status = RpcServerListen(
		1,                                   // Recommended minimum number of threads.
		RPC_C_LISTEN_MAX_CALLS_DEFAULT,      // Recommended maximum number of threads.
		FALSE);                              // Start listening now.

	if (status)
		exit(status);
}