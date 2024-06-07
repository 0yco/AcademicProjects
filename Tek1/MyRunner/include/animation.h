/*
** EPITECH PROJECT, 2021
** My Runner
** File description:
** animation.h
*/

#ifndef ANIMATION_H_
    #define ANIMATION_H_
    #define WALK  0
    #define JUMP  1
    #define SLIDE 2

typedef struct animation {
    sfClock *clock;
    sfTime time;
    float seconds;
    sfVector2f offset;
    sfVector2f velocity;
    int state;
    int isstate;
    float gravity;
    sfClock *clock_slide;
    sfMusic *sound;
} animation_t;

#endif /* ANIMATION_H_ */
