/*
** EPITECH PROJECT, 2019
** free_flute_t
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include "asm.h"

void free_content_flute_t(main_t *current)
{
    if (current->arg1)
        free(current->arg1);
    if (current->arg2)
        free(current->arg2);
    if (current->arg3)
        free(current->arg3);
    if (current->arg4)
        free(current->arg4);
    if (current->index)
        free(current->index);
}

void free_flute_t(main_t *current)
{
    while (current) {
        free_content_flute_t(current);
        if (current->prev)
            free(current->prev);
        if (!current->next) {
            free(current);
            break;
        }
        current = current->next;
    }
}