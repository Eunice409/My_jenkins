/*
** EPITECH PROJECT, 2025
** G-NWP-400-COT-4-1-myftp-95 (3)
** File description:
** cwd.c
*/

#include "../include/my.h"

void cwd_cmd(int client_fd, char *path)
{
    if (path == NULL) {
        dprintf(client_fd, "501 Syntax error\r\n");
        return;
    }
    if (chdir(path) == -1) {
        dprintf(client_fd, "550 Failed to change directory\r\n");
        return;
    }
    dprintf(client_fd, "250 Directory changed\r\n");
}
