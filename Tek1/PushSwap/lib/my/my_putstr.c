/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** My_putstr
*/

#include <unistd.h>

int my_strlen(char const *str);

int my_putstr(char const *str)
{
    int i = 0;

    write(1, &str[i++], my_strlen(str));
    return 0;
}
