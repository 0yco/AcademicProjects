/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** loop.c
*/

#include "my_runner.h"

static void process_sprite(game_t *game, lnk_list_t *list)
{
    int speed = 0;

    sfRenderWindow_drawSprite(game->window, list->value->sprite, NULL);
    if (game->state == PAUSE || game->state == GAME_OVER) {
        sfMusic_pause(game->music);
        return;
    }
    count_score(1, game);
    animation_sprite(game, list, speed);
}

void process_list(lnk_list_t *list, game_t *game,
void (*pointer)(game_t *, lnk_list_t *))
{
    while (list != NULL) {
        pointer(game, list);
        list = list->prev;
    }
}

int process_game(game_t *game, lnk_list_t *list)
{
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            process_window_events(game, list);
        sfRenderWindow_clear(game->window, game->clear_color);
        process_list(list, game, process_sprite);
        sfRenderWindow_drawText(game->window, game->text, NULL);
        sfRenderWindow_drawText(game->window, game->game_over, NULL);
        sfRenderWindow_display(game->window);
    }
    return 0;
}
