/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** animation_character.c
*/

#include "my_runner.h"

static void animation_slide(lnk_list_t *list)
{
    sfClock_restart(list->value->animation.clock);
    list->value->utils.rect = (sfIntRect) {440, 0, 220, 270};
    sfSprite_setRotation(list->value->sprite, -75);
    sfSprite_setPosition(list->value->sprite,
    (sfVector2f) {list->value->utils.o_pos.x, 700});
    sfSprite_setTextureRect(list->value->sprite, list->value->utils.rect);
}

static void state(lnk_list_t *list)
{
    switch (list->value->animation.state) {
        case JUMP: list->value->animation.velocity.y = -15;
            sfMusic_play(list->value->animation.sound);
            list->value->utils.rect = (sfIntRect) {0, 275, 220, 270};
            sfClock_restart(list->value->animation.clock);
            list->value->animation.offset = (sfVector2f) {232, 270};
            list->value->animation.isstate = 0;
            break;
        case SLIDE: animation_slide(list);
            break;
    }
    list->value->animation.isstate = 0;
}

static void animate_character(lnk_list_t *list)
{
    if (list->value->utils.rect.left == list->value->animation.offset.x * 4) {
        list->value->utils.rect.left = 0;
    } else
        list->value->utils.rect.left += list->value->animation.offset.x;
}

void animation_character(lnk_list_t *list, game_t *game)
{
    gravity(list);
    get_position(list, game, 2);
    if (list->value->animation.isstate == 1)
        state(list);
    list->value->animation.time = sfClock_getElapsedTime
    (list->value->animation.clock);
    list->value->animation.seconds =
    list->value->animation.time.microseconds / 800000.0;
    if (list->value->animation.seconds > 0.1 &&
    list->value->animation.state != SLIDE) {
        animate_character(list);
        sfClock_restart(list->value->animation.clock);
    } else if (list->value->animation.seconds > 0.8) {
        list->value->utils.rect.left = 0;
        sfSprite_setRotation(list->value->sprite, 0);
        sfClock_restart(list->value->animation.clock);
        sfSprite_setPosition(list->value->sprite,
        (sfVector2f) {list->value->utils.o_pos.x, 520});
    }
}
