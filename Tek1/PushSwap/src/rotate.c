/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-enzo.daumalle
** File description:
** rotate.c
*/

#include "push_swap.h"

void rotate_la(linkedlist_t **l_a)
{
    linkedlist_t *temp = *l_a;
    linkedlist_t *lastNode;

    if (l_a == NULL || (*l_a)->next == NULL)
        return;
    *l_a = (*l_a)->next;
    temp->next = NULL;
    lastNode = *l_a;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = temp;
}

void rotate_lb(linkedlist_t **l_b)
{
    linkedlist_t *temp = *l_b;
    linkedlist_t *lastNode;

    if (l_b == NULL || (*l_b)->next == NULL)
        return;
    *l_b = (*l_b)->next;
    temp->next = NULL;
    lastNode = *l_b;
    while (lastNode->next != NULL)
        lastNode = lastNode->next;
    lastNode->next = temp;
}

void rotate_rot(linkedlist_t **l_a, linkedlist_t **l_b)
{
    rotate_la(l_a);
    rotate_lb(l_b);
}
