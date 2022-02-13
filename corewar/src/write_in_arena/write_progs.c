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

char put_it(corewar_t *crw)
{
    int pos = crw->tmp->load_address;

    for (size_t i = 0; i < crw->tmp->prog_size; ++i) {
        if (pos >= MEM_SIZE)
            pos = 0;
        if (crw->map[pos])
            return (error("Overlap detected.\n"));
        crw->map[pos] = (unsigned char)crw->tmp->prog[i];
        ++pos;
    }
    return (SUCCESS);
}

void display_map(corewar_t *crw)
{
    for (int i = 0; i < MEM_SIZE; ++i) {
        if (i && (i) % (IDX_MOD / 16) == 0)
            my_puts("\n");
        if ((i) % (IDX_MOD / 16) == 0)
            m_printf(1, "%-4X :", i);
        m_printf(1, " %2X", crw->map[i]);
    }
    my_puts("\n");
}

char write_arena(corewar_t *crw)
{
    int pos[5][2] = {{-2, -2}, {-2, -2}, {-2, -2}, {-2, -2}, {-2, -2}};
    int save[5][2] = {{-2, -2}, {-2, -2}, {-2, -2}, {-2, -2}, {-2, -2}};

    for (int i = 0; i < MEM_SIZE; ++i)
        crw->map[i] = 0;
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next) {
        pos[crw->tmp->registers[0] - 1][0] = crw->tmp->load_address;
        pos[crw->tmp->registers[0] - 1][1] = (int)crw->tmp->prog_size;
        save[crw->tmp->registers[0] - 1][0] = crw->tmp->load_address;
        save[crw->tmp->registers[0] - 1][1] = (int)crw->tmp->prog_size;
    }
    if (find_pos(pos, save) == false)
        return (error("Overlap detected.\n"));
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next)
        crw->tmp->load_address = pos[crw->tmp->registers[0] - 1][0];
    for (crw->tmp = crw->procs_head; crw->tmp; crw->tmp = crw->tmp->next) {
        if (put_it(crw) == FAILURE)
            return (FAILURE);
    }
    return (SUCCESS);
}

char write_in_mem(corewar_t *crw)
{
    if (invalid_prog_number(crw) == FAILURE)
        return (FAILURE);
    if (organize_progs(crw) == FAILURE)
        return (FAILURE);
    if (write_arena(crw) == FAILURE)
        return (FAILURE);

    return (SUCCESS);
}

char write_progs(corewar_t *crw)
{
    if (read_progs(crw) == FAILURE)
        return (FAILURE);
    if (write_in_mem(crw) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}