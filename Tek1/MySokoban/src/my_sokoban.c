/*
** EPITECH PROJECT, 2022
** B-PSU-200-MPL-2-1-bsmysokoban-enzo.daumalle
** File description:
** sokoban.c
*/

#include "my_sokoban.h"

static void help(char *argv)
{
    if (my_str_isequal(argv, "-h")) {
        my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     ");
        my_putstr("map file representing the warehouse map, ");
        my_putstr("containing '#' for walls, 'P' for the player, ");
        my_putstr("'X' for boxes and 'O' for storage locations.\n");
        exit(0);
    }
}

int main(int argc, char **argv)
{
    game_t *game;

    if (argc != 2)
        return 84;
    help(argv[1]);
    init(&game, argv[1]);
    while (1)
        event(game);
    exit_sokoban(0);
    return 0;
}
