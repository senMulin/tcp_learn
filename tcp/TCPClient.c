//
// Created by mulin on 2019/8/25.
//
#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>
#include <arpa/inet.h>

#include <pthread.h>

#include "TCPClient.h"

void* tcp_client() {

    //create a socket
    int network_socket;
    network_socket = socket(AF_INET, SOCK_STREAM, 0);

    //specify an address for the socket
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(9001);
    inet_aton("127.0.0.1", &server_addr.sin_addr.s_addr);

    int status = connect(network_socket, (struct sockaddr *) &server_addr, sizeof(server_addr));

    if (status == -1) {
        printf("There was an error making a connection to the remote socket\n\n");
    }

    char response[256];

    recv(network_socket, &response, sizeof(response), 0);

    printf("The Server send data: %s\n",response);

    shutdown(network_socket, 0);

    return 0;
}

void tcp_client_thread() {
    pthread_t tid;
    int ret;

    //create thread

    ret = pthread_create(&tid, NULL, &tcp_client, NULL);

    if (ret == 0) {
        printf("create tcp client thread successfully.\n");
    }
    else {
        printf("create tcp client thread failure.\n");
    }
}