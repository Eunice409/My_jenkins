/*
** EPITECH PROJECT, 2025
** G-NWP-400-COT-4-1-myftp-95 (3)
** File description:
** cdup.c
*/

#include "../include/my.h"

void cdup_cmd(int client_fd)
{
    if (chdir("..") == -1) {
        dprintf(client_fd, "550 Failed\r\n");
        return;
    }
    dprintf(client_fd, "200 Directory changed\r\n");
}
