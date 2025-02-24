/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-enzo.daumalle
** File description:
** swap_and_transfert.c
*/

#include "push_swap.h"

void swap_la(linkedlist_t *l_a)
{
    int swap;

    swap = l_a->data;
    l_a->data = l_a->next->data;
    l_a->next->data = swap;
}

void swap_lb(linkedlist_t *l_b)
{
    int swap;

    swap = l_b->data;
    l_b->data = l_b->next->data;
    l_b->next->data = swap;
}

void swap_lab(linkedlist_t *l_a, linkedlist_t *l_b)
{
    swap_la(l_a);
    swap_lb(l_b);
}

void push_to_la(linkedlist_t **l_a, linkedlist_t **l_b)
{
    linkedlist_t *temp = *l_a;

    if ((*l_b) == NULL)
        return;
    *l_a = *l_b;
    *l_b = (*l_b)->next;
    (*l_a)->next = temp;
}

void push_to_lb(linkedlist_t **l_b, linkedlist_t **l_a)
{
    linkedlist_t *temp = *l_b;

    if (*l_a == NULL)
        return;
    *l_b = *l_a;
    *l_a = (*l_a)->next;
    (*l_b)->next = temp;
}
