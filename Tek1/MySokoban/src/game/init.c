/*
** EPITECH PROJECT, 2022
** B-PSU-200-MPL-2-1-mysokoban-enzo.daumalle
** File description:
** init.c
*/

#include "my_sokoban.h"

static void check_map(game_t *game)
{
    int rlen;
    int len = 1;
    int end_line = 0;

    for (rlen = 0; game->map[rlen] && game->map[rlen] != '\n'; rlen++);
    rlen += 1;
    for (int i = 0; game->map[i + rlen]; i++) {
        if (game->map[i] == '\n')
            end_line = 1;
        if (end_line && len != rlen)
            exit_sokoban(84);
        else if (end_line) {
            end_line = 0;
            len = 0;
        }
        len += 1;
    }
}

void check_game(game_t *game)
{
    for (int i = 0; game->map[i]; i++) {
        if (game->map[i] == 'O')
            game->nbO += 1;
        if (ch_isnequal(game->map[i], " \n#XOP"))
            exit_sokoban(84);
    }
    check_map(game);
}

game_t *init_game(char *path_map)
{
    int fd;
    int nread;
    struct stat st;
    game_t *game = malloc(sizeof(game_t));
    if ((fd = open(path_map, O_RDONLY)) == -1)
        exit_sokoban(84);
    game->path_map = path_map;
    game->nbO = 0;
    stat(path_map, &st);
    game->map = malloc(sizeof(char) * st.st_size + 1);
    game->onbox = false;
    game->pushX = false;
    nread = read(fd, game->map, st.st_size);
    game->map[nread] = '\0';
    check_game(game);
    game->lose = game->nbO;
    game->p_box = malloc(sizeof(int *) * (game->nbO + 1));
    save_posmap(game);
    save_posentity(game);
    return game;
}

void init(game_t **game, char *path_map)
{
    WINDOW *win = initscr();

    *game = init_game(path_map);
    keypad(win, TRUE);
    noecho();
    nodelay(win, TRUE);
    use_default_colors();
    start_color();
    init_pair(1, COLOR_WHITE, -1);
    curs_set(0);
    addstr((*game)->map);
}
