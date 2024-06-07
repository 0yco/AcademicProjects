/*
** EPITECH PROJECT, 2022
** B-PSU-200-MPL-2-1-mysokoban-enzo.daumalle
** File description:
** event.c
*/

#include "my_sokoban.h"

static void restart_sokoban(game_t *game)
{
    clear();
    game->onbox = false;
    game->pushX = false;
    game->nbO = 0;
    check_game(game);
    game->lose = game->nbO;
    save_posmap(game);
    save_posentity(game);
    display_map(game);
    mvaddch(game->py, game->px, 'P');
}

static void onresize_win(game_t *game)
{
    clear();
    if (LINES <= game->nbline || COLS <= game->nbrow)
        mvprintw(LINES / 2, COLS / 2 - 14, "The window are too short...");
    else {
        display_map(game);
        mvaddch(game->py, game->px, 'P');
    }
}

void state_game(game_t *game)
{
    if (game->pushX && game->onbox)
        game->nbO += 1;
    if (game->nbO == 0) {
        clear();
        display_map(game);
        usleep(100000);
        refresh();
        endwin();
        curs_set(0);
        exit(0);
    } else if (game->lose == 0) {
        clear();
        display_map(game);
        usleep(100000);
        refresh();
        endwin();
        curs_set(1);
        exit(1);
    }
}

void exit_sokoban(int state)
{
    clear();
    refresh();
    endwin();
    curs_set(1);
    exit(state);
}

void event(game_t *game)
{
    int ch = getch();

    switch (ch) {
        case KEY_RIGHT: mvplayer(game, 1, 0);
            break;
        case KEY_LEFT: mvplayer(game, -1, 0);
            break;
        case KEY_UP: mvplayer(game, 0, -1);
            break;
        case KEY_DOWN: mvplayer(game, 0, 1);
            break;
        case KEY_SPACE: restart_sokoban(game);
            break;
        case KEY_RESIZE: onresize_win(game);
            break;
        case KEY_ESCAPE: exit_sokoban(0);
    }
}
