#include <stdio.h>


#include "tcp/TCPServer.h"
#include "tcp/TCPClient.h"

int main() {
    printf("Hello, World!\n");

    printf("start tcp server. \n");
    tcp_server_thread();

    printf("start tcp client. \n");
    tcp_client_thread();

    while (1){

    }
    return 0;
}