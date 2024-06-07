/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** my_hunter.h
*/

#ifndef MY_RUNNER_H
    #define MY_RUNNER_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include <stdio.h>

    #include "my.h"
    #include "game.h"
    #include "object.h"

void add_node(object_t *object, lnk_list_t **head);
sfBool check_collision_entity(lnk_list_t *list, game_t *game);
void count_score(int nb, game_t *game);
void get_position(lnk_list_t *list, game_t *game, int id);
int check_arg(int ac, char *av[]);
void gravity(lnk_list_t *list);
void create_map(lnk_list_t **list, char *file);
game_t *create_game(sfVideoMode mode, sfColor clear_color);
void create_object(utils_t utils, lnk_list_t **list);
void animation_sprite(game_t *game, lnk_list_t *list, int speed);
void animation_character(lnk_list_t *list, game_t *game);
int process_game(game_t *game, lnk_list_t *list);
void process_window_events(game_t *game, lnk_list_t *list);
void process_list(lnk_list_t *list, game_t *game,
void (*pointer)(game_t *, lnk_list_t *));
void destroy_object(__attribute__((unused)) game_t *game, lnk_list_t *list);
void destroy_game(game_t *game);

#endif /* MY_RUNNER_H */
