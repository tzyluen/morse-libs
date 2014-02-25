/**
 * Morse Code Translator
 * TCPIP
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2
 */
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "handler.h"


int main(int argc, char **argv)
{
    int server_socket;      /* socket descriptor for server */
    int client_socket;      /* socket descriptor for client */
    struct sockaddr_in morse_server_addr;   /* local address */
    struct sockaddr_in morse_client_addr;   /* client address */
    unsigned short morse_server_port;       /* server port */
    unsigned int client_length;             /* length of client address data structure */

    if (argc != 2) {
        fprintf(stderr, "Usage:  %s <server port>\n", argv[0]);
        exit(1);
    }

    morse_server_port = atoi(argv[1]);

    /* create socket for incoming connections */
    if ((server_socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        die_with_error(__FILE__, __LINE__, "socket() failed");

    /* construct local address structure */
    memset(&morse_server_addr, 0, sizeof(morse_server_addr));   /* reset structure */
    morse_server_addr.sin_family = AF_INET;                     /* internet address family */
    morse_server_addr.sin_addr.s_addr = htonl(INADDR_ANY);      /* any incoming interface */
    morse_server_addr.sin_port = htons(morse_server_port);      /* local port */

    /* bind to the local address */
    if (bind(server_socket, (struct sockaddr*) &morse_server_addr, sizeof(morse_server_addr)) < 0)
        die_with_error(__FILE__, __LINE__, "bind() failed");

    /* mark the socket so it will listen for incoming connections */
    if (listen(server_socket, MAX_PENDING) < 0)
        die_with_error(__FILE__, __LINE__, "listen() failed");

    for (;;) {
        /* set the size of the in-out parameter */
        client_length = sizeof(morse_server_addr);

        /* wait for a client to connect */
        if ((client_socket = accept(server_socket, (struct sockaddr*) &morse_client_addr, &client_length)) < 0)
            die_with_error(__FILE__, __LINE__, "accept() failed");

        /* client_socket is connected to a client */
        printf("Handling client %s\n", inet_ntoa(morse_client_addr.sin_addr));

        handle_tcp_client(client_socket);
    }
}
