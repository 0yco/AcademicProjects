/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** main.c
*/

#include "my_runner.h"

static void init_object(lnk_list_t **list, char *path)
{
    create_object((utils_t) {{0, 0, 177, 177}, {1070, 25},
    LIFE, "assets/img/heart.png", {0, 0}}, list);
    create_map(list, path);
    create_object((utils_t) {{0, 0, 240, 275}, {200, 520},
    CHR, "assets/img/chr.png", {0, 0}}, list);
    create_object((utils_t) {{0, 0, 1921, 724}, {0, 0},
    MG, "assets/img/mg.png", {0, 0}}, list);
    create_object((utils_t) {{0, 0, 1921, 724}, {0, 0},
    BG, "assets/img/bg.png", {0, 0}}, list);
}

int main(int argc, char *argv[])
{
    int err;
    if ((err = check_arg(argc, argv)) != 1)
        return err;
    sfVideoMode mode = {1200, 680, 32};
    game_t *game = create_game(mode, sfBlack);
    lnk_list_t *list = NULL;

    init_object(&list, argv[1]);
    process_game(game, list);
    process_list(list, game, destroy_object);
    free(list);
    destroy_game(game);
    return 0;
}
