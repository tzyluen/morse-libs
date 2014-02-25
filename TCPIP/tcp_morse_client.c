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
    int sock;
    struct sockaddr_in morse_server_addr;
    unsigned short morse_server_port;
    char *server_ip;
    char *words;
    char morse_buffer[RCVBUFSIZE];
    unsigned int words_len;
    int bytes_rcvd, total_bytes_rcvd;

    if ((argc < 3) || (argc > 4)) {
        fprintf(stderr, "Usage: %s <server ip> \"<words>\" [port]\n", argv[0]);
        exit(1);
    }

    server_ip = argv[1];
    words = argv[2];

    if (argc == 4)
        morse_server_port = atoi(argv[3]);
    else
        morse_server_port = 9999;

    /* create the stream socket using TCP */
    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0)
        die_with_error(__FILE__, __LINE__, "socket() failed");

    /* construct the server address structure */
    memset(&morse_server_addr, 0, sizeof(morse_server_addr));   /* reset structure */
    morse_server_addr.sin_family        = AF_INET;              /* internet address family */
    morse_server_addr.sin_addr.s_addr   = inet_addr(server_ip); /* server ip address */
    morse_server_addr.sin_port          = htons(morse_server_port); /* server port */

    /* establish connection to morse server */
    if (connect(sock, (struct sockaddr*) &morse_server_addr, sizeof(morse_server_addr)) < 0)
        die_with_error(__FILE__, __LINE__, "connect() failed");

    words_len = strlen(words);

    /* send the string to the server */
    if (send(sock, words, words_len, 0) != words_len)
        die_with_error(__FILE__, __LINE__, "send() sent a different number of bytes than expected");

    if ((bytes_rcvd = recv(sock, morse_buffer, RCVBUFSIZE, 0)) < 0)
        die_with_error(__FILE__, __LINE__, "recv() failed 0");

    char *morses = malloc(bytes_rcvd + 1);
    memcpy(morses, morse_buffer, bytes_rcvd);
    morses[bytes_rcvd] = '\0';
    total_bytes_rcvd = bytes_rcvd;
    //d_print(__FILE__, __LINE__, morses);

    while ((bytes_rcvd = recv(sock, morse_buffer, RCVBUFSIZE, 0))) {
        total_bytes_rcvd += bytes_rcvd;
        char *_buf = malloc(total_bytes_rcvd + 1);
        morse_buffer[bytes_rcvd] = '\0';
        sprintf(_buf, "%s%s", morses, morse_buffer);
        //d_print(__FILE__, __LINE__, _buf);
        morses = _buf;
    }

    printf("%s\n", morses);

    close(sock);
    exit(0);
}
