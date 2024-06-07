/*
** EPITECH PROJECT, 2021
** BS My Hunter
** File description:
** animation.h
*/


#ifndef ANIMATION_H_
    #define ANIMATION_H_

typedef struct animation {
    sfIntRect rect;
    sfClock *clock;
    sfClock *clock_db;
    sfTime time;
    sfMusic *sound_death;
    sfMusic *sound_bless;
    float seconds;
    sfVector2f offset;
    int max_value;
} animation_t;

#endif /* ANIMATION_H_ */
