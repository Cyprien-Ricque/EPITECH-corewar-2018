/*
** EPITECH PROJECT, 2019
** read_file
** File description:
** Created by Emilien Delevoye
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "asm.h"

int open_file_s(char *path)
{
    int size = my_strlen(path);
    int fd;

    if (!path || size < 3)
        return (-1);
    fd = open(path, O_RDONLY);
    return (fd);
}

void remove_comment(char *str)
{
    for (int a = 0; str[a]; ++a) {
        if (str[a] == '#')
            str[a] = '\0';
    }
}

bool read_file(int fd, content_t *list)
{
    char *read = get_next_line(fd);

    if (!read)
        return (false);
    while (read != NULL) {
        list->str = read;
        remove_comment(list->str);
        read = get_next_line(fd);
        if (!read) {
            list->next = NULL;
        } else {
            list->next = malloc(sizeof(content_t));
            if (!list->next)
                return (false);
            list = list->next;
            list->next = NULL;
        }
    }
    close(fd);
    return (true);
}