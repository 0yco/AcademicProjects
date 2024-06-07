/*
** EPITECH PROJECT, 2022
** B-CCP-400-MPL-4-1-panoramix-enzo.daumalle
** File description:
** main.c
*/

#include "panoramix.h"

int help(void)
{
    printf("USAGE: ./panoramix <nb_villagers> <pot_size>");
    printf(" <nb_fights> <nb_refills>\n");
    return 0;
}

static void manage_threads(panoramix_t *p)
{
    pthread_t *villagers = malloc(sizeof(pthread_t) * p->nb_villagers);
    pthread_t druid;

    pthread_create(&druid, NULL, druid_woooork, (void *)p);
    for (long i = 0; i < p->nb_villagers; i++)
        pthread_create(&villagers[i], NULL, villager_chargeeee, (void *)p);

    pthread_join(druid, NULL);
    for (long i = 0; i < p->nb_villagers; i++)
        pthread_join(villagers[i], NULL);

    free(villagers);
    free(p);
}

int main(int av, char **ac)
{
    panoramix_t *p = NULL;

    if (av == 1)
        return help();
    if (av != 5)
        return 84;
    p = panoramix(atoi(ac[1]), atoi(ac[2]), atoi(ac[3]), atoi(ac[4]));
    if (!p) {
        help();
        printf("Values must be >0.\n");
        return 84;
    }
    manage_threads(p);
    return 0;
}
