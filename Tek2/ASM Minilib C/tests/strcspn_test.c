/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strcspn_test.c
*/

#include <criterion/criterion.h>
#include <string.h>

extern size_t _strcspn(const char*, const char*);

Test(test_strcspn, search_characters_present)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "wd!";

    cr_assert(_strcspn(s1, s2) == 7);
}

Test(test_strcspn, search_characters_not_present)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "xyz";

    cr_assert(_strcspn(s1, s2) == 13);
}
