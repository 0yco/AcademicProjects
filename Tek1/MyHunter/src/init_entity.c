/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myhunter-enzo.daumalle
** File description:
** init_entity.c
*/

#include "../include/my_hunter.h"

static void create_sound(entity_t *entity)
{
    entity->animation.sound_death =
    sfMusic_createFromFile("sounds/death.ogg");
    entity->animation.sound_bless =
    sfMusic_createFromFile("sounds/dbz-teleport.ogg");
    sfMusic_setVolume(entity->animation.sound_bless, 30);
    sfMusic_setVolume(entity->animation.sound_death, 300);
}

entity_t *create_entity(sfIntRect rect, sfVector2f pos,
char *img, game_t *game)
{
    entity_t *entity;

    entity = malloc(sizeof(struct entity));
    entity->pos = pos;
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    entity->animation.clock = sfClock_create();
    entity->animation.clock_db = sfClock_create();
    entity->texture = sfTexture_createFromFile(img, NULL);
    entity->texture_white = sfTexture_createFromFile("img/enemy.png", NULL);
    entity->texture_bless = sfTexture_createFromFile("img/blessing.png", NULL);
    entity->texture_death = sfTexture_createFromFile("img/death.png", NULL);
    entity->sprite = sfSprite_create();
    create_sound(entity);
    sfSprite_setPosition(entity->sprite, pos);
    sfSprite_setTexture(entity->sprite, entity->texture, sfTrue);
    entity->animation.offset = (sfVector2f) {7, 1};
    entity->animation.rect = rect;
    sfSprite_setTextureRect(entity->sprite, entity->animation.rect);
    sfSprite_setScale(entity->sprite, (sfVector2f) {-1, 1});
    return entity;
}

void destroy_entity(entity_t *entity)
{
    sfSprite_destroy(entity->sprite);
    sfTexture_destroy(entity->texture);
    sfTexture_destroy(entity->texture_white);
    sfMusic_destroy(entity->animation.sound_death);
    sfMusic_destroy(entity->animation.sound_bless);
    free(entity);
}
