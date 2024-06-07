/*
** EPITECH PROJECT, 2021
** B-CPE-101-MPL-1-1-bistromatic-matheo.beaunez
** File description:
** contains.c
*/

int str_contains(char *table, char content)
{
    for (int i = 0; table[i]; i++)
        if (content == table[i])
            return 1;
    return 0;
}
