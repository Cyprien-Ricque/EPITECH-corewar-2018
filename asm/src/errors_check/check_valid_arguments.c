/*
** EPITECH PROJECT, 2019
** check_valid_arguments
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char (*check_commands[17])(main_t *, errors_t *) =
{
    check_live, check_ld, check_st, check_add, check_sub, check_and, check_or,
    check_xor, check_zjmp, check_ldi, check_sti, check_fork, check_lld,
    check_lldi, check_lfork, check_aff, NULL
};

char check_valid_args(main_t *current, errors_t *errors UNUSED)
{
    if (current->command < 0)
        return (SUCCESS);
    if (check_commands[(int)current->command](current, errors) == FAILURE)
        return (FAILURE);
    return (SUCCESS);
}