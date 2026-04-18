/*
** EPITECH PROJECT, 2026
** G-NWP-400-COT-4-1-myftp-95
** File description:
** main
*/

#include "../include/my.h"
#include <string.h>

int pasv_fd = -1;
int data_fd = -1;

void client(int client_fd)
{
    int bytes;

    while (1) {
        char buffer[1024] = {0};
        bytes = read(client_fd, buffer, 1023);
        if (bytes <= 0)
            break;
        if (buffer[0] == '\n' || buffer[0] == '\r')
            continue;
        printf("command received: %s", buffer);
        command(buffer, client_fd);
    }
}

void accept_client(int server_fd)
{
    int client_fd;
    while (1) {
        client_fd = accept(server_fd, NULL, NULL);
        if (client_fd < 0)
            continue;
        printf("Client connected!\n");
        dprintf(client_fd, "220 Service ready\r\n");
        client(client_fd);
        close(client_fd);
    }
}

int main(int ac, char **av)
{
    int port;
    int server_fd;

    if (ac < 2) {
        usage();
        return 84;
    }
    if (ac == 2 && strcmp(av[1], "--help") == 0) {
        usage();
        return 0;
    }
    port = atoi(av[1]);
    server_fd = create_server_socket(port);
    printf("Server listening on port %d...\n", port);
    accept_client(server_fd);
    close(server_fd);
    return 0;
}

