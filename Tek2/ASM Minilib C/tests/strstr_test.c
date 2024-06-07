/*
** EPITECH PROJECT, 2022
** MiniLibC
** File description:
** strstr_test.c
*/

#include <criterion/criterion.h>
#include <string.h>

extern char* _strstr(const char*, const char*);

Test(test_strstr, search_string_present)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "world";

    cr_assert(_strstr(s1, s2) != NULL);
}

Test(test_strstr, search_string_not_present)
{
    const char* s1 = "Hello, world!";
    const char* s2 = "foo";

    cr_assert(_strstr(s1, s2) == NULL);
}
