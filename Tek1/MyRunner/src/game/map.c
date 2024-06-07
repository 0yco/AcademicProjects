/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** map.c
*/

#include "my_runner.h"

static int help(char *av[])
{
    if (av[1][0] == '-' && av[1][1] == 'h'
    && my_strlen(av[1]) == 2) {
        my_putstr("Manual :\n\nUSAGE\n./my_runner map.txt\n\n\n");
        my_putstr("OPTIONS\n\t-i  In progress (launch the game in infinity ");
        my_putstr("mode.)\n\t-h  Print the usage and quit.\n\n\n");
        my_putstr("CREATE MAP\n\t1 : Floor\n\t2 : Statue\n\t3 : Void\n\n");
        my_putstr("Example : '11111212133113333312131313121' (2-2000)\n");
        my_putstr("Read map/.legend for more information...\n\n\n");
        my_putstr("USER INTERACTIONS\n\tSPACE_KEY\tJump\n\tC_KEY\t\tSlide\n");
        my_putstr("\tP_KEY\t\tPause\n");
        return 0;
    }
    return 1;
}

static int get_line(char *av[])
{
    FILE *map;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    map = fopen(av[1], "r");
    if (map == NULL || (nread = getline(&line, &len, map)) == -1) {
        my_putstr("The map does not exist or the file is invalid\n");
        return 84;
    }
    if (nread < 2 || nread > 2000) {
        my_putstr("The map is too small or too big (2 to 1000)\n");
        return 84;
    }
    free(line);
    fclose(map);
    return 1;
}

int check_arg(int ac, char *av[])
{
    if (ac != 2)
        return 84;
    if (!help(av))
        return 0;
    return get_line(av);
}

static void create_block(lnk_list_t **list, int *posx, char line)
{
    switch (line - 48) {
        case 1: create_object((utils_t) {{0, 0, 487, 44}, {*posx, 636},
        FG, "assets/img/fg.png", {0, 0}}, list);
            *posx = *posx + 487;
            break;
        case 2: create_object((utils_t) {{377, 233, 80, 50}, {*posx, 580},
        BLOCK, "assets/img/devil_statue.png", {0, 0}}, list);
            break;
        case 3:
            *posx = *posx + 100;
    }
}

void create_map(lnk_list_t **list, char *file)
{
    FILE *map;
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;
    int posx = 0;

    map = fopen(file, "r");
    nread = getline(&line, &len, map);
    for (int index = 0; index < nread; index++)
        create_block(list, &posx, line[index]);
    free(line);
}
