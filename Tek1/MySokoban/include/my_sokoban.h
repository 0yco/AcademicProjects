/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** my_sokoban.h
*/

#ifndef __MY_SOKOBAN_H__
    #define __MY_SOKOBAN_H__
    #define UNUSED __attribute__ ((unused))
    #define KEY_SPACE   32
    #define KEY_ESCAPE  27

    #include "game.h"
    #include <stdbool.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <ncurses.h>
    #include <curses.h>
    #include <time.h>

int my_strlen(char const *str);
int my_putstr(char const *str);
bool my_str_isequal(char *from, char *to);
int count_line(game_t *game, int *nbline);
int ch_isnequal(char ch, char *container);
void check_game(game_t *game);
void display_map(game_t *game);
void state_game(game_t *game);
void save_posentity(game_t *game);
void save_posmap(game_t *game);
game_t *init_game(char *path_map);
void init(game_t **game, char *path_map);
void event(game_t *game);
void mvplayer(game_t *game, int x, int y);
void exit_sokoban(int ext);

#endif /* __MY_SOKOBAN_H__ */
