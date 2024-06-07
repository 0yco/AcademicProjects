/*
** EPITECH PROJECT, 2022
** my_sokoban
** File description:
** game.h
*/

#ifndef GAME_H_
    #define GAME_H_

    #define POS_CHR(x, y) game->p_map[game->py + y][game->px + x]

    #include <stdbool.h>

typedef struct game_s {
    int px;
    int py;
    char *path_map;
    char *map;
    char **p_map;
    int **p_box;
    int nbrow;
    int nbline;
    int nbO;
    int lose;
    int state;
    bool onbox;
    bool pushX;
} game_t;

#endif /* GAME_H_ */
