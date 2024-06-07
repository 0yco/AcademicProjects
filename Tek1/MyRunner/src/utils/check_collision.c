/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** check_collision.c
*/

#include "my_runner.h"

sfBool check_collision_entity(lnk_list_t *list, game_t *game)
{
    if ((game->pos_chr.x + 240 >= list->value->utils.pos.x &&
    game->pos_chr.x + 240 <= list->value->utils.pos.x +
    list->value->utils.rect.width)
    && (game->pos_chr.y >= list->value->utils.pos.y -
    list->value->utils.rect.height * 2
    && game->pos_chr.y <= list->value->utils.pos.y))
        return sfTrue;
    return sfFalse;
}
