/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-enzo.daumalle
** File description:
** cross_rotate.c
*/

#include "push_swap.h"

void re_rotate_la(linkedlist_t **l_a)
{
    linkedlist_t *previous = NULL;
    linkedlist_t *temp = *l_a;

    if (*l_a == NULL)
        return;
    if (temp->next) {
        previous = temp;
        temp = temp->next;
    } else  {
        *l_a = NULL;
        return;
    }
    while (temp->next) {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    add_node_at_front(temp->data, l_a);
}

void re_rotate_lb(linkedlist_t **l_b)
{
    linkedlist_t *previous = NULL;
    linkedlist_t *temp = *l_b;

    if (*l_b == NULL)
        return;
    if (temp->next) {
        previous = temp;
        temp = temp->next;
    } else {
        *l_b = NULL;
        return;
    }
    while (temp->next) {
        previous = temp;
        temp = temp->next;
    }
    previous->next = NULL;
    add_node_at_front(temp->data, l_b);
}

void re_rotate_rot(linkedlist_t **l_a, linkedlist_t **l_b)
{
    re_rotate_la(l_a);
    re_rotate_lb(l_b);
}
