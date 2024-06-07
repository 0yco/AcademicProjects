/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-enzo.daumalle
** File description:
** panoramix.h
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <pthread.h>
#include <semaphore.h>

void *villager_chargeeee(void *arg);
void *druid_woooork(void *arg);

typedef struct panoramix_s {
    int nb_villagers;
    int pot;
    int pot_size;
    int nb_fights;
    int nb_refills;
    long id;
    pthread_mutex_t mutex;
    sem_t sem_need_refill;
    sem_t sem_druid_sleep;
} panoramix_t;
panoramix_t *panoramix(int nb_villagers, int pot_size,
int nb_fights, int nb_refills);
