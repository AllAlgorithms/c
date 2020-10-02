/*
 ============================================================================
 Name        : TCP_Sender.c
 Author      : GodisC00L
 Description : Simple TCP sender. Expected input {Local IP address, port} send a
 message to the other side until message is "Bye".
 ============================================================================
 */

#include "TCP_sender.h"

#define BUFFER_SIZE 1024
#define MAX_CONNECTION 1

void error(char *msg) {
    perror(msg);
    exit(errno);
}

int main(int argc, char *argv[]) {
    int welcomeSocket, newSocket, pornNum, n;
    char buffer[BUFFER_SIZE + 1];
    struct sockaddr_in serverAddr, cliAddr;
    socklen_t client;

    /* Check if we have all necessary arguments are there*/
    if (argc < 3) {
        errno = EIO;
        error("Error");
    }
    pornNum = atoi(argv[2]);

    /*---- Create the socket. The three arguments are: ----
     * 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
    welcomeSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (welcomeSocket < 0){
        error("Error opening socket");
    }

    /*---- Configure settings of the server address struct ----
     * Setting zeros in serverAddr */
    bzero((char *) &serverAddr, sizeof(serverAddr));
    /* Address family = Internet */
    serverAddr.sin_family = AF_INET;
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(pornNum);
    /* Set IP address */
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    /*---- Bind the address struct to the socket ----*/
    if (bind(welcomeSocket, (struct sockaddr *) &serverAddr, sizeof(serverAddr))
        < 0) {
        close(welcomeSocket);
        error("ERROR on binding");
    }

    /*---- Listen on the socket, with 1 max connection requests queued ----*/
    if (!listen(welcomeSocket, MAX_CONNECTION))
        printf("Listening\n");
    else {
        close(welcomeSocket);
        error("ERROR");
    }

    /*---- Accept call creates a new socket for the incoming connection ----*/
    client = sizeof(cliAddr);
    newSocket = accept(welcomeSocket, (struct sockaddr *) &cliAddr, &client);
    if (newSocket < 0) {
        close(welcomeSocket);
        error("Error: Can't accept client");
    }

    /*---- Keep sending message until "Bye" or error ----*/
    do {
        printf("Enter Message: ");
        fgets(buffer, BUFFER_SIZE-1, stdin);
    }while (((n = send(newSocket, buffer, BUFFER_SIZE, 0)) >= 0) && (strcmp(buffer,"Bye") != 0));
    if (n < 0) {
        close(newSocket);
        close(welcomeSocket);
        error("Error sending from socket");
    }
    close(newSocket);
    close(welcomeSocket);
    return 0;
}
