/*
** EPITECH PROJECT, 2021
** my_str_islower.c
** File description:
** My_str_islower
*/

int my_str_islower(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] <= 96 || str[i] >= 123) {
            return 0;
        }
    }
    return 1;
}
