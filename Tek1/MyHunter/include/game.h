/*
** EPITECH PROJECT, 2021
** BS My Hunter
** File description:
** game.h
*/


#ifndef GAME_H
    #define GAME_H
    #include <stdlib.h>

typedef struct game {
    sfRenderWindow *window;
    sfEvent event;
    sfTexture *texture;
    sfIntRect rect;
    sfClock *clock;
    sfVector2f size;
    sfTime time;
    float seconds;
    sfSprite *sprite;
    sfColor clear_color;
    sfMusic *music;
} game_t;

game_t *create_game(sfVideoMode mode, sfColor clear_color);

#endif /* GAME_H_ */
