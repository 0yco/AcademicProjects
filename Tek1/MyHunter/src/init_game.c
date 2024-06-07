/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** init.c
*/

#include "../include/my_hunter.h"

static void create_music(game_t *game)
{
    game->music = sfMusic_createFromFile("sounds/Music_ninja.ogg");
    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_setVolume(game->music, 40);
    sfMusic_play(game->music);
}

game_t *create_game(sfVideoMode mode, sfColor clear_color)
{
    game_t *game;

    game = malloc(sizeof(struct game));
    game->window = sfRenderWindow_create(mode, "My Hunter",
    sfResize | sfClose, NULL);
    game->clear_color = clear_color;
    game->rect = (sfIntRect) {0, 100, 1200, 700};
    game->size = (sfVector2f) {8400, 1800};
    game->texture = sfTexture_createFromFile("img/bg.png", NULL);
    game->sprite = sfSprite_create();
    game->clock = sfClock_create();
    create_music(game);
    sfSprite_scale(game->sprite, (sfVector2f) {1.5, 1.5});
    sfSprite_setTexture(game->sprite, game->texture, sfTrue);
    sfSprite_setTextureRect(game->sprite, game->rect);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return game;
}

void destroy_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfTexture_destroy(game->texture);
    sfMusic_destroy(game->music);
    free(game);
}
