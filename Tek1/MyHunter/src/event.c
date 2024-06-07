/*
** EPITECH PROJECT, 2021
** My Hunter
** File description:
** event.c
*/

#include "../include/my_hunter.h"

void manage_mouse_click(entity_t *target, entity_t *entity, int boel)
{
    if (check_collision_entity(target, entity) && boel == 1
    && entity->animation.rect.width == 200) {
        sfMusic_play(entity->animation.sound_death);
        sfSprite_setTexture(entity->sprite, entity->texture_death, sfTrue);
        entity->size = (sfVector2f) {512, 512};
        entity->animation.rect = (sfIntRect) {0, 0, 128, 128};
    } else if (check_collision_entity(target, entity) && boel == 2
    && entity->animation.rect.width == 200) {
        sfMusic_play(entity->animation.sound_bless);
        sfSprite_setTexture(entity->sprite, entity->texture_bless, sfTrue);
        sfSprite_setPosition(entity->sprite,
        (sfVector2f) {sfSprite_getPosition(entity->sprite).x,
        sfSprite_getPosition(entity->sprite).y - 30});
        entity->size = (sfVector2f) {728, 824};
        entity->animation.rect = (sfIntRect) {0, 0, 182, 206};
    }
}

static int random_respawn(entity_t *entity, int boel)
{
    int rd_y = rand() % 2;
    int rd_sprite = rand() % 2;

    if (rd_y == 0)
        rd_y = 1;
    else if (rd_y == 1)
        rd_y = -1;
    if (boel == 1)
        return rd_y;
    if (rd_sprite == 0)
        sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    else if (rd_sprite == 1)
        sfSprite_setTexture(entity->sprite, entity->texture_white, sfTrue);
    return 0;
}

void entity_isdead_or_save(entity_t *entity)
{
    if (entity->animation.rect.width == 128
    && entity->animation.offset.x <= 30) {
        entity->animation.offset = (sfVector2f)
        {entity->animation.offset.x + 0.4, (rand() % 15) *
        random_respawn(entity, 1)};
    } else if (entity->animation.rect.width == 182
    && entity->animation.offset.x <= 30)
        entity->animation.offset =
        (sfVector2f) {entity->animation.offset.x - 0.4, (rand() % 15) *
        random_respawn(entity, 1)};
    random_respawn(entity, 2);
    sfSprite_setTextureRect(entity->sprite, entity->animation.rect);
    entity->animation.rect = (sfIntRect) {0, 0, 200, 100};
}
