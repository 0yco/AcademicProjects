/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** noop.c
*/

#include "myftp.h"

void noop(PARAMS_CMDS_UNUSED)
{
    if (is_no_params(server->buffer + 4, client->sd) == false)
        return;
    dprintf(client->sd, "200 NOOP command successful.\r\n");
}
