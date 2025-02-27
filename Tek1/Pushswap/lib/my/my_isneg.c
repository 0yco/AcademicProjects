/*
** EPITECH PROJECT, 2021
** my_isneg.c
** File description:
** My_isneg
*/

#include <unistd.h>
#include "my.h"

int my_isneg(int n)
{
    if (n >= 0){
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
