/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** server.c
*/

#include "myftp.h"

static server_t *create_socket(int port, char *path)
{
    server_t *server = malloc(sizeof(server_t));
    int opt = 1;

    if ((server->fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    if (setsockopt(server->fd, SOL_SOCKET, SO_REUSEADDR |
        SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    server->address.sin_family = AF_INET;
    server->address.sin_port = htons(port);
    server->address.sin_addr.s_addr = INADDR_ANY;
    server->path = path;
    server->buffer = malloc(sizeof(char) * 4096);
    return server;
}

static void bind_socket(server_t *server)
{
    int fd = bind(server->fd,
    (struct sockaddr*)&server->address, sizeof(server->address));

    if (fd < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
}

static void listen_socket(server_t *server)
{
    int state = listen(server->fd, 3);

    if (state < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
}

void server(int port, char *path)
{
    server_t *server = create_socket(port, path);

    bind_socket(server);
    listen_socket(server);
    while (1) {
        process_server(server);
    }
}
