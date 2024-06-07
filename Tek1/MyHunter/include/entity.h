/*
** EPITECH PROJECT, 2021
** BS My Hunter
** File description:
** entity.h
*/


#ifndef ENTITY_H_
    #define ENTITY_H_
    #include <stdlib.h>
    #include "animation.h"

typedef struct entity {
    sfTexture *texture;
    sfTexture *texture_white;
    sfTexture *texture_death;
    sfTexture *texture_bless;
    sfSprite *sprite;
    sfVector2f size;
    sfVector2f pos;
    animation_t animation;
} entity_t;

entity_t *create_entity(sfIntRect rect, \
sfVector2f pos, char *img, game_t *game);

#endif /* ENTITY_H_ */
