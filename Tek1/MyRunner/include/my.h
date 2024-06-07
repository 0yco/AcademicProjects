/*
** EPITECH PROJECT, 2021
** Lib
** File description:
** my.h
*/

#ifndef __MY_H__
    #define __MY_H__
    #include <stdarg.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
void detect_flags_chars(char *flags, va_list ap, int i);
int detect_flags_int(char *flags, va_list ap, int i, int arg);
int detect_flags_op(char *flags, va_list ap, int i, int arg);
void detect_hashflags(char *flags, int i);
int detect_flags_sub_add(char *flags, va_list ap, int i, int arg);
int detect_flags_zero(char *flags, va_list ap, int i, int arg);
void write_space_or_zero(int count, int boel);
void check_unisgned(int nb);
int my_printf(char *formats, ...);
int my_strlen_num(int nb);
int str_contains(char *table, char content);
int my_put_nbr_unsigned(int nb);
int my_put_longnbr(long int nb);
int my_putnbr_base(int nbr, char const *base);
int my_putnbr_longbase(unsigned long int nbr, char const *base);
int my_putstr_printable(char const *str);
void my_put_address(char *pointer);

#endif /* __MY_H__ */
