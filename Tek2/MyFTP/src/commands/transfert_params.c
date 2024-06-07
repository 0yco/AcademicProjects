/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** logout.c
*/

#include "myftp.h"

void port(PARAMS_CMDS)
{
    int port = 0;

    server->buffer = strtok(server->buffer + 5, "\r\n");
    if (!server->buffer) {
        dprintf(client->sd, "530 Invalid port.\r\n");
        return;
    }
    port = atoi(server->buffer);
    if (port < 0 || port > 65535
        || (port == 0 && strcmp(server->buffer, "0"))) {
        dprintf(client->sd, "530 Invalid port.\r\n");
        return;
    }
    if (client->mode != NONE) {
        dprintf(client->sd, "425 Can't open data connection.\r\n");
        return;
    }
    client->mode = ACTIVE;
    dprintf(client->sd, "200 Command not implemented.\r\n");
}

void pasv(PARAMS_CMDS)
{
    (void) server;

    if (client->mode != NONE) {
        dprintf(client->sd, "425 Can't open data connection.\r\n");
        return;
    }
    client->mode = PASSIVE;
    dprintf(client->sd, "227 Command not implemented.\r\n");
}
