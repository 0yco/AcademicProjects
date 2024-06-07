/*
** EPITECH PROJECT, 2023
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** exec_commands.c
*/

#include "myftp.h"

static const builtin_t builtins[NB_CMDS] = {
    {"USER", &user},
    {"PASS", &pass},
    {"QUIT", &quit},
    {"CWD", &cwd},
    {"CDUP", &cdup},
    {"DELE", &dele},
    {"PWD", &pwd},
    {"PASV", &pasv},
    {"PORT", &port},
    {"HELP", &help},
    {"NOOP", &noop},
    {"RETR", &retr},
    {"STOR", &stor},
    {"LIST", &list},
};

builtin_t *get_builtin(char *buffer)
{
    char *cmd = strtok(strdup(buffer), " ");

    if (cmd[strlen(cmd) - 1] == '\n')
        cmd = strtok(cmd, "\r\n");
    for (int i = 0; i < NB_CMDS; i++)
        if (!strcmp(cmd, builtins[i].cmd)) {
            free(cmd);
            return ((builtin_t *)&builtins[i]);
        }
    free(cmd);
    return NULL;
}
