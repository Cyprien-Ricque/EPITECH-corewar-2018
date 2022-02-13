/*
** EPITECH PROJECT, 2019
** check_labels
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char label_first_node(errors_t *err, char *str, bool *status)
{
    err->first_l = malloc(sizeof(struct chain_indexes));
    if (!err->first_l)
        return (FAILURE);
    err->last_l = err->first_l;
    err->last_l->str = str;
    err->last_l->next = NULL;
    *status = true;
    return (SUCCESS);
}

char label_other_nodes(errors_t *err, char *str)
{
    err->last_l->next = malloc(sizeof(struct chain_indexes));
    if (!err->last_l->next)
        return (FAILURE);
    err->last_l = err->last_l->next;
    err->last_l->next = NULL;
    err->last_l->str = str;
    return (SUCCESS);
}

char add_label(char *arg, errors_t *err)
{
    static bool status = false;

    for (int a = 0; arg[a]; ++a) {
        if (arg[a] == ':')
            arg[a] = '\0';
    }
    if (status == false) {
        if (label_first_node(err, arg, &status) == FAILURE)
            return (FAILURE);
    } else {
        if (label_other_nodes(err, arg) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}

char check_validity_indexes(errors_t *errors)
{
    struct chain_indexes *index = errors->first;
    struct chain_labels *labels;
    bool status;

    while (index) {
        status = false;
        labels = errors->first_l;
        while (labels) {
            if (my_strcmp(labels->str, index->str) == true)
                status = true;
            labels = labels->next;
        }
        if (status == false)
            return (FAILURE);
        index = index->next;
    }
    return (SUCCESS);
}

char check_labels(main_t *current, errors_t *errors)
{
    if (current->arg1)
        if (add_index(current->arg1, errors) == FAILURE)
            return (FAILURE);
    if (current->arg2)
        if (add_index(current->arg2, errors) == FAILURE)
            return (FAILURE);
    if (current->arg3)
        if (add_index(current->arg3, errors) == FAILURE)
            return (FAILURE);
    if (current->arg4)
        if (add_index(current->arg4, errors) == FAILURE)
            return (FAILURE);
    if (current->index)
        if (add_label(current->index, errors) == FAILURE)
            return (FAILURE);
    return (SUCCESS);
}