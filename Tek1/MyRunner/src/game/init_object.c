/*
** EPITECH PROJECT, 2022
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** init_object.c
*/

#include "my_runner.h"

static void create_sound(object_t *object)
{
    object->animation.sound = sfMusic_createFromFile("assets/sounds/jump.ogg");
    sfMusic_setVolume(object->animation.sound, 120);
}

static void create_character(object_t *object)
{
    sfSprite_setScale(object->sprite, (sfVector2f) {0.6, 0.6});
    object->animation.offset = (sfVector2f) {220, 275};
    object->animation.gravity = 0.6;
    object->animation.clock = sfClock_create();
    object->animation.clock_slide = sfClock_create();
    create_sound(object);
}

static void set_value_object(object_t *object, utils_t utils)
{
    object->texture = sfTexture_createFromFile(utils.path, NULL);
    object->sprite = sfSprite_create();
    object->utils.rect = utils.rect;
    object->utils.o_pos = utils.o_pos;
    object->utils.id = utils.id;
    object->animation.state = WALK;
    object->animation.isstate = 0;
}

void create_object(utils_t utils, lnk_list_t **list)
{
    object_t *object = malloc(sizeof(object_t));

    set_value_object(object, utils);
    sfSprite_setPosition(object->sprite, object->utils.o_pos);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, object->utils.rect);
    if (object->utils.rect.width == 80)
        sfSprite_setScale(object->sprite, (sfVector2f) {-2, 2});
    if (object->utils.id == BG || object->utils.id == MG)
        sfTexture_setRepeated(object->texture, sfTrue);
    if (object->utils.id == CHR)
        create_character(object);
    else if (object->utils.id == LIFE)
        sfSprite_scale(object->sprite, (sfVector2f) {0.5, 0.5});
    add_node(object, list);
}
