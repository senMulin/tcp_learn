//
// Created by mulin on 2019/8/25.
//
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

#include <pthread.h>

#include "TCPServer.h"

void* tcp_server() {

    char message[256] = "You have reached the server";

    int server_socket;
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // define the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9001);
    server_address.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr_in *) &server_address, sizeof(server_address));

    listen(server_socket, 5);

    int client_socket;
    client_socket = accept(server_socket, NULL, NULL);

    //send the message
    send(client_socket, message, sizeof(message), 0);

    shutdown(server_socket, 0);
}

void tcp_server_thread() {
    pthread_t tid;
    int ret;

    //create thread

    ret = pthread_create(&tid, NULL, &tcp_server, NULL);

    if (ret == 0) {
        printf("create tcp server thread successfully.\n");
    }
    else {
        printf("create tcp server thread failure.\n");
    }
}