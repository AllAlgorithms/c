/*
 ============================================================================
 Name        : TCP_receiver.c
 Author      : GodisC00L
 Description : Simple TCP receiver. Expected input {server IP address, port}.
 ============================================================================
 */

#include "TCP_receiver.h"

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(errno);
}

int main(int argc, char *argv[]) {
    int clientSocket, portn, n;
    char buffer[BUFFER_SIZE + 1];
    struct sockaddr_in serverAddr;

    /* Check if we have all necessary arguments are there*/
    if (argc < 3) {
        errno = EIO;
        error("Usage: IP Address, Port, Number of parts");
    }
    portn = atoi(argv[2]);

    /*---- Create the socket. The three arguments are: ----
     * 1) Internet domain 2) Stream socket 3) Default protocol (TCP in this case) */
    clientSocket = socket(PF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
        error("Error opening socket");

    /*---- Configure settings of the server address struct ----
     * Setting zeros in serverAddr */
    bzero((char *) &serverAddr, sizeof(serverAddr));
    /* Address family = Internet */
    serverAddr.sin_family = AF_INET;
    /* Set port number, using htons function to use proper byte order */
    serverAddr.sin_port = htons(portn);
    /* Set IP address */
    serverAddr.sin_addr.s_addr = inet_addr(argv[1]);

    /*---- Connect the socket to the server using the address struct ----*/
    if (connect(clientSocket, (struct sockaddr *) &serverAddr,
                sizeof(serverAddr)) < 0) {
        close(clientSocket);
        error("Error connecting");
    }

    /*---- Read the message from the server into the buffer ----*/
    do {
        /*---- Print the received message ----*/
        printf("%s", buffer);
    } while (((n = recv(clientSocket, buffer, BUFFER_SIZE, 0)) > 0) && (strcmp(buffer, "Bye") != 0));
    if (n < 0) {
        close(clientSocket);
        error("Error reading from socket");
    }
    if (!n) {
        close(clientSocket);
        error("Error socket reset");
    }
    close(clientSocket);
    return 0;
}
