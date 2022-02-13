/*
** EPITECH PROJECT, 2019
** base_check_errors
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char (*functions_error[5])(main_t *, errors_t *) =
{
    check_args_alone, check_missing_params, check_valid_args, check_labels,
    NULL
};

char check_errors(head_t *output)
{
    main_t *current;
    errors_t errors = {NULL, NULL, NULL, NULL};

    if (!output)
        return (FAILURE);
    current = output->first;
    if (!current && (output->header.comment[0] == '\0' ||
        output->header.prog_name[0] == '\0'))
        return (FAILURE);
    while (current) {
        for (int a = 0; functions_error[a]; ++a) {
            if (functions_error[a](current, &errors) == FAILURE)
                return (FAILURE);
        }
        current = current->next;
    }
    if (check_validity_indexes(&errors) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}