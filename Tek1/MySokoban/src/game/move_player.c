/*
** EPITECH PROJECT, 2022
** B-PSU-200-MPL-2-1-mysokoban-enzo.daumalle
** File description:
** move_player.c
*/

#include "my_sokoban.h"

static void check_blocked(game_t *game, int x, int y)
{
    int nb = 0;

    if (POS_CHR(x * 2 + 1, y * 2) == '#' && POS_CHR(x * 2, y * 2 + 1) == '#')
        nb += 1;
    if (POS_CHR(x * 2 - 1, y * 2) == '#' && POS_CHR(x * 2, y * 2 + 1) == '#')
        nb += 1;
    if (POS_CHR(x * 2 + 1, y * 2) == '#' && POS_CHR(x * 2, y * 2 - 1) == '#')
        nb += 1;
    if (POS_CHR(x * 2 - 1, y * 2) == '#' && POS_CHR(x * 2, y * 2 - 1) == '#')
        nb += 1;
    if (nb != 0)
        game->lose -= 1;
}

static int canmove(game_t *game, int x, int y)
{
    if (POS_CHR(x, y) == '#')
        return 0;
    if (game->pushX) {
        if (POS_CHR((x * 2), (y * 2)) == 'X')
            return 0;
        if (POS_CHR((x * 2), (y * 2)) == '#')
            return 0;
        if (POS_CHR((x * 2), (y * 2)) == 'O')
            game->nbO -= 1;
        check_blocked(game, x, y);
    }
    return 1;
}

static void interaction_entity(game_t *game, int x, int y)
{
    if (game->onbox) {
        mvaddch(game->py, game->px, 'O');
        POS_CHR(0, 0) = 'O';
        game->onbox = false;
    } else
        mvaddch(game->py, game->px, ' ');
    for (int i = 0; game->p_box[i]; i++)
        if (game->p_box[i][0] == (game->px + x) &&
        game->p_box[i][1] == (game->py + y))
            game->onbox = true;
    if (game->pushX) {
        POS_CHR(x, y) = ' ';
        POS_CHR((x * 2), (y * 2)) = 'X';
    }
}

void mvplayer(game_t *game, int x, int y)
{
    if (POS_CHR(x, y) == 'X')
        game->pushX = true;
    POS_CHR(0, 0) = ' ';
    if (canmove(game, x, y)) {
        interaction_entity(game, x, y);
        game->px += x;
        game->py += y;
    }
    game->pushX = false;
    POS_CHR(0, 0) = 'P';
    display_map(game);
    refresh();
    state_game(game);
}
