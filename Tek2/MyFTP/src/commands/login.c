/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** user.c
*/

#include "myftp.h"

void user(PARAMS_CMDS)
{
    char *username = server->buffer + 5;

    if (client->username && client->password) {
        dprintf(client->sd, "500 Please logout with QUIT.\r\n");
        return;
    }
    if (!username || !strcmp(username, "\r\n") || *username == '\n') {
        dprintf(client->sd, "530 Please login with USER then PASS.\r\n");
        return;
    }

    if (strcmp(username, "\r\n") && *username != '\n' && !client->username) {
        client->username = strdup(username);
        dprintf(client->sd, "331 User name okay, need password.\r\n");
    } else if (client->username)
        dprintf(client->sd, "500 You have already entered a username.\r\n");
    else
        dprintf(client->sd, "530 Please login with USER then PASS.\r\n");
}

void pass(PARAMS_CMDS)
{
    char *password = server->buffer + 5;

    if (!client->username) {
        dprintf(client->sd, "530 Please login with USER then PASS.\r\n");
        return;
    }
    if (client->username && client->password) {
        dprintf(client->sd, "500 Please logout with QUIT.\r\n");
        return;
    }
    if (!strcmp(password, "\r\n")
        && !strcmp(client->username, "Anonymous\r\n")) {
        client->password = strdup(password);
        dprintf(client->sd, "230 User logged in, proceed.\r\n");
    } else
        dprintf(client->sd, "530 Need account for login.\r\n");
}

void cwd(PARAMS_CMDS)
{
    char *path = server->buffer + 4;

    if (!path || !strcmp(path, "\r\n") || *path == '\n') {
        dprintf(client->sd, "550 Failed to change directory.\r\n");
        return;
    }
    path[strlen(path) - 2] = '\0';
    if (chdir(path) == -1)
        dprintf(client->sd, "550 Failed to change directory.\r\n");
    else
        dprintf(client->sd, "250 Directory successfully changed.\r\n");
}

void cdup(PARAMS_CMDS)
{
    (void) server;

    if (chdir("..") == -1)
        dprintf(client->sd, "550 Failed to change directory.\r\n");
    else
        dprintf(client->sd, "200 Directory successfully back.\r\n");
}
