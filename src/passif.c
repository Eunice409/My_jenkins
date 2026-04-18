/*
** EPITECH PROJECT, 2026
** G-NWP-400-COT-4-1-myftp-95
** File description:
** passive
*/

#include "../include/my.h"

extern int pasv_fd;

void passive_mode(int client_fd)
{
    int p1;
    int p2;
    int port;
    struct sockaddr_in addr;
    socklen_t len = sizeof(addr);

    pasv_fd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = 0;
    bind(pasv_fd, (struct sockaddr *)&addr, sizeof(addr));
    listen(pasv_fd, 1);
    getsockname(pasv_fd, (struct sockaddr *)&addr, &len);
    port = ntohs(addr.sin_port);
    p1 = port / 256;
    p2 = port % 256;
    dprintf(client_fd, "227 Entering Passive Mode (127,0,0,1,%d,%d)\r\n", p1, p2);
}