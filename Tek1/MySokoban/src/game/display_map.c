/*
** EPITECH PROJECT, 2021
** B-PSU-200-MPL-2-1-mysokoban-enzo.daumalle
** File description:
** display_map.c
*/

#include "my_sokoban.h"

void display_map(game_t *game)
{
    for (int i = 0; i < game->nbline; i++)
        mvprintw(i, 0, game->p_map[i]);
}
