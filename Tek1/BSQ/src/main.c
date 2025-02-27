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

map_t *create_map(int fd, struct stat details);
void convert_to_int(map_t *map);
void draw_square(map_t *map);
void find_corner(map_t *map);

void increase_loop(int *pos_value, int *pos_buffer, int *i)
{
    *pos_value = 0;
    *pos_buffer = *pos_buffer + 1;
    *i = *i + 1;
}

char *draw_square_of_one(map_t *map)
{
    for (int i = 0; i < map->nb_cols * map->nb_rows; i++) {
        if (map->buffer[i] == '.') {
            map->buffer[i] = 'x';
            return map->buffer;
        }
    }
    return map->buffer;
}

char *bsq(char *argv)
{
    int fd = open(argv, O_RDONLY);
    struct stat details;
    stat(argv, &details);
    if (fd < 0)
        exit(84);
    map_t *map = create_map(fd, details);
    if (map->nb_cols == 1 || map->nb_rows == 1)
        return draw_square_of_one(map);
    if (details.st_size == 0)
        exit(84);
    convert_to_int(map);
    find_corner(map);
    draw_square(map);
    close(fd);
    return map->buffer;
}

int main(int argc, char *argv[])
{
    if (argc != 2)
        exit(84);
    my_printf("%s", bsq(argv[1]));
    return 0;
}
