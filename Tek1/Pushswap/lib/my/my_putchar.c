/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** My_putchar
*/

#include <unistd.h>

void my_putchar(char ch)
{
    write (1, &ch, 1);
}
