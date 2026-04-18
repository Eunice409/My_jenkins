/*
** EPITECH PROJECT, 2026
** G-NWP-400-COT-4-1-myftp-95
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define MAX_CLIENTS 150

extern int pasv_fd;
extern int data_fd;

int usage(void);
void passive_mode(int client_fd);
int actif_mode(int client_fd, char *arg);
void list(int client_fd);
void cwd_cmd(int client_fd, char *path);
void cdup_cmd(int client_fd);
int create_server_socket(int port);
void command(char *buf, int client_fd);

#endif
