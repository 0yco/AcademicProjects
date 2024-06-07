/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strrchr_test.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern char *_strrchr(const char *, int);

Test(test_strrchr, basic)
{
    const char *str = "Hello World";
    char c = 'o';
    char *res = _strrchr(str, c);
    cr_assert_eq(res, strrchr(str, c),
    "Got: %p Expected: %p", res, strrchr(str, c));
}

Test(test_strrchr, not_found)
{
    const char *str = "Hello World";
    char c = 'z';
    char *res = _strrchr(str, c);
    cr_assert_null(res, "Got: %p Expected: NULL", res);
}
