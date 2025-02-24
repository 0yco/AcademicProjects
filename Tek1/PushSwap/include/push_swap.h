/*
** EPITECH PROJECT, 2021
** B-CPE-110-MPL-1-1-pushswap-enzo.daumalle
** File description:
** push_swap.h
*/

#ifndef __PUSH_SWAP_H__
    #define __PUSH_SWAP_H__
    #include <stdlib.h>
    #include "my.h"

typedef struct linkedlist_s
{
    int data;
    struct linkedlist_s *next;
} linkedlist_t;

typedef struct list_write_s
{
    int len;
    char *str;
} list_write_t;

void swap_elem(int *array, int index1 ,int index2);
void add_node_at_back(int data, linkedlist_t **node);
void add_node_at_front(int data, linkedlist_t **node);
void insert_sort(linkedlist_t **l_a, linkedlist_t **l_b, list_write_t *lw);
void write_ops(list_write_t *lw, const char *src);
void swap_la(linkedlist_t *l_a);
void swap_lb(linkedlist_t *l_b);
void swap_lab(linkedlist_t *l_a, linkedlist_t *l_b);
void push_to_la(linkedlist_t **l_a, linkedlist_t **l_b);
void push_to_lb(linkedlist_t **l_b, linkedlist_t **l_a);
void rotate_la(linkedlist_t **l_a);
void rotate_lb(linkedlist_t **l_b);
void rotate_rot(linkedlist_t **l_a, linkedlist_t **l_b);
void re_rotate_la(linkedlist_t **l_a);
void re_rotate_lb(linkedlist_t **l_b);
void re_rotate_rot(linkedlist_t **l_a, linkedlist_t **l_b);

#endif /* __PUSH_SWAP_H__ */
