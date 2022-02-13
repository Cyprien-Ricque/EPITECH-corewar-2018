/*
** EPITECH PROJECT, 2019
** my_strlen
** File description:
** my_strlen
*/

#include "lib.h"

ssize_t my_strlen(char const *str)
{
    ssize_t counter = 0;

    if (str == NULL)
        return (-1);
    while (str[counter] != '\0')
        ++counter;
    return (counter);
}