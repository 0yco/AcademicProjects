/*
** EPITECH PROJECT, 2022
** LIB NAPI
** File description:
** getRay.c
*/

#include "n4s.h"
#include <ctype.h>

static bool isfloat(char *str)
{
    for (int i = 0; str[i]; i++)
        if ((str[i] < '0' || str[i] > '9') && str[i] != '.')
            return false;
    return true;
}

bool update_info(algo_t *algo, char **rays)
{
    if (!isfloat(rays[0]))
        return false;
    if (!isfloat(rays[15]))
        return false;
    if (!isfloat(rays[30]))
        return false;
    algo->speed = 1;
    algo->alpha = 0;
    algo->middle = atof(rays[15]);
    algo->left = atof(rays[0]);
    algo->right = atof(rays[30]);
    return true;
}
