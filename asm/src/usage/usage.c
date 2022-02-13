/*
** EPITECH PROJECT, 2019
** usage
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

int usage(char *av)
{
    my_puts("USAGE\n\t");
    my_puts(av);
    my_puts(" file_name[.s]\n\nDESCRIPTION\n\tfile_name\tfile " \
        "in assembly language to be converted into file_name.cor, an " \
        "executable in the Virtual Machine.\n");
    return (SUCCESS);
}
