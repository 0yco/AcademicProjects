/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** My_strstr
*/

char *my_strstr(char *str, char const *to_find)
{
    const char *n = str;
    const char *c = to_find;

    while (1) {

        if (! *c)
            return str;

        if (! *n)
            return 0;

        if (*n++ != *c++) {
            n = ++str;
            c = to_find;
        }
    }
}
