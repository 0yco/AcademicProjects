/*
** EPITECH PROJECT, 2021
** BS My Hunter
** File description:
** map.h
*/

#ifndef MAP_H_
    #define MAP_H_

typedef struct map {
    int nb_cols;
    int nb_rows;
    char *buffer;
    int **arr;
    int pos[2];
    int greater_number;
    int boel;
} map_t;

map_t *create_map(int fd, struct stat details);

#endif /* MAP_H_ */
