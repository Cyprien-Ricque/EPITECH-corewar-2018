/*
** EPITECH PROJECT, 2019
** my_arraylen
** File description:
** my_arraylen
*/

#include "lib.h"

ssize_t my_arraylen(char **array)
{
    ssize_t counter = 0;

    if (array == NULL || array[0] == NULL)
        return (-1);
    while (array[counter] != NULL)
        ++counter;
    return (counter);
}