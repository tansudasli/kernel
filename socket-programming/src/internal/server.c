#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/un.h>
#include <sys/socket.h>
#include <unistd.h>


#define MAX_QUEUE_LENGTH 2
#define SOCKET_NAME "/tmp/dummy"
#define BUFFER_SIZE 256

char buffer[BUFFER_SIZE];

/**
 * Logic implementation sample
 * Server gets numeric values, then keep adding to calculate results
 * If gets 0, then return total!
 *
 * @param buffer = input char[], but contains integers
 */
int total = 0;
int sum(char buf[]) {
    int data;

    memcpy(&data, buffer, sizeof(int));

    total += data;

    if (data == 0) return 0;

    return -1;
}

/**
 * Basically, It creates a socket(), bind(), listen(), and accept() (master blocking).
 * Waits client's connect() at accept phase.
 * Then read() data (client blocking), and process request then write() (client non-blocking) to client.
 *
 * Supported Operations
 *  - sum() : gets numeric chars, and calculate total value. If gets 0, then returns total result.
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char const *argv[]) {

    //remove the socket, in case of abnormal termination!
    unlink(SOCKET_NAME);

    //create the socket
    int masterSocket = socket(AF_LOCAL, SOCK_STREAM, 0);
    if (masterSocket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    printf("Master socket created\n");

    //define and bind the server address
    struct sockaddr_un serverAddress;
    memset(&serverAddress, 0, sizeof(struct sockaddr_un));

    serverAddress.sun_family = AF_LOCAL;
    strncpy(serverAddress.sun_path, SOCKET_NAME, sizeof(SOCKET_NAME) - 1);

    int status = bind(masterSocket, (struct sockaddr *) &serverAddress, sizeof(serverAddress));
    if (status == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }

    printf("Bind b/w  %s address and socket[%d] succeeded\n", SOCKET_NAME, masterSocket);

    //listen
    status = listen(masterSocket, MAX_QUEUE_LENGTH);
    if (status == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Listening on %s w/ max backlog conn. = %d\n", SOCKET_NAME, MAX_QUEUE_LENGTH);

    //accept
    for (;;) {
        //now, we use dataSocket, not masterSocket. masterSocket will create this new socket !
        //blocking operation !!
        //todo: make it multi-thread, non blocking
        int dataSocket = accept(masterSocket, NULL, NULL);
        if (dataSocket == -1) {
            perror("accept");
            exit(EXIT_FAILURE);
        }

        printf("Data socket created. Accepting...\n");

        //receive
        int result = 0;
        for (;;) {
            memset(buffer, 0, BUFFER_SIZE);

            printf("Waiting data from client...\n");

            //blocking operation !!
            status = read(dataSocket, buffer, BUFFER_SIZE);
            if (status == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            //todo: implementation point of client-server command logic
            result = sum(buffer);
            if (result == 0) break;
        }

        //send back to client
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "Result = %d", result);

        printf("Sendin data [%s] to client...\n", buffer);
        //non-blocking operation !!
        status = write(dataSocket, buffer, BUFFER_SIZE);
        if (status == -1) {
            perror("write");
            exit(EXIT_FAILURE);
        }

        //close socket
        close(dataSocket);
    }

    //close socket. so master can get another connection
    close(masterSocket);
    printf("Master socket closed..\n");

    unlink(SOCKET_NAME);
    exit(EXIT_SUCCESS);


}