/*
** EPITECH PROJECT, 2018
** m_slen
** File description:
** m_slen
*/

#include <unistd.h>
#include "lib.h"

int m_arraylen(char **src)
{
    int count = 0;

    if (!src)
        return (-1);
    while (src[count])
        ++count;
    return (count);
}