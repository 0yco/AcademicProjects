/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-enzo.daumalle
** File description:
** loop.c
*/

#include "../include/my_hunter.h"

static void process_window_events(game_t *window, entity_t *target, entity_t *entity)
{
    if (window->event.type == sfEvtClosed ||
    (window->event.type == sfEvtKeyPressed &&
    window->event.key.code == sfKeyEscape))
        sfRenderWindow_close(window->window);
    if (sfMouse_isButtonPressed(sfMouseLeft))
        manage_mouse_click(target, entity, 1);
    if (sfMouse_isButtonPressed(sfMouseRight))
        manage_mouse_click(target, entity, 2);
    if (window->event.type == sfEvtKeyPressed
    && window->event.key.code == sfKeyR)
        sfSprite_setPosition(entity->sprite, entity->pos);
}

int process_game(game_t *game, entity_t *entity, entity_t *target)
{
    while (sfRenderWindow_isOpen(game->window)) {
        while (sfRenderWindow_pollEvent(game->window, &game->event))
            process_window_events(game, target, entity);
        entity_left_background(entity);
        animate_background(game);
        animate_entity(entity);
        animate_mouse(target, game);
        sfRenderWindow_clear(game->window, game->clear_color);
        sfRenderWindow_drawSprite(game->window, game->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, entity->sprite, NULL);
        sfRenderWindow_drawSprite(game->window, target->sprite, NULL);
        sfRenderWindow_display(game->window);
    }
    return (0);
}
