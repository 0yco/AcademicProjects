/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** My_strlen
*/

int my_strlen_num(int nb)
{
    int i = 0;

    if (nb < 0) {
        i++;
        nb = -nb;
    }
    while (nb > 9) {
        nb /= 10;
        i++;
    }
    i++;
    return i;
}
