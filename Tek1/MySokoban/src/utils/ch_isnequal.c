/*
** EPITECH PROJECT, 2022
** B-PSU-200-MPL-2-1-mysokoban-enzo.daumalle
** File description:
** str_ncontains.c
*/

#include "my_sokoban.h"

int ch_isnequal(char ch, char *container)
{
    for (int j = 0; container[j]; j++)
        if (ch == container[j])
            return 0;
    return 1;
}
