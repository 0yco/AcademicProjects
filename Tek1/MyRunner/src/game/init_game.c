/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** init.c
*/

#include "my_runner.h"

static void create_score(game_t *game)
{
    game->text = sfText_create();
    game->game_over = sfText_create();
    game->font = sfFont_createFromFile("assets/arcade.ttf");

    sfText_setString(game->text, "0");
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 60);
    sfText_setPosition(game->text, (sfVector2f) {35, 25});
    sfText_setColor(game->text, (sfColor) {255, 255, 255, 255});
}

static void create_sound(game_t *game)
{
    game->music = sfMusic_createFromFile("assets/sounds/this_sky_of_mine.ogg");
    game->music_over = sfMusic_createFromFile("assets/sounds/game_over.ogg");

    sfMusic_setLoop(game->music, sfTrue);
    sfMusic_setVolume(game->music, 20);
    sfMusic_setVolume(game->music_over, 20);
    sfMusic_play(game->music);
}

game_t *create_game(sfVideoMode mode, sfColor clear_color)
{
    game_t *game;

    game = malloc(sizeof(struct game));
    game->window = sfRenderWindow_create(mode, "My Runner",\
    sfResize | sfClose, NULL);
    game->state = START;
    game->clear_color = clear_color;
    game->clock = sfClock_create();
    sfRenderWindow_setFramerateLimit(game->window, 60);
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    create_sound(game);
    create_score(game);
    return game;
}
