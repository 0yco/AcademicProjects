/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** help.c
*/

#include "myftp.h"

void help(PARAMS_CMDS_UNUSED)
{
    dprintf(client->sd, "214 USER, PASS, QUIT, CWD, CDUP, DELE, PWD, PASV, ");
    dprintf(client->sd, "PORT, HELP, NOOP, RETR, STOR, LIST\r\n");
}
