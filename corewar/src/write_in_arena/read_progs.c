/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

off_t header_size(proc_t *proc)
{
    off_t size = 0;
    char buf[PROG_NAME_LENGTH + 1];

    size += sizeof(int);
    lseek(proc->fd, size, SEEK_SET);
    if (read(proc->fd, buf, PROG_NAME_LENGTH + 1) != PROG_NAME_LENGTH + 1)
        return (-1);
    proc->name = my_strdup((const char *)buf);
    if (!proc->name)
        return (-1);
    size += PROG_NAME_LENGTH + 4;
    lseek(proc->fd, size, SEEK_SET);
    if (read(proc->fd, buf, sizeof(int)) != sizeof(int))
        return (-1);
    proc->prog_size = (size_t)octect_to_dec(buf, 4);
    size += sizeof(int);
    size += COMMENT_LENGTH + 4;
    return (size);
}

char read_progs(corewar_t *crw)
{
    off_t header;

    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next) {
        header = header_size(crw->tmp);
        if (header == -1)
            return (error("Invalid header.\n"));
        lseek(crw->tmp->fd, header, SEEK_SET);
        crw->tmp->prog = malloc(crw->tmp->prog_size + 1);
        if (!crw->tmp->prog)
            return (error("Malloc error.\n"));
        if (read(crw->tmp->fd, crw->tmp->prog, crw->tmp->prog_size) !=
            (ssize_t)crw->tmp->prog_size)
            return (error("Invalid header.\n"));
        crw->tmp->prog[crw->tmp->prog_size] = 0;
    }
    return (SUCCESS);
}