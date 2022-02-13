/*
** EPITECH PROJECT, 2019
** pars_content_file
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char (*content_asm[4])(main_t *, char *) =
{
    index_check, command_check, params_check, NULL
};

void clear_separators(char *str)
{
    for (int a = 0; str[a]; ++a) {
        if (str[a] == SEPARATOR_CHAR)
            str[a] = ' ';
    }
}

char change_list_settings(content_t **list, head_t *output, bool *first_node)
{
    while ((*list) && (*list)->str[0] == '\0')
        (*list) = (*list)->next;
    if (!(*list))
        return (SUCCESS);
    clear_separators((*list)->str);
    if (create_following_node(first_node, output) == FAILURE)
        return (FAILURE);
    else if (create_first_node(first_node, output) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}

char read_rest_file(content_t **list, head_t *output)
{
    bool first_node = true;
    main_t *current = NULL;

    output->first = NULL;
    output->last = NULL;
    while ((*list)) {
        if (change_list_settings(list, output, &first_node) == FAILURE)
            return (FAILURE);
        current = output->last;
        for (int a = 0; content_asm[a]; ++a) {
            if (!(*list))
                return (SUCCESS);
            if ((content_asm[a])(current, (*list)->str) == FAILURE)
                return (FAILURE);
        }
        (*list) = (*list)->next;
    }
    if (check_errors(output) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}