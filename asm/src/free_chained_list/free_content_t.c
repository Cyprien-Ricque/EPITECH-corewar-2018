/*
** EPITECH PROJECT, 2019
** free_content_t
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include "asm.h"

void free_content_t(content_t first)
{
    content_t *current = first.next;
    content_t *previous;

    while (current) {
        free(current->str);
        previous = current;
        current = current->next;
        free(previous);
    }
}