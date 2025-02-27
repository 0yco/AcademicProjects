/*
** EPITECH PROJECT, 2021
** my_strcmp.c
** File description:
** My_strcmp
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int result = 0;

    if (my_strlen(s1) > my_strlen(s2))
        return (my_strlen(s1) - my_strlen(s2));

    if (my_strlen(s1) < my_strlen(s2))
        return (my_strlen(s1) - my_strlen(s2));

    for (int i = 0; s1[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            result--;
        if (s2[i] > s1[i])
            result++;
    }
    return result;
}
