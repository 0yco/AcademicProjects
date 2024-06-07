/*
** EPITECH PROJECT, 2022
** Panoramix
** File description:
** villager.c
*/

#include "panoramix.h"

static void drink(panoramix_t *p, long id)
{
    printf("Villager %ld: I need a drink... I see %d servings left.\n", id,
    p->pot);
    if (p->pot > 0)
        p->pot--;
    else {
        printf("Villager %ld: Hey Pano wake up! We need more potion.\n", id);
        sem_post(&p->sem_need_refill);
        sem_wait(&p->sem_druid_sleep);
    }
}

static void fight(long id, int *nb_fights)
{
    (*nb_fights)--;
    printf("Villager %ld: Take that roman scum! Only %d left.\n",
    id, (*nb_fights));
}

void *villager_chargeeee(void *arg)
{
    panoramix_t *p = (panoramix_t *)arg;
    long id = p->id++;
    int nb_fights = p->nb_fights;

    printf("Villager %ld: Going into battle!\n", id);
    while (nb_fights > 0) {
        pthread_mutex_lock(&p->mutex);
        if (p->nb_refills < 1 && p->pot < 1) {
            pthread_mutex_unlock(&p->mutex);
            break;
        }
        drink(p, id);
        fight(id, &nb_fights);
        pthread_mutex_unlock(&p->mutex);
        sleep(0.1);
    }
    printf("Villager %ld: I'm going to sleep now...\n", id);
    return NULL;
}
