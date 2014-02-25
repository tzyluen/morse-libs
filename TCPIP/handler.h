/**
 * Morse Code Translator
 * TCPIP
 * Copyright (C) 2013 Ng Tzy Luen. All Rights Reserved.
 *
 * Tested under GNU C gcc 4.7.2
 */
#ifndef HANDLER_H
#define HANDLER_H

#define RCVBUFSIZE 32       /* size of receive buffer */
#define MAX_PENDING 5       /* maximum outstanding connection requests */

void d_print(char *fname, int line, char *message);
void die_with_error(char *fname, int line, char *err_message);
void handle_tcp_client(int client_socket);

#endif
