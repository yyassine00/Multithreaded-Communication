# Description 

This program containstwo executable files called 'client.c' and 'server.c'. These files are used to create a reverse echo client-server model 
that for sending and recieving messages between two endpoints using TCP protocol. The client sends a message to the server then the server 
reverses the message and sends it back to the client. 

# Execution Environment 

This program is writtin in C programming language and is compatibale with any Unix-based operating systems. This program has been tested on 
Debian with gcc compiler version 9.3.0.

# Building and Running The Program 

## To build the program run the following:

$ make 

This will result in two executables being created. 'client' and 'server'.

## To run the program run the following:

$ ./server (port number)

- Use last four digits of student ID number to avoid confliction.

$ ./client (server address) (port number)

- If you encounter 'permission denied error' run the following command: $ chmod +x server

To terminate the program, type 'fin'








