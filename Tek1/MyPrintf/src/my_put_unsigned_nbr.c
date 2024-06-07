/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** My_put_nbr
*/

#include "../include/printf.h"

int my_put_nbr_unsigned(int nb)
{
    check_unisgned(nb);
    if (nb > 9) {
        int c = nb % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(c + 48);
    } else
        my_putchar(nb + 48);
    return 0;
}
