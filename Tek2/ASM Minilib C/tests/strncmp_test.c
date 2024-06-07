/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strncmp_test.c
*/

#include <criterion/criterion.h>
#include <string.h>

extern int _strncmp(const char *, const char *, size_t);

Test(test_strncmp, equal_strings)
{
    const char *s1 = "Hello, world!";
    const char *s2 = "Hello, world!";
    cr_assert_eq(strncmp(s1, s2, 5),
    _strncmp(s1, s2, 5), "Error: strings are equal");
}

Test(test_strncmp, different_strings)
{
    const char *s1 = "Hello, world!";
    const char *s2 = "Goodbye, world!";
    cr_assert_eq(strncmp(s1, s2, 7),
    _strncmp(s1, s2, 7), "Error: strings are different");
}

Test(test_strncmp, empty_strings)
{
    const char *s1 = "";
    const char *s2 = "";
    cr_assert_eq(strncmp(s1, s2, 1),
    _strncmp(s1, s2, 1), "Error: empty strings");
}
