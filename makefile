CC = gcc

CFLAGS = -Wall -Wextra -Werror -pedantic

.PHONY: all clean


server: server.c
	gcc server.c -o server

client: client.c
	gcc client.c -o client 

clean:
	rm -f server client
