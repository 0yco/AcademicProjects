/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** main.c
*/

#include "../include/my_hunter.h"
#include <time.h>

sfBool check_collision_entity(entity_t *entity1, entity_t *entity2)
{
    sfVector2f pos_entity1 = {sfSprite_getPosition(entity1->sprite).x,
    sfSprite_getPosition(entity1->sprite).y};
    sfVector2f pos_entity2 = {sfSprite_getPosition(entity2->sprite).x,
    sfSprite_getPosition(entity2->sprite).y};

    if ((pos_entity1.x >= pos_entity2.x - 125 &&
    pos_entity1.x <= pos_entity2.x + entity2->size.x - 125)
    && (pos_entity1.y >= pos_entity2.y
    && pos_entity1.y <= pos_entity2.y + 100))
        return sfTrue;
    return sfFalse;
}

int main(void)
{
    sfVideoMode mode = {1800, 1040, 32};
    game_t *game = create_game(mode, sfBlack);
    entity_t *target = create_entity((sfIntRect) {0, 0, 64, 64},
    (sfVector2f) {400, 100}, "img/target.png", game);
    entity_t *entity;

    srand(time(NULL));
    entity = create_entity((sfIntRect) {0, 0, 200, 100}, (sfVector2f)
    {-350, rand() % 680}, "img/heroes.png", game);
    entity->size = (sfVector2f) {200, 100};
    target->size = (sfVector2f) {64, 64};
    process_game(game, entity, target);
    destroy_game(game);
    destroy_entity(target);
    destroy_entity(entity);
    return 0;
}
