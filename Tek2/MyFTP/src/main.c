/*
** EPITECH PROJECT, 2022
** B-NWP-400-MPL-4-1-myftp-enzo.daumalle
** File description:
** main.c
*/

#include "myftp.h"

void help_usage(void)
{
    printf("USAGE: ./myftp port path\n");
    printf("\tport is the port number on which the server socket listens.\n");
    printf("\tpath is the path to the home");
    printf(" directory for the Anonymous user.\n");
}

int main(int ac, char **av)
{
    if (ac == 2 && !strcmp(av[1], "-help")) {
        help_usage();
        return 0;
    }
    if (ac != 3) {
        printf("Invalid arguments.\n");
        return 84;
    }
    int port = atoi(av[1]);
    if (port == 0) {
        printf("Invalid port number.\n");
        return 84;
    }
    if (chdir(av[2]) == -1) {
        printf("Invalid path.\n");
        return 84;
    }
    server(port, av[2]);
    return 0;
}
