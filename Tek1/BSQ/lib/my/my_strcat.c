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
    int lengh = my_strlen(dest);

    for (i = 0; src[i] != '\0'; i++)
        dest[lengh + i] = src[i];

    dest[lengh + i] = '\0';
    return dest;
}
