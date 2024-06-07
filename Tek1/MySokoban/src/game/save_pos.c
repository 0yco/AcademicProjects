/*
** EPITECH PROJECT, 2022
** B-PSU-200-MPL-2-1-mysokoban-enzo.daumalle
** File description:
** save_pos.c
*/

#include "my_sokoban.h"

static void save_posplayer(game_t *game, int posy, int posx)
{
    if (game->p_map[posy][posx] == 'P') {
        game->px = posx;
        game->py = posy;
        POS_CHR(0, 0) = ' ';
    }
}

static void save_posbox(game_t *game, int posy, int posx, int *count)
{
    if (game->p_map[posy][posx] == 'O') {
        game->p_box[*count] = malloc(sizeof(int) * 2);
        game->p_box[*count][0] = posx;
        game->p_box[*count][1] = posy;
        *count += 1;
    }
}

void save_posentity(game_t *game)
{
    int count = 0;

    for (int i = 0; i < game->nbline; i++) {
        for (int j = 0; j < game->nbrow; j++) {
            save_posplayer(game, i, j);
            save_posbox(game, i, j, &count);
        }
    }
    game->p_box[game->nbO] = NULL;
}

void save_posmap(game_t *game)
{
    int i = 0;
    int j = 0;

    game->nbline = 0;
    game->nbrow = count_line(game, &game->nbline);
    game->p_map = malloc(sizeof(char *) * (game->nbline + 1));
    for (int tab = 0; tab < game->nbline; tab++) {
        game->p_map[tab] = malloc(sizeof(char) * game->nbrow + 1);
        for (j = 0; j < game->nbrow; j++)
            game->p_map[tab][j] = game->map[i++];
        game->p_map[tab][j] = '\0';
        i += 1;
    }
    game->p_map[game->nbline] = NULL;
}
