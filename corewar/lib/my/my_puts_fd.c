/*
** EPITECH PROJECT, 2019
** my_puts_fd
** File description:
** my_puts_fd
*/

#include "lib.h"
#include <unistd.h>

void my_puts_fd(char const *str, int fd)
{
    if (str == NULL || fd < 0)
        return;
    write(fd, str, (size_t)my_strlen(str));
}