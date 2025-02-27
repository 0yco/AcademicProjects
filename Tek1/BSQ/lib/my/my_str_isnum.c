/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** My_revstr
*/

int my_str_isnum(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return 0;
        }
    }
    return 1;
}
