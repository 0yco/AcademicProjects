/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** file_action.c
*/

#include "myftp.h"

void stor(PARAMS_CMDS_UNUSED)
{
    if (is_data_connection(client) == false)
        return;
    dprintf(client->sd, "150 Command not implemented.\r\n");
}

void retr(PARAMS_CMDS)
{
    (void) server;

    if (is_data_connection(client) == false)
        return;
    dprintf(client->sd, "150 Command not implemented.\r\n");
}

void list(PARAMS_CMDS)
{
    (void) server;

    if (is_data_connection(client) == false)
        return;
    dprintf(client->sd, "150 File status okay.\r\n");
}

void dele(PARAMS_CMDS)
{
    char *path = strtok(server->buffer + 5, "\r\n");

    if (remove(path) == -1) {
        dprintf(client->sd, "550 Failed to delete file.\r\n");
        return;
    }
    dprintf(client->sd, "250 File successfully deleted.\r\n");
}

void pwd(PARAMS_CMDS)
{
    (void) server;
    char *path = getcwd(NULL, 0);

    if (!path) {
        dprintf(client->sd, "550 Failed to get current directory.\r\n");
        free(path);
        return;
    }
    if (is_no_params(server->buffer + 3, client->sd) == false) {
        free(path);
        return;
    }
    dprintf(client->sd, "257 %s\r\n", path);
    free(path);
}
