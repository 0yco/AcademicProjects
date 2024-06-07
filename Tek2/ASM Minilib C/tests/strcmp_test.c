/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strcmp_test.c
*/

#include <criterion/criterion.h>
#include <string.h>

extern int _strcmp(const char *, const char *);

Test(test_strcmp, equal_strings)
{
    const char *s1 = "Hello, world!";
    const char *s2 = "Hello, world!";
    cr_assert_eq(strcmp(s1, s2), _strcmp(s1, s2), "Error: strings are equal");
}

Test(test_strcmp, different_strings)
{
    const char *s1 = "Hello, world!";
    const char *s2 = "Goodbye, world!";
    cr_assert_eq(strcmp(s1, s2),
    _strcmp(s1, s2), "Error: strings are different");
}

Test(test_strcmp, empty_strings)
{
    const char *s1 = "";
    const char *s2 = "";
    cr_assert_eq(strcmp(s1, s2), _strcmp(s1, s2), "Error: empty strings");
}
