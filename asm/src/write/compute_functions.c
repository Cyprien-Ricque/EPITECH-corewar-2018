/*
** EPITECH PROJECT, 2019
** compute_functions.c
** File description:
** compute function for the asm
*/

#include "asm.h"

int my_compute_power(int nb, int power)
{
    int save_nb = nb;

    power -= 1;
    if (power < 0)
        return (0);
    else if (power == 0)
        return (1);
    else {
        while (power > 0) {
            nb = nb * save_nb;
            power -= 1;
        }
    }
    return (nb);
}

void compute_cb_with_indirect(head_t *info, char *power, main_t *new_node)
{
    info->header.prog_size += 2;
    new_node->code_byte += my_compute_power(2, (*power));
    (*power)--;
    new_node->code_byte += my_compute_power(2, (*power));
    (*power)--;
}

void compute_cb_with_direct(head_t *info, char *power, main_t *new_node)
{
    info->header.prog_size += 4;
    new_node->code_byte += my_compute_power(2, (*power));
    (*power)--;
    (*power)--;
}

void compute_cb_with_register(head_t *info, char *power, main_t *new_node)
{
    info->header.prog_size += 1;
    (*power)--;
    new_node->code_byte += my_compute_power(2, (*power));
    (*power)--;
}