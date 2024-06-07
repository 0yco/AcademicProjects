/*
** EPITECH PROJECT, 2021
** B-MUL-200-MPL-2-1-myrpg-enzo.daumalle
** File description:
** dog_mode.c
*/

// review

#include <my_rpg.h>

void god_mode(game_t *game, object_t *chr)
{
    static bool god = false;

    if (god) {
        chr->stats->speed = 20;
        chr->stats->hp = 10000;
        god = false;
    } else {
        chr->stats->hp = 100;
        chr->stats->speed = 5;
        god = true;
    }
}