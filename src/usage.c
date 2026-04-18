/*
** EPITECH PROJECT, 2026
** G-NWP-400-COT-4-1-myftp-95
** File description:
** usage
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "../include/my.h"

int usage(void)
{
        printf("USAGE: ./myftp port path\n");
        printf(" port is the port number on which");
        printf(" the server socket listens\n");
        printf(" path is the path to the home");
        printf(" directory for the ANonymous user\n");
    return 0;
}
