/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** destroy.c
*/

#include "my_runner.h"

void destroy_object(__attribute__((unused)) game_t *game, lnk_list_t *list)
{
    sfSprite_destroy(list->value->sprite);
    sfTexture_destroy(list->value->texture);
    if (list->value->utils.id == CHR) {
        sfMusic_destroy(list->value->animation.sound);
        sfClock_destroy(list->value->animation.clock);
    }
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    sfMusic_destroy(game->music);
    sfMusic_destroy(game->music_over);
    sfText_destroy(game->text);
    sfFont_destroy(game->font);
    free(game);
}