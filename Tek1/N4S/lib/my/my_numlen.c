/*
** EPITECH PROJECT, 2021
** LIB
** File description:
** my_numlen.c
*/

int my_numlen(int nb)
{
    int i = 0;

    if (nb < 0) {
        nb = -nb;
    }
    while (nb > 9) {
        nb /= 10;
        i++;
    }
    i++;
    return i;
}
