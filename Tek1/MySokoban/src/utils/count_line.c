/*
** EPITECH PROJECT, 2022
** B-PSU-200-MPL-2-1-mysokoban-enzo.daumalle
** File description:
** count_line.c
*/

#include "my_sokoban.h"

int count_line(game_t *game, int *nbline)
{
    int i;

    for (i = 0; game->map[i]; i++)
        if (game->map[i] == '\n' && game->map[i + 1] != '\0')
            *nbline += 1;
    *nbline += 1;
    return ((i + 1) - (*nbline)) / (*nbline);
}
