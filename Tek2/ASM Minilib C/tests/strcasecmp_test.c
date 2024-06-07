/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strcasecmp_test.c
*/

#include <criterion/criterion.h>
#include <string.h>

extern int _strcasecmp(const char*, const char*);

Test(test_strcasecmp, identical_strings)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "hello, world!";

    cr_assert(_strcasecmp(s1, s2) == 0);
}

Test(test_strcasecmp, different_strings)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "Goodbye, world!";

    cr_assert(_strcasecmp(s1, s2) != 0);
}
