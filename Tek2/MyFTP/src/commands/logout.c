/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** logout.c
*/

#include "myftp.h"

void quit(PARAMS_CMDS)
{
    if (is_no_params(server->buffer + 4, client->sd) == false)
        return;
    dprintf(client->sd, "221 Disconnection.\r\n");
    client->username = NULL;
    client->password = NULL;
    close(client->sd);
    free(server->buffer);
    free(server);
    free(client);
    exit(EXIT_SUCCESS);
    client->sd = -1;
}
