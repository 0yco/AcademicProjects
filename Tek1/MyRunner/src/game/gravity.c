/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** gravity.c
*/

#include "my_runner.h"

void gravity(lnk_list_t *list)
{
    sfSprite_move(list->value->sprite, list->value->animation.velocity);
    if (sfSprite_getPosition(list->value->sprite).y < 520)
        list->value->animation.velocity.y += list->value->animation.gravity;
    else if (list->value->utils.rect.left == 0
    && (list->value->animation.state == JUMP
    || list->value->animation.state == SLIDE)) {
            list->value->animation.state = WALK;
            list->value->utils.rect = (sfIntRect) {0, 0, 240, 275};
            list->value->animation.offset = (sfVector2f) {220, 0};
            list->value->animation.velocity.y = 0;
            sfMusic_stop(list->value->animation.sound);
    } else
        list->value->animation.velocity.y = 0;
}
