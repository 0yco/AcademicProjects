/*
** EPITECH PROJECT, 2021
** B-MUL-100-MPL-1-1-myrunner-enzo.daumalle
** File description:
** add_list.c
*/

#include "my_runner.h"

static void add_null_node(lnk_list_t **head,
lnk_list_t *newNode, object_t *object)
{
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->value = object;
    (*head) = newNode;
}

void add_node(object_t *object, lnk_list_t **head)
{
    lnk_list_t *newNode = malloc(sizeof(lnk_list_t));

    if ((*head) == NULL) {
        add_null_node(head, newNode, object);
        return;
    }
    newNode->prev = (*head);
    (*head)->next = newNode;
    newNode->next = NULL;
    newNode->value = object;
    (*head) = newNode;
}
