/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-matheo.beaunez
** File description:
** my_getnbr_base.c
*/

#include <stdlib.h>
#include "../include/printf.h"

static int error_two_digits(char *base)
{
    int count = 1;

    for (int i = 0; base[i] != base[count]; count++) {
        if (count == my_strlen(base)) {
            count = 0;
            i += 1;
        } else if (base[i] == '\0')
            return 0;
        if (count + 1 == i)
            count++;
    }
    return 1;
}

static int get_nbr(char *str, char *base, int i)
{
    int count = 0;

    while (str[i] != base[count]) {
        count++;
    }
    return count;
}

static void check_nbr(char *str, char *base, int i, int len_base)
{
    for (int count = 0; str[i] != base[count]; count++) {
        if (count == len_base)
            exit(84);
    }
}

int my_getnbr_base(char const *str, char const *base)
{
    int result = 0;
    int len_base = my_strlen(base);
    int len_str = my_strlen(str);
    int nbr = 0;
    int pos_nbr = 0;

    if (error_two_digits((char*)base) == 1)
        exit(84);
    for (int i = 0; str[i] != '\0'; i++) {
        check_nbr((char*)str, (char*)base, i, len_base);
        pos_nbr = len_str - (i + 1);
        nbr = get_nbr((char*)str, (char*)base, i);
        result += my_compute_power_rec(len_base, pos_nbr) * nbr;
    }
    return result;
}
