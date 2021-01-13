# fileManager
A file manager for downloading, sending and deleting files.

# RPC interface
At the beginning of the work, the RPC interface was implemented, which describes the functions that implement the client-server application. The definition of this interface was written in MIDL (Microsoft Interface Definition Language) in a text file with the .idl extension.
The UUID was generated using the Online UUID Generator.
After building the project containing this file, MS Visual Studio 2017 generates two files with the .c extension and one header file used in the source codes of the client and server applications.

# Server
The server side works on the statefull protocol, storing information about the client. If the server starts successfully, diagnostic information is output to the console.

# Client
At the beginning of the client's work, it is necessary to go through impersonation by entering the correct credentials, after which the remaining commands become available. If you enter incorrect data, the program will display a special message.

# Client commands
* help - show Help list
* download <HOST_PATH> <SERV_PATH> - download file from server
* upload <HOST_PATH> <SERV_PATH> - upload file to server
* exit - exit the program