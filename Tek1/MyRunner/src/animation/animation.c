/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** animate->c
*/

#include "my_runner.h"

static void animation_block(lnk_list_t *list, game_t *game)
{
    get_position(list, game, 1);
    sfSprite_move(list->value->sprite, (sfVector2f) {-6, 0});
    if (check_collision_entity(list, game)) {
        game->time = sfClock_getElapsedTime (game->clock);
        game->seconds = game->time.microseconds / 1000000.0;
        if (game->seconds > 0.3) {
            game->state = HEART;
            sfClock_restart(game->clock);
        }
    }
}

static void game_over(game_t *game)
{
    sfMusic_play(game->music_over);
    sfText_setString(game->game_over, "Game Over");
    sfText_setFont(game->game_over, game->font);
    sfText_setCharacterSize(game->game_over, 120);
    sfText_setPosition(game->game_over, (sfVector2f) {250, 200});
    sfText_setColor(game->game_over, (sfColor) {255, 255, 255, 255});
    sfText_setPosition(game->text, (sfVector2f) {480, 400});
    sfText_setCharacterSize(game->text, 90);
    game->state = GAME_OVER;
}

static void life(lnk_list_t *list, game_t *game)
{
    if (list->value->utils.rect.left == 600) {
        game->state = PAUSE;
        game_over(game);
    }
    if (game->state == HEART) {
        game->state = GAME;
        list->value->utils.rect.left += 200;
    }
}

void animation_sprite(game_t *game, lnk_list_t *list, int speed)
{
    switch (list->value->utils.id) {
        case BG: speed = 1;
            break;
        case MG: speed = 3;
            break;
        case FG: sfSprite_move(list->value->sprite, (sfVector2f) {-6, 0});
            break;
        case BLOCK: animation_block(list, game);
            break;
        case CHR: animation_character(list, game);
            break;
        case LIFE: life(list, game);
            break;
    }
    list->value->utils.rect.left += speed;
    sfSprite_setTextureRect(list->value->sprite, list->value->utils.rect);
}
