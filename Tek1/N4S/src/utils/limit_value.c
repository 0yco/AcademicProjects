/*
** EPITECH PROJECT, 2022
** B-AIA-200-MPL-2-1-n4s-enzo.daumalle
** File description:
** limit_value.c
*/

#include "n4s.h"

void limit_value(algo_t *algo)
{
    if (algo->speed < -1)
        algo->speed = -1;
    else if (algo->speed > 1)
        algo->speed = 1;
    if (algo->alpha < -1)
        algo->alpha = -1;
    else if (algo->alpha > 1)
        algo->alpha = 1;
}
