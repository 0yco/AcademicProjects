/*
** EPITECH PROJECT, 2022
** utils
** File description:
** my_str_isequal_to.c
*/

#include "my_sokoban.h"

bool my_str_isequal(char *from, char *to)
{
    int len_from = my_strlen(from);
    int len_to = my_strlen(to);

    if (len_to != len_from)
        return 0;
    for (int i = 0; to[i]; i++)
        if (from[i] != to[i])
            return 0;
    return 1;
}
