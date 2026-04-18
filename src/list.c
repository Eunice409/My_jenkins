/*
** EPITECH PROJECT, 2026
** G-NWP-400-COT-4-1-myftp-95
** File description:
** list
*/

#include <dirent.h>
#include "../include/my.h"

extern int pasv_fd;
extern int data_fd;

void list(int client_fd)
{
    DIR *dir;
    struct dirent *entry;

    if (pasv_fd == -1 && data_fd == -1) {
        dprintf(client_fd, "425 Use PASV or PORT first\r\n");
        return;
    }
    dprintf(client_fd, "150 Opening data connection\r\n");
    if (pasv_fd != -1)
        data_fd = accept(pasv_fd, NULL, NULL);
    dir = opendir(".");
    while ((entry = readdir(dir)) != NULL)
        dprintf(data_fd, "%s\r\n", entry->d_name);
    closedir(dir);
    close(data_fd);
    if (pasv_fd != -1)
        close(pasv_fd);
    pasv_fd = -1;
    data_fd = -1;
    dprintf(client_fd, "226 Transfer complete\r\n");
}
