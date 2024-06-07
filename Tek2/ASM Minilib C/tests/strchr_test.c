/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strchr_test.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern char *_strchr(const char *, int);

Test(test_strchr, basic)
{
    const char *str = "Hello World";
    char c = 'o';
    char *res = _strchr(str, c);
    cr_assert_eq(res, strchr(str, c),
    "Got: %p Expected: %p", res, strchr(str, c));
}

Test(test_strchr, not_found)
{
    const char *str = "Hello World";
    char c = 'z';
    char *res = _strchr(str, c);
    cr_assert_null(res, "Got: %p Expected: NULL", res);
}
