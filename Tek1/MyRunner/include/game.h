/*
** EPITECH PROJECT, 2021
** BS My Hunter
** File description:
** game.h
*/


#ifndef GAME_H
    #define GAME_H
    #define MENU        0
    #define START       1
    #define GAME        2
    #define PAUSE       3
    #define GAME_OVER   4
    #define HEART       5

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfColor clear_color;
    sfMusic *music;
    sfMusic *music_over;
    sfText *text;
    sfText *game_over;
    sfFont *font;
    int score;
    sfVector2f pos_chr;
    int state;
    sfClock *clock;
    sfTime time;
    float seconds;
} game_t;

game_t *create_game(sfVideoMode mode, sfColor clear_color);

#endif /* GAME_H_ */
