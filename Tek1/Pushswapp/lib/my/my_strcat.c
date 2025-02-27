/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** My_strcat
*/

#include "my.h"

char *my_strcat(char *dest, const char *src)
{
    int i;
    int len = my_strlen(dest);

    for (i = 0; src[i]; i++)
        dest[len + i] = src[i];
    dest[len + i] = '\0';
    return dest;
}
