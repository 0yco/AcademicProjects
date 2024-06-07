/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** event.c
*/

#include "my_runner.h"

static void animation_isstate(lnk_list_t *list, int state)
{
    while (list->value->utils.id != CHR) {
        list = list->prev;
        if (list->value->animation.state != JUMP &&
        list->value->animation.state != SLIDE) {
            list->value->animation.isstate = 1;
            list->value->animation.state = state;
        }
    }
}

static void game_isstate(game_t *game, int state)
{
    if (game->state == PAUSE && state == PAUSE) {
        game->state = GAME;
        sfMusic_play(game->music);
    } else
        game->state = state;
}

void process_window_events(game_t *game, lnk_list_t *list)
{
    if (game->event.type == sfEvtClosed || (game->event.type
    == sfEvtKeyPressed && game->event.key.code == sfKeyEscape))
        sfRenderWindow_close(game->window);
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeySpace &&
    list->value->animation.isstate == 0)
        animation_isstate(list, JUMP);
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyC &&
    list->value->animation.isstate == 0)
        animation_isstate(list, SLIDE);
    if (game->event.type == sfEvtKeyPressed &&
    game->event.key.code == sfKeyP)
        game_isstate(game, PAUSE);
}
