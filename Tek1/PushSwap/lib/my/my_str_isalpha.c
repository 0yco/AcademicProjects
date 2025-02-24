/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** My_revstr
*/

int my_str_isalpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 64 || str[i] >= 123) {
            return 0;
        } else if (str[i] <= 96 && str[i] > 90) {
            return 0;
        }
    }
    return 1;
}
