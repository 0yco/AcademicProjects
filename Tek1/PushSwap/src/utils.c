/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-enzo.daumalle
** File description:
** utils.c
*/

#include "push_swap.h"

void write_ops(list_write_t *lw, const char *src)
{
    int i;

    for (i = 0; src[i]; i++)
        lw->str[lw->len + i] = src[i];
    lw->str[lw->len + i] = '\0';
    if (lw->len >= 99999900) {
        lw->len = 0;
        my_putstr(lw->str);
    }
    lw->len += 3;
}

void insert_sort(linkedlist_t **l_a, linkedlist_t **l_b, list_write_t *lw)
{
    linkedlist_t *temp = *l_a;
    int indexl = 0;
    int index = 0;
    int lnbr = temp->data;

    while (temp->next) {
        temp = temp->next;
        index++;
        if (temp->data < lnbr) {
            lnbr = temp->data;
            indexl = index;
        }
    }
    for (int i = 0; i < indexl; i++) {
        rotate_la(l_a);
        write_ops(lw, "ra ");
    }
    push_to_lb(l_b, l_a);
    write_ops(lw, "pb ");
}

void add_node_at_back(int data, linkedlist_t **node)
{
    linkedlist_t *newNode = malloc(sizeof(linkedlist_t));

    newNode->data = data;
    newNode->next = NULL;
    if (*node == NULL)
        *node = newNode;
    else {
        linkedlist_t *lastNode = *node;

        while (lastNode->next != NULL)
            lastNode = lastNode->next;
        lastNode->next = newNode;
    }
}

void add_node_at_front(int data, linkedlist_t **node)
{
    linkedlist_t *newNode = malloc(sizeof(linkedlist_t));

    newNode->data = data;
    newNode->next = *node;
    *node = newNode;
}
