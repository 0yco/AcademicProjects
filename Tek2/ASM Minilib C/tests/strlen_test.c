/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strlen_test.c
*/

#include <criterion/criterion.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>

extern int _strlen(const char *);

Test(test_strlen, basic)
{
    const char *str = "Hello World";
    int len = _strlen(str);
    cr_assert_eq(len, strlen(str), "Got: %d Expected: %lu", len, strlen(str));
}

Test(test_strlen, empty_string)
{
    const char *str = "";
    int len = _strlen(str);
    cr_assert_eq(len, strlen(str), "Got: %d Expected: %lu", len, strlen(str));
}
