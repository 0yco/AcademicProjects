/*
** EPITECH PROJECT, 2021
** my_printf
** File description:
** detect_op.c
*/

#include <stdarg.h>
#include <stdlib.h>
#include "../include/printf.h"

void detect_hashflags(char *flags, int i)
{
    switch (flags[i])
    {
    case 'x':
        my_putstr("0x");
        break;
    case 'X':
        my_putstr("0X");
        break;
    case 'o':
        my_putchar('0');
        break;
    }
}

int detect_flags_zero(char *flags, va_list ap, int i, int arg)
{
    int len_arg = my_strlen_num(arg);
    int count = 0;

        i++;
        if (flags[i] == '+' || flags[i] == '0') {
            my_putchar('+');
            i++;
            len_arg++;
        }
        for (; flags[i] >= '0' && flags[i] <= '9'; i++)
            count = count * 10 + flags[i]- 48;
        count -= len_arg;
        if (str_contains("diouXxb", flags[i]) == 1) {
            write_space_or_zero(count, 1);
            detect_flags_int(flags, ap, i, arg);
        } else
            exit(84);
    return i;
}

int detect_flags_sub_add(char *flags, va_list ap, int i, int arg)
{
    int len_arg = my_strlen_num(arg);
    int count = 0;
    int boel = flags[i];

        if(flags[i + 1] == '-')
            i++;
        if(flags[i] == '-' || flags[i] == '+')
            i++;
        for (; flags[i] >= '0' && flags[i] <= '9'; i++)
            count = count * 10 + flags[i] - 48;
        count -= len_arg;
        if (str_contains("diouXxbc", flags[i]) == 1 &&
        (boel == 48 || boel == 45)) {
            detect_flags_int(flags, ap, i, arg);
            write_space_or_zero(count, boel);
        } else if (str_contains("diouXxbc", flags[i]) == 1) {
            write_space_or_zero(count, boel);
            detect_flags_int(flags, ap, i, arg);
        }
        return i;
}

int detect_flags_op(char *flags, va_list ap, int i, int arg)
{
    if (arg >= 0 && ((flags[i] == '-' && flags[i + 1] != '-') ||
    (flags[i] == '0' && flags[i + 1] == '-') ||
    (flags[i] == '+' && (flags[i + 1] != '+' && flags[i + 1] != '0')) ||
    (flags[i] > '0' && flags[i] <= '9')))
        return detect_flags_sub_add(flags, ap, i, arg);
    else if (arg >= 0 && ((flags[i] == '0' && flags[i + 1] != '0') ||
    (flags[i] == '+' && flags[i + 1] == '0')))
        return detect_flags_zero(flags, ap, i, arg);
    else
        return detect_flags_int(flags, ap, i, arg);
    return i;
}
