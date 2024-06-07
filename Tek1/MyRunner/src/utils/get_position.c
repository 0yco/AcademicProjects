/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** get_position.c
*/

#include "my_runner.h"

void get_position(lnk_list_t *list, game_t *game, int id)
{
    if (id == 1) {
        list->value->utils.pos = (sfVector2f) {\
        sfSprite_getPosition(list->value->sprite).x,
        sfSprite_getPosition(list->value->sprite).y};
    } else if (id == 2) {
        game->pos_chr = (sfVector2f) {
            sfSprite_getPosition(list->value->sprite).x,
            sfSprite_getPosition(list->value->sprite).y
        };
    }
}