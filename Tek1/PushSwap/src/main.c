/*
** EPITECH PROJECT, 2021
** Pushswap
** File description:
** main.c
*/

#include "push_swap.h"

static int check_sorted(linkedlist_t *list)
{
    if (list == NULL || list->next == NULL)
        return 1;
    while (list->next) {
        if (list->data > list->next->data)
            return 0;
        list = list->next;
    }
    return 1;
}

static void push_swap(linkedlist_t *list_a,
linkedlist_t *list_b, list_write_t *lw)
{
    lw->len = 0;
    while (list_a) {
        insert_sort(&list_a, &list_b, lw);
    }
    while (list_b->next) {
        push_to_la(&list_a, &list_b);
        write_ops(lw, "pa ");
    }
    push_to_la(&list_a, &list_b);
    write_ops(lw, "pa\n");
}

int main(int argc, char *argv[])
{
    linkedlist_t *list_a = NULL;
    linkedlist_t *list_b = NULL;
    list_write_t *lw = malloc(sizeof(list_write_t));

    lw->str = malloc(sizeof(char) * 100000000);
    if (argc < 2)
        return 84;
    for (int i = 1; i < argc; i++)
        add_node_at_back(my_getnbr(argv[i]), &list_a);
    if (check_sorted(list_a)) {
        my_putchar('\n');
        return 0;
    }
    push_swap(list_a, list_b, lw);
    my_putstr(lw->str);
    return 0;
}
