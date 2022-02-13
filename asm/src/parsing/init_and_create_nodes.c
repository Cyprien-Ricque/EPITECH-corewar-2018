/*
** EPITECH PROJECT, 2019
** init_and_create_nodes
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include "asm.h"

void init_chained_list_cont(main_t *current)
{
    current->command = -1;
    current->code_byte = -1;
    current->pos = -1;
    current->arg1 = NULL;
    current->arg2 = NULL;
    current->arg3 = NULL;
    current->arg4 = NULL;
    current->index = NULL;
}

char create_following_node(bool const *first, head_t *output)
{
    main_t *new_node;

    if (*first == true)
        return (SUCCESS);
    new_node = malloc(sizeof(main_t));
    if (!new_node)
        return (FAILURE);
    output->last->next = new_node;
    new_node->prev = output->last;
    output->last = new_node;
    new_node->next = NULL;
    init_chained_list_cont(new_node);
    return (SUCCESS);
}

char create_first_node(bool *first, head_t *output)
{
    main_t *new_node;

    if (*first == false)
        return (SUCCESS);
    new_node = malloc(sizeof(main_t));
    if (!new_node)
        return (FAILURE);
    output->first = new_node;
    output->last = new_node;
    new_node->next = NULL;
    new_node->prev = NULL;
    init_chained_list_cont(new_node);
    *first = false;
    return (SUCCESS);
}
