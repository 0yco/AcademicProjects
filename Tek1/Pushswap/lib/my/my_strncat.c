/*
** EPITECH PROJECT, 2021
** my_strncat.c
** File description:
** My_strncat
*/

#include "my.h"

char *my_strncat(char *dest, const char *src, int n)
{
    int lengh = my_strlen(dest);
    int i;

    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[lengh + i] = src[i];
    }

    dest[lengh + i] = '\0';
    return dest;
}
