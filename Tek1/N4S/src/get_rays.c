/*
** EPITECH PROJECT, 2022
** LIB NAPI
** File description:
** getRay.c
*/

#include "n4s.h"

char **get_rays(char *line)
{
    char **sorted = NULL;

    my_putstr("GET_INFO_LIDAR\n");
    sorted = strsplit(range_strdup(line, NULL,
    ":No further info", true), ":", false);
    sorted += 6;
    if (!(*sorted))
        return NULL;
    return sorted;
}
