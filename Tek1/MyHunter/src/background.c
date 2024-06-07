/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** background.c
*/

#include "../include/my_hunter.h"

static void change_background(game_t *game)
{
    if (game->rect.top == 0)
        game->rect.top += game->size.y / 7;
    game->rect.left = 0;
}

void entity_left_background(entity_t *entity)
{
    if (sfSprite_getPosition(entity->sprite).x >= 1860) {
        sfSprite_setPosition(entity->sprite, (sfVector2f)
        {-150, rand() % 500});
    }
    if (sfSprite_getPosition(entity->sprite).y >= 1140)
        sfSprite_setPosition(entity->sprite, (sfVector2f)
        {sfSprite_getPosition(entity->sprite).x,
        sfSprite_getPosition(entity->sprite).y - 1240});
    else if (sfSprite_getPosition(entity->sprite).y <= -110)
        sfSprite_setPosition(entity->sprite, (sfVector2f)
        {sfSprite_getPosition(entity->sprite).x,
        sfSprite_getPosition(entity->sprite).y + 1100});
}

void animate_background(game_t *game)
{
    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 800000.0;
    if (game->seconds > 0.10) {
        if (game->rect.left == (game->size.x / 7) * 6) {
            change_background(game);
        } else
            game->rect.left += 1200;
        sfSprite_setTextureRect(game->sprite, game->rect);
        sfClock_restart(game->clock);
    }
}
