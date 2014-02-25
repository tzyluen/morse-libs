/**
 * Morse Code Translator
 * TCPIP
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2
 */
#include <error.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "handler.h"
#include "morse.h"


void d_print(char *fname, int line, char *message)
{
    printf("-D- %s at line: %d: %s\n", fname, (int)line, message);
}


void die_with_error(char *fname, int line, char *err_message)
{
    error(1, 0, "%s:%d:%s", fname, line, err_message);
}


void handle_tcp_client(int client_socket)
{
    char words[RCVBUFSIZE];             /* buffer for input string */
    int recv_msg_size;                  /* size of received message */
    Morse_map *mm = Morse_map_create();

    /* receive message from client */
    if ((recv_msg_size = recv(client_socket, words, RCVBUFSIZE, 0)) < 0)
        die_with_error(__FILE__, __LINE__, "recv() failed");

    char *dmsg = malloc(recv_msg_size + 10 + 2);
    words[recv_msg_size] = '\0';
    sprintf(dmsg, "strlen(%s): %d", words, recv_msg_size);
    d_print(__FILE__, __LINE__, dmsg);

    char *morses = line_to_morse(words, mm);
    d_print(__FILE__, __LINE__, morses);

    /* send received string and receive again until end of transmission */
    /*while (recv_msg_size > 0) {
        if (send(client_socket, morses, strlen(morses), 0))
            die_with_error(__FILE__, __LINE__, "send() failed");
        send(client_socket, morses, strlen(morses), 0);
        d_print(__FILE__, __LINE__, "called");

        if ((recv_msg_size = recv(client_socket, words, RCVBUFSIZE, 0)) < 0)
            die_with_error(__FILE__, __LINE__, "recv() failed");

        morses = line_to_morse(words, mm);
    }*/
    morses = line_to_morse(words, mm);
    /* send morse string to client */
    send(client_socket, morses, strlen(morses), 0);

    close(client_socket);       /* close client socket */
}
