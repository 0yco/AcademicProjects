/*
** EPITECH PROJECT, 2021
** my_swap.c
** File description:
** My_swap
*/

void my_swap(int *a, int *b)
{
    int c = *b;
    *b = *a;
    *a = c;
}
