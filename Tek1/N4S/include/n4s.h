/*
** EPITECH PROJECT, 2022
** B-AIA-200-MPL-2-1-n4s-enzo.daumalle
** File description:
** n4s.h
*/

#ifndef _N4S_H_
    #define _N4S_H_
    #include "my.h"
    #include <stdarg.h>
    #include <stdio.h>
    #include <string.h>
    #include <unistd.h>
    #include <time.h>
    #include <stdlib.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <fcntl.h>
    #include <dirent.h>
    #include <stdbool.h>
    #include <math.h>

    #define UNUSED __attribute__((unused))
    #define INT (int)

typedef struct algo_s {
    float speed;
    float alpha;
    float middle;
    float left;
    float right;
} algo_t;

char **get_rays(char *line);
char *read_file(char *path);
void limit_value(algo_t *algo);
bool update_info(algo_t *algo, char **rays);
void algo(algo_t *algo, char **rays);

#endif
