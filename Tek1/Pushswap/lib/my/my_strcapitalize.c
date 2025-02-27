/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** My_revstr
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    my_strlowcase(str);

    if (str[0] >= 'a' && str[0] <= 'z')
        str[0] -= 32;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+'
        && str[i + 1] >= 'a' && str[i + 1] <= 'z')
            str[i + 1] -= 32;
    }
    return str;
}
