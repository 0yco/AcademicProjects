/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** object.h
*/


#ifndef OBJECT_H_
    #define OBJECT_H_
    #include "animation.h"


typedef enum {BLOCK, FG, MG, BG, CHR, LIFE} ID;

typedef struct utils_s {
    sfIntRect rect;
    sfVector2f o_pos;
    ID id;
    char *path;
    sfVector2f pos;
} utils_t;

typedef struct object_s {
    sfTexture *texture;
    sfSprite *sprite;
    utils_t utils;
    animation_t animation;
} object_t;

typedef struct lnk_list_s {
    struct lnk_list_s *prev;
    struct lnk_list_s *next;
    object_t *value;
} lnk_list_t;

#endif /* OBJECT_H_ */
