/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** memset_test.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern void *_memset(void *, int, size_t);

Test(test_memset, basic)
{
    char got[] = "Hello World";
    char exp[] = "Hello World";
    int c = 'o';
    size_t n = 5;
    _memset(got, c, n);
    memset(exp, c, n);
    cr_assert_arr_eq(got, exp, strlen(exp), "Got: %s Expected: %s", got, exp);
}

Test(test_memset, zero_length)
{
    char got[] = "Hello World";
    char exp[] = "Hello World";
    int c = 'o';
    size_t n = 0;
    _memset(got, c, n);
    memset(exp, c, n);
    cr_assert_arr_eq(got, exp, strlen(exp), "Got: %s Expected: %s", got, exp);
}
