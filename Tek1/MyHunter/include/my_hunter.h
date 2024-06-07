/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** my_hunter.h
*/

#ifndef MY_HUNTER_H
    #define MY_HUNTER_H
    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdio.h>

    #include "game.h"
    #include "entity.h"

game_t *create_game(sfVideoMode mode, sfColor clear_color);
entity_t *create_entity(sfIntRect retc, sfVector2f pos, \
char *img, game_t *game);
void entity_left_background(entity_t *entity);
void animate_entity(entity_t *entity);
void animate_mouse(entity_t *entity, game_t *window);
void animate_death_blessing(entity_t *entity);
void animate_background(game_t *game);
void entity_isdead_or_save(entity_t *entity);
void manage_mouse_click(entity_t *target, entity_t *entity, int boel);
int process_game(game_t *game, entity_t *entity, entity_t *target);
void destroy_game(game_t *game);
void destroy_entity(entity_t *entity);
sfBool check_collision_entity(entity_t *entity1, entity_t *entity2);

#endif /* MY_HUNTER_H */
