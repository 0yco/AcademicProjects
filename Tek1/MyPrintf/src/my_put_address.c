/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** my_put_address.c
*/

#include "../include/printf.h"

void my_put_address(char *pointer)
{
    unsigned long int address = (unsigned long) pointer;
    my_putstr("0x");
    my_putnbr_longbase(address, "0123456789abdef");
}