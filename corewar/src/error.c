/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include "lib.h"

char error(char *error)
{
    write(2, "Error: ", 7);
    write(2, error, (size_t)my_strlen(error));
    return (FAILURE);
}