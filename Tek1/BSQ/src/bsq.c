/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-BSQ-enzo.daumalle
** File description:
** main.c
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "../include/map.h"

void increase_loop(int *pos_value, int *pos_buffer, int *i);

map_t *create_map(int fd, struct stat details)
{
    int i;
    map_t *map = malloc(sizeof(map_t));
    map->buffer = malloc(sizeof(char) * details.st_size + 1);
    map->nb_cols = 0;
    map->nb_rows = 0;

    read(fd, map->buffer, details.st_size);
    map->buffer[details.st_size] = '\0';
    for (i = 0; map->buffer[i] != '\n'; i++)
        map->nb_rows = map->nb_rows * 10 + map->buffer[i] - 48;
    map->nb_cols = (details.st_size - (i + 1)) / map->nb_rows - 1;
    map->buffer += (i + 1);
    map->greater_number = 0;
    map->boel = 1;
    return map;
}

void convert_to_int(map_t *map)
{
    int i = 0;
    int value;
    int pos_value = 0;
    map->arr = malloc(sizeof(int *) * map->nb_rows);

    for (int i = 0; i < map->nb_rows + 1; i++)
        map->arr[i] = malloc(sizeof(int) * map->nb_cols);
    for (int pos_buffer = 0; pos_buffer < (map->nb_cols + 1)
    * map->nb_rows; pos_buffer++) {
        if (map->buffer[pos_buffer] == 'o')
            value = 0;
        else if (map->buffer[pos_buffer] == '.')
            value = 1;
        else
            exit(84);
        map->arr[i][pos_value] = value;
        pos_value++;
        if (pos_value == map->nb_cols)
            increase_loop(&pos_value, &pos_buffer, &i);
    }
}

void draw_square(map_t *map)
{
    for (int i = map->greater_number; i > 0; i--) {
        for (int count = map->greater_number; count > 0; count--) {
            map->buffer[(map->pos[1] - (i - 1)) * (map->nb_cols + 1) +
            (map->pos[0] + 1 - count)] = 'x';
        }
    }
}

void transform_nbr(map_t *map, int count, int i)
{
    int lower_number = 0;
    int cumul = map->arr[i - 1][count - 1] + map->arr[i][count - 1] +
    map->arr[i - 1][count];

    if (map->arr[i][count] != 0 && cumul != 0) {
        lower_number = map->arr[i - 1][count - 1];
        if (map->arr[i - 1][count] < lower_number)
            lower_number = map->arr[i - 1][count];
        if (map->arr[i][count - 1] < lower_number)
            lower_number = map->arr[i][count - 1];
        map->arr[i][count] = lower_number + 1;
    }
    if (map->arr[i][count] > map->greater_number ||
    (map->arr[i][count] >= map->greater_number && map->boel == 1)) {
        map->greater_number = map->arr[i][count];
        map->pos[0] = count;
        map->pos[1] = i;
        map->boel = 1;
    } else
        map->boel = 0;
}

void find_corner(map_t *map)
{
    for (int i = 1; i < map->nb_rows; i++)
        for (int count = 1; count < map->nb_cols; count++)
            transform_nbr(map, count, i);
}
