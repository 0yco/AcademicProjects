/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** druid.c
*/

#include "panoramix.h"

void *druid_woooork(void *arg)
{
    panoramix_t *p = (panoramix_t *)arg;

    printf("Druid: I'm ready... but sleepy...\n");
    while (p->nb_refills > 0) {
        sem_wait(&p->sem_need_refill);
        if (p->pot > 0) {
            sem_post(&p->sem_druid_sleep);
            continue;
        }
        p->nb_refills--;
        printf("Druid: Ah! Yes, yes, I'm awake! Working on it!");
        printf(" Beware I can only make %d more refills after this one.\n",
        p->nb_refills);
        p->pot = p->pot_size - 1;
        sem_post(&p->sem_druid_sleep);
    }
    printf("Druid: I'm out of viscum. I'm going back to... zZz\n");
    return NULL;
}
