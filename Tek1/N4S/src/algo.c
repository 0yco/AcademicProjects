/*
** EPITECH PROJECT, 2022
** LIB NAPI
** File description:
** getRay.c
*/

#include "n4s.h"

void algo_right(algo_t *algo)
{
    if (algo->right < 350) {
        algo->speed = 0.35;
        algo->alpha += 0.1;
    }
    if (algo->right < 300) {
        algo->speed = 0.35;
        algo->alpha += 0.2;
    }
    if (algo->right < 200)
        algo->alpha += 0.08;
    if (algo->right < 100)
        algo->alpha += 0.2;
}

void algo_left(algo_t *algo)
{
    if (algo->left < 350) {
        algo->speed -= 0.35;
        algo->alpha = -0.1;
    }
    if (algo->left < 300) {
        algo->speed = 0.35;
        algo->alpha -= 0.2;
    }
    if (algo->left < 200)
        algo->alpha -= 0.08;
    if (algo->left < 100)
        algo->alpha -= 0.2;
}

void exec_n4s(algo_t *algo)
{
    size_t len = 0;
    char *line = NULL;

    printf("WHEELS_DIR:%f\n", algo->alpha);
    fflush(stdout);
    limit_value(algo);
    sleep(0.05);
    if (getline(&line, &len, stdin) == -1)
        fprintf(stderr, "Error getline\n");
    if (algo->speed < 0) {
        printf("CAR_BACKWARDS:%f\n", -algo->speed);
    } else
        printf("CAR_FORWARD:%f\n", algo->speed);
    fflush(stdout);
    sleep(0.05);
    if (getline(&line, &len, stdin) == -1)
        fprintf(stderr, "Error getline\n");
}

void algo2(algo_t *algo)
{
    if (algo->left < 600 && algo->right < 600 && algo->middle > 400)
        algo->alpha = 0;
    if (algo->right < 120 && algo->left > 120) {
        algo->speed = -0.3;
        algo->alpha = -0.4;
    }
    if (algo->left < 120 && algo->right > 120) {
        algo->speed = -0.3;
        algo->alpha = 0.4;
    }
    exec_n4s(algo);
}

void algo(algo_t *algo, char **rays)
{
    if (!update_info(algo, rays))
        return;
    algo->speed = 0.5;
    if (algo->middle < 450) {
        algo->speed -= 0.25;
        if (algo->middle < 300)
            algo->speed -= 0.2;
    }
    if (algo->left < 450) {
        algo->speed = 0.4;
        algo->alpha = 0.03;
        algo_left(algo);
    } else if (algo->right < 450) {
        algo->speed = 0.4;
        algo->alpha = 0.03;
        algo_right(algo);
    }
    algo2(algo);
}
