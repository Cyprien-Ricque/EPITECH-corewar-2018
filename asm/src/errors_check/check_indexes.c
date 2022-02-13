/*
** EPITECH PROJECT, 2019
** check_indexes
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char index_first_node(errors_t *err, char *str, bool *status)
{
    err->first = malloc(sizeof(struct chain_indexes));
    if (!err->first)
        return (FAILURE);
    err->last = err->first;
    err->last->str = str;
    err->last->next = NULL;
    *status = true;
    return (SUCCESS);
}

char index_other_nodes(errors_t *err, char *str)
{
    err->last->next = malloc(sizeof(struct chain_indexes));
    if (!err->last->next)
        return (FAILURE);
    err->last = err->last->next;
    err->last->next = NULL;
    err->last->str = str;
    return (SUCCESS);
}

char add_index(char *arg, errors_t *err)
{
    static bool status = false;
    char *str;

    if (arg[0] && arg[1] && arg[2] && arg[0] == '%' && arg[1] == ':')
        str = arg + 2;
    else
        return (SUCCESS);
    if (status == false)
        return (index_first_node(err, str, &status));
    else
        return (index_other_nodes(err, str));
}