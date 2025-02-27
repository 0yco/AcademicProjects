/*
** EPITECH PROJECT, 2021
** my_is_prime.c
** File description:
** My_is_prime
*/

int my_is_prime(int nb)
{

    if (nb % 2 != 0)
        return 1;

    if (nb == 2)
        return 1;

    if (nb % 2 == 0 && nb != 2 || nb % 3 == 0 || nb <= 1)
        return 0;

    return 0;
}
