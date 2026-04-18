/*
** EPITECH PROJECT, 2026
** G-NWP-400-COT-4-1-myftp-95
** File description:
** commande
*/

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include "../include/my.h"

void command(char *buf, int client_fd)
{
    if (strncmp(buf, "USER", 4) == 0) {
        dprintf (client_fd, "331 User okay.\r\n");
        return;
    }
    if (strncmp(buf, "PASS", 4) == 0) {
        dprintf (client_fd, "230 User logged in.\r\n");
        return;
    }
    if (strncmp(buf, "PASV", 4) == 0) {
        passive_mode(client_fd);
        return;
    }
    if (strncmp(buf, "PORT", 4) == 0) {
        actif_mode (client_fd, buf + 5);
        return;
    }
    if (strncmp(buf, "LIST", 4) == 0) {
        list(client_fd);
        return;
    }
    if (strncmp(buf, "PWD", 3) == 0) {
        dprintf (client_fd, "257 \" / \" is current directory.\r\n");
        return;
    }
    if (strncmp(buf, "CWD", 3) == 0) {
        cwd_cmd(client_fd, buf + 4);
        return;
    }
    if (strncmp(buf, "CDUP", 4) == 0) {
        cdup_cmd(client_fd);
        return;
    }
    if (strncmp(buf, "QUIT", 4) == 0) {
        dprintf (client_fd, "221 Service closing control connection.\r\n");
        close(client_fd);
        return;
    }
    dprintf (client_fd, "500 Syntax error, command unrecognized.\r\n");
}
