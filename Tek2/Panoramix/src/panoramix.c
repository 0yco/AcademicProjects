/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** panoramix.c
*/

#include "panoramix.h"

panoramix_t *panoramix(int nb_villagers, int pot_size,
int nb_fights, int nb_refills)
{
    panoramix_t *p = NULL;

    if (nb_villagers <= 0 || pot_size <= 0 ||
        nb_fights <= 0 || nb_refills <= 0)
        return NULL;
    p = malloc(sizeof(panoramix_t));
    p->nb_villagers = nb_villagers;
    p->pot = pot_size;
    p->pot_size = pot_size;
    p->nb_fights = nb_fights;
    p->nb_refills = nb_refills;
    p->id = 0;
    pthread_mutex_init(&p->mutex, NULL);
    sem_init(&p->sem_need_refill, 0, 0);
    sem_init(&p->sem_druid_sleep, 0, 0);
    return p;
}
