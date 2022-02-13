/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** main
*/

#include "corewar.h"

int main(int UNUSED ac, char **av)
{
    if (corewar(av) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}