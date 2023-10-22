#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <pthread.h>

// Function prototypes
void error(char* msg);
void* handleClient(void* client_socket);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int sockfd, newsockfd, portno;
    socklen_t cli_len;
    struct sockaddr_in serv_addr, cli_addr;

    portno = atoi(argv[1]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Error opening socket");
    }

    bzero((char*)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        error("Error on binding");
    }

    listen(sockfd, 5);
    cli_len = sizeof(cli_addr;

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &cli_len);
        if (newsockfd < 0) {
            error("Error accepting new connection");
            continue;
        }

        // Create a new thread to handle the client
        pthread_t thread;
        if (pthread_create(&thread, NULL, handleClient, (void*)&newsockfd) != 0) {
            error("Error creating thread");
            continue;
        }
    }

    // Cleanup and resource release
    close(sockfd);
    return 0;
}

void* handleClient(void* client_socket) {
    int newsockfd = *((int*)client_socket);
    char buffer[255];

    while (1) {
        bzero(buffer, 256);
        int n = read(newsockfd, buffer, 255);
        if (n < 0) {
            error("Error reading from client");
            break;
        }

        // Process the client's request

        n = write(newsockfd, buffer, strlen(buffer));
        if (n < 0) {
            error("Error writing to client");
            break;
        }
    }

    close(newsockfd);
    pthread_exit(NULL);
}

void error(char* msg) {
    perror(msg);
    exit(1);
}
