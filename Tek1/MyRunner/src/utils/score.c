/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** score.c
*/

#include "my_runner.h"

static int my_intlen(int nbr)
{
    int len = 0;

    if (nbr < 0) {
        len++;
        nbr = -nbr;
    }
    while (nbr > 9) {
        len++;
        nbr = nbr / 10;
    }
    return ++len;
}

void count_score(int nb, game_t *game)
{
    int c = 0;
    game->score = game->score + nb;
    int d = game->score;
    int i = 0;
    char *text_score = malloc(sizeof(char) * my_intlen(game->score));

    text_score[i] = c + '0';
    for (; d > 9; i++) {
        c = d % 10;
        d = d / 10;
        text_score[i] = c + '0';
    }
    text_score[i] = d + '0';
    text_score[i + 1] = '\0';
    text_score = my_revstr(text_score);
    sfText_setString(game->text, text_score);
}
