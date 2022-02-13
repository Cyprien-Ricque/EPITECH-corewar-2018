/*
** EPITECH PROJECT, 2019
** main_t
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

int main(int ac, char **av)
{
    int fd;

    if (ac != 2) {
        write(2, "Missing file\n", 13);
        usage(av[0]);
        return (FAILURE);
    }
    if (my_strcmp(av[1], "-h") == true)
        return (usage(av[0]));
    fd = open_file_s(av[1]);
    if (fd < 0)
        return (FAILURE);
    if (main_asm(fd, av[1]) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}