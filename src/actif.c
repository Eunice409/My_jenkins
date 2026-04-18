/*
** EPITECH PROJECT, 2026
** G-NWP-400-COT-4-1-myftp-95
** File description:
** actif
*/

#include "../include/my.h"

extern int data_fd;

int actif_mode(int client_fd, char *arg)
{
    int h1,h2,h3,h4,p1,p2;
    int port;
    char ip[64];
    struct sockaddr_in addr;

    if (sscanf(arg, "%d,%d,%d,%d,%d,%d",
        &h1,&h2,&h3,&h4,&p1,&p2) != 6) {
        dprintf(client_fd, "501 Syntax error\r\n");
        return -1;
    }

    sprintf(ip,"%d.%d.%d.%d",h1,h2,h3,h4);
    port = p1 * 256 + p2;
    data_fd = socket(AF_INET, SOCK_STREAM, 0);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(ip);
    if (connect(data_fd,(struct sockaddr*)&addr,sizeof(addr)) < 0) {
        dprintf(client_fd,"425 Can't connect\r\n");
        return -1;
    }
    dprintf(client_fd,"200 PORT command successful\r\n");
    return data_fd;
}
