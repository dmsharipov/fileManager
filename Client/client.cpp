#define _CRT_SECURE_NO_WARNINGS
#define MAX_CMD_ARGUMENTS_QNT 5
#define MY_ERROR (-101)
#include <stdio.h>
#include "RPC_lab2_interface_h.h"
#include <string>
#include <iostream>
#include <windows.h> 

enum commandNames
{
	delete_,
	upload_,
	download_,
	logout_,
	exit_,
	unknown,
	help
};

bool fExit = 0;

void ClientShutDown()
{
	fExit = 1;
}

commandNames parseCommand(char* command, char** argv) {

	int args_qnt = MAX_CMD_ARGUMENTS_QNT;

	argv[0] = strtok(command, " \n");
	for (int i = 1; i < MAX_CMD_ARGUMENTS_QNT; i++) {

		argv[i] = strtok(NULL, " \n");

		if (argv[i] == NULL) {

			args_qnt = i;
			break;
		}
	}

	if (argv[0] == NULL)
		return (unknown);
	else if (strcmp(argv[0], "download") == NULL)
		return (download_);
	else if (strcmp(argv[0], "upload") == NULL)
		return (upload_);
	else if (strcmp(argv[0], "delete") == NULL)
		return (delete_);
	else if (strcmp(argv[0], "exit") == NULL)
		return (exit_);
	else if (strcmp(argv[0], "logout") == NULL)
		return (logout_);
	else if (strcmp(argv[0], "help") == NULL)
		return (help);
	else
		return (unknown);
}

void PrintCommandList() {

	printf("\n\nHelp list:\n");
	printf("\thelp - show Help list\n");
	printf("\tdownload <HOST_PATH> <SERV_PATH>\n");
	printf("\tupload <HOST_PATH> <SERV_PATH>\n");
	printf("\tdelete <SERV_PATH>\n");
	printf("\texit - exit program\n");
	printf("\n");
}

int GetFileSize(std::string  pathToFile)
{
	FILE* p_file = NULL;
	p_file = fopen(pathToFile.c_str(), "rb");
	if (p_file == NULL)
	{
		printf("GetFileSize error");
		return MY_ERROR;
	}
	fseek(p_file, 0, SEEK_END);
	int size = ftell(p_file);
	fclose(p_file);
	return size;
}

void UploadFile(char* pathToFileLocal, char* pathTofileOnServer)
{
	if ((pathToFileLocal == NULL) || pathTofileOnServer == NULL)
	{
		printf("incorrect arguments");
		return;
	}

	int fileSize = GetFileSize(pathToFileLocal);
	if (fileSize <= 0)
	{
		printf("GetFileSize error");
		return;
	}

	FILE* fileLocal = fopen(pathToFileLocal, "rb");
	if (fileLocal == NULL)
	{
		printf("fopen error");
		return;
	}

	int res;
	int sizePayload;
	unsigned char buf[IO_BUF_SIZE];
	while (1)
	{
		sizePayload = fread(buf, sizeof(BYTE), IO_BUF_SIZE, fileLocal);
		if (sizePayload <= 0)
		{
			if (sizePayload == 0)
			{
				break;
			}
			else
			{
				printf("fread error");
				fclose(fileLocal);
				return;
			}
		}

		res = RPC_upload((const unsigned char*)pathTofileOnServer, sizePayload, buf, fileSize);
		if (res < 0)
		{
			printf("RPC_upload error");
			fclose(fileLocal);
			return;
		}
	}
}

void DownloadFile(char* pathToFileLocal, char* pathTofileOnServer)
{
	if ((pathToFileLocal == NULL) || pathTofileOnServer == NULL)
	{
		printf("incorrect arguments");
		return;
	}

	FILE* fileLocal = fopen(pathToFileLocal, "wb");
	if (fileLocal == NULL)
	{
		printf("fopen error");
		return;
	}

	unsigned char buf[IO_BUF_SIZE];
	unsigned int sizePayload;
	unsigned int fileFullSize;
	unsigned int sizeReceivedData = 0;
	int res;
	while (1)
	{
		res = RPC_download((const unsigned char*)pathTofileOnServer, buf, &sizePayload, &fileFullSize);
		if (res < 0)
		{
			printf("RPC_download error");
			fclose(fileLocal);
			return;
		}

		fwrite(buf, sizeof(BYTE), sizePayload, fileLocal);

		sizeReceivedData += sizePayload;

		if (sizeReceivedData == fileFullSize)
		{
			break;
		}
	}
}

