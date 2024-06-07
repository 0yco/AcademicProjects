/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** printf.h
*/

#ifndef __PRINTF_H__
    #define __PRINTF_H__
    #include <stdarg.h>

void detect_flags_chars(char *flags, va_list ap, int i);
int detect_flags_int(char *flags, va_list ap, int i, int arg);
int detect_flags_op(char *flags, va_list ap, int i, int arg);
void detect_hashflags(char *flags, int i);
int detect_flags_sub_add(char *flags, va_list ap, int i, int arg);
int detect_flags_zero(char *flags, va_list ap, int i, int arg);
void write_space_or_zero(int count, int boel);
void check_unisgned(int nb);
int my_printf(char *formats, ...);
int my_strlen(char const *str);
int my_strlen_num(int nb);
int str_contains(char *table, char content);
char *my_revstr(char *str);
void my_putchar(char ch);
int my_put_nbr(int nb);
int my_put_nbr_unsigned(int nb);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_longbase(unsigned long int nbr, char const *base);
int my_putstr_printable(char const *str);
int my_putstr(char const *str);
void my_put_address(char *pointer);
int my_compute_power_rec(int nb, int p);

#endif /* __PRINTF_H__ */
