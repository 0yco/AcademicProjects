/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** checker.c
*/

#include "myftp.h"

bool buffer_is_invalid(char *buffer)
{
    for (int i = 0; buffer[i]; i++)
        if (buffer[i] != ' ' && buffer[i] != '\r' && buffer[i] != '\n')
            return false;
    return true;
}

bool is_no_params(char *buffer, int sd)
{
    if (strcmp(buffer, "\r\n")) {
        dprintf(sd, "500 Syntax error, there is no parameters.\r\n");
        return false;
    }
    return true;
}

bool is_data_connection(client_t *client)
{
    if (client->mode == NONE) {
        dprintf(client->sd, "425 Use PORT or PASV first.\r\n");
        return false;
    }
    return true;
}

bool is_authentified(client_t *client, char *cmd)
{
    if (!strcmp(cmd, "USER") || !strcmp(cmd, "PASS") ||
        !strcmp(cmd, "QUIT") || !strcmp(cmd, "HELP"))
        return true;
    if (!client->username || !client->password) {
        dprintf(client->sd, "530 Please login with USER then PASS.\r\n");
        return false;
    }
    return true;
}
