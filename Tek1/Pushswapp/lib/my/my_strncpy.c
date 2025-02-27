/*
** EPITECH PROJECT, 2021
** my_strncpy.c
** File description:
** My_strncpy
*/

char *my_strncpy (char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n && src[i] != '\0') {
        dest[i] = src[i];
        i ++;
    }
    for (; i < n; i++)
        dest[i] = '\0';
    return dest;
}