int ClientLogIn()
{
	char username[101];
	char password[101];

	int status = ERROR_LOGON_FAILURE;
	while (status == ERROR_LOGON_FAILURE)
	{
		printf("Please, enter login and password for connection.");
		printf("\nlogin>> ");
		gets_s((char*)username, 100);
		printf("\npassword>> ");
		gets_s((char*)password, 100);

		status = RPC_login((handle_t)interface_handle, (unsigned char*)username, (unsigned char*)password);
		if (status == ERROR_LOGON_FAILURE)
		{
			printf("Incorrect username/password!\n");
		}
		else if (status != ERROR_SUCCESS)
		{
			printf("RPC_LogIn error");
			return status;
		}
	}

	printf("login: DONE\n");

	return 0;
}

int ClientConnect(RPC_CSTR* szStringBinding)
{
	RPC_STATUS status;

// Creates a string binding handle.
// This function is nothing more than a printf.
// Connection is not done here.
	status = RpcStringBindingComposeA(
		NULL,                                        // UUID to bind to.
		(RPC_CSTR)("ncacn_ip_tcp"),		// Use TCP/IP protocol.
		(RPC_CSTR)("192.168.1.17"),    // TCP/IP network address to use.
		(RPC_CSTR)("9000"),				// TCP/IP port to use.
		NULL,                                    // Protocol dependent network options to use.
		szStringBinding);                       // String binding output.

	if (status)
		return status;

	// Validates the format of the string binding handle and converts
	// it to a binding handle.
	// Connection is not done here either.
	status = RpcBindingFromStringBindingA(
		*szStringBinding,					  // The string binding to validate.
		&interface_handle);					  // Put the result in the implicit binding
											  // handle defined in the IDL file.

	if (status)
		return status;

	status = ClientLogIn();
	if (status)
	{
		printf("ClientLogIn error");

		RpcStringFreeA(szStringBinding); 
		RpcBindingFree(&interface_handle);
		return status;
	}

	return 0;
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
	RPC_CSTR szStringBinding = NULL;

	status = ClientConnect(&szStringBinding);
	if (status)
	{
		printf("ClientConnect error");
		exit(status);
	}

	printf("\n<<Welcome to the client programm!>>\n");

	PrintCommandList();

	char command[1000];
	char* argv[MAX_CMD_ARGUMENTS_QNT];
	commandNames curCommand;
	int res;
	while (!fExit) {

		memset((void*)argv, 0, sizeof(char*) * MAX_CMD_ARGUMENTS_QNT);

		fflush(stdin);
		printf("\nEnter command: ");
		fgets(command, sizeof(command), stdin);
		curCommand = parseCommand(command, argv);

		Sleep(1000);

		if (fExit)
		{
			break;
		}

		switch (curCommand) {

		case delete_:
			res = RPC_delete((unsigned char*)argv[1]);
			if (res != 0)
			{
				if (res == EACCES)
				{
					printf("Access is denied\n");
				}
				else if (res == ENOENT)
				{
					printf("Path is incorrect\n");
				}
				else
				{
					printf("RPC_delete error");
				}
			}
			break;

		case upload_:
			UploadFile(argv[1], argv[2]);
			break;

		case download_:
			DownloadFile(argv[1], argv[2]);
			break;

		case exit_:
			RPC_exit();
			fExit = 1;
			break;

		case help:
			PrintCommandList();
			break;

		case unknown:
			printf("\nUnrecognised command\n");
			break;

		default:
			printf("\n\n\nHow???\n\n");
			break;
		}
	}

	RPC_logout();

	// Free the memory allocated by a string.
	status = RpcStringFreeA( &szStringBinding); // String to be freed.

	if (status) exit(status);

	// Releases binding handle resources and disconnects from the server.
	status = RpcBindingFree(&interface_handle); // Frees the implicit binding handle defined in the IDL file.

	if (status) exit(status);
}