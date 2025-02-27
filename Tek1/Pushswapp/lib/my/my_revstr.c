/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** My_revstr
*/

#include "my.h"

char *my_revstr(char *str)
{
    int i = 0;
    int c = my_strlen(str) - 1;
    char n;

    while (i < c && str[i] != '\0') {
        n = str[i];
        str[i] = str[c];
        str[c] = n;
        i ++;
        c --;
    }
    return str;
}
