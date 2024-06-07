/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strpbrk_test.c
*/

#include <criterion/criterion.h>
#include <string.h>

extern char* _strpbrk(const char*, const char*);

Test(test_strpbrk, search_characters_present)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "oe";

    cr_assert(_strpbrk(s1, s2) != NULL);
}

Test(test_strpbrk, search_characters_not_present)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "xy";

    cr_assert(_strpbrk(s1, s2) == NULL);
}
