/*
** EPITECH PROJECT, 2022
** B-AIA-200-MPL-2-1-n4s-enzo.daumalle
** File description:
** main.c
*/

#include "n4s.h"

int main(void)
{
    algo_t *alg = malloc(sizeof(algo_t));
    char **rays = NULL;
    char *line = NULL;
    size_t len = 0;

    my_putstr("START_SIMULATION\n");
    while (1) {
        if (getline(&line, &len, stdin) == -1)
            fprintf(stderr, "Error getline\n");
        rays = get_rays(line);
        if (!rays)
            continue;
        algo(alg, rays);
    }
    exit(EXIT_SUCCESS);
    return (0);
}
