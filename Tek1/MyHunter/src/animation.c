/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** animation.c
*/

#include "../include/my_hunter.h"

static void change_picture_entity(entity_t *entity)
{
    if (entity->animation.rect.left == 1000)
        entity->animation.rect.left = 0;
    else
        entity->animation.rect.left += 200;
}

void animate_entity(entity_t *entity)
{
    if (entity->animation.rect.width != 200)
        animate_death_blessing(entity);
    else {
        entity->animation.time = sfClock_getElapsedTime
        (entity->animation.clock);
        entity->animation.seconds =
        entity->animation.time.microseconds / 1000000.0;
        if (entity->animation.seconds > 0.10) {
            change_picture_entity(entity);
            sfSprite_setTextureRect(entity->sprite, entity->animation.rect);
            sfClock_restart(entity->animation.clock);
        }
    }
    sfSprite_move(entity->sprite, entity->animation.offset);
}

void animate_mouse(entity_t *entity, game_t *window)
{
    sfVector2f pos_sprite_mouse = {sfMouse_getPositionRenderWindow
    (window->window).x, sfMouse_getPositionRenderWindow(window->window).y};

    sfSprite_setPosition(entity->sprite, pos_sprite_mouse);
}

static void change_picture_death_blessing(entity_t *entity)
{
    if (entity->animation.rect.top != (entity->size.y / 4) * 3)
        entity->animation.rect.top += entity->size.y / 4;
    entity->animation.rect.left = 0;
}

void animate_death_blessing(entity_t *entity)
{
    entity->animation.time = sfClock_getElapsedTime
    (entity->animation.clock_db);
    entity->animation.seconds = entity->animation.time.microseconds / 300000.0;
    if (entity->animation.seconds > 0.10) {
        if (entity->animation.rect.left == (entity->size.x / 4) * 3) {
            change_picture_death_blessing(entity);
        } else
            entity->animation.rect.left += entity->size.x / 4;
        sfSprite_setTextureRect(entity->sprite, entity->animation.rect);
        sfClock_restart(entity->animation.clock_db);
    }
    if (entity->animation.rect.top == (entity->size.y / 4) * 3
    && entity->animation.rect.left == (entity->size.x / 4) * 3) {
        sfSprite_setPosition(entity->sprite,
        (sfVector2f) {-150, rand() % 500});
        entity_isdead_or_save(entity);
        entity->size = (sfVector2f) {200, 100};
        sfMusic_stop(entity->animation.sound_bless);
        sfMusic_stop(entity->animation.sound_death);
    }
}
