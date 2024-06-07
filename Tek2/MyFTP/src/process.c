/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** process.c
*/

#include "myftp.h"

static void unexpected_client(int client_fd, int valread)
{
    if (valread == 0) {
        printf("Client disconnected");
        close(client_fd);
        return;
    } else if (valread == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }
}

static client_t *accept_connection(server_t *server)
{
    client_t *client = malloc(sizeof(client_t));

    client->address_len = sizeof(client->address);
    client->username = NULL;
    client->password = NULL;
    client->mode = NONE;
    if ((client->sd = accept(server->fd,
    (struct sockaddr*)&client->address, &client->address_len)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    return client;
}

static void wait_buffer(client_t *client, server_t *server, int *valread)
{
    if (strcmp(server->buffer + strlen(server->buffer) - 2, "\r\n")) {
        while (strcmp(server->buffer + strlen(server->buffer) - 2, "\r\n"))
            *valread = read(client->sd, server->buffer, 4096);
    }
}

static void process_client(client_t *client, server_t *server)
{
    int valread = 0;

    memset(server->buffer, 0, 4096);
    while ((valread = read(client->sd, server->buffer, 4096)) > 0) {
        unexpected_client(client->sd, valread);
        wait_buffer(client, server, &valread);
        if (buffer_is_invalid(server->buffer)) {
            memset(server->buffer, 0, 4096);
            dprintf(client->sd, "500 Invalid syntax.\r\n");
            continue;
        }
        builtin_t *cmd = get_builtin(server->buffer);
        printf("Client: %s", server->buffer);
        if (cmd && is_authentified(client, cmd->cmd))
            cmd->fptr(client, server);
        if (!cmd)
            dprintf(client->sd, "500 Unknown command.\r\n");
        memset(server->buffer, 0, 4096);
    }
}

void process_server(server_t *server)
{
    client_t *client = accept_connection(server);
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (pid == 0) {
        dprintf(client->sd, "220 Service ready for new user.\r\n");
        if (client == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        process_client(client, server);
        close(client->sd);
        free(client);
        exit(EXIT_SUCCESS);
    } else
        close(client->sd);
}
