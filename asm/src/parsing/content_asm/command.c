/*
** EPITECH PROJECT, 2019
** command
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

extern op_t const op_tab[];

void remove_command(char *str)
{
    while (str[0] && str[0] != ' ' && str[0] != '\t')
        move_str(str, 0);
    if (str[0])
        move_str(str, 0);
}

char command_check(main_t *current, char *str)
{
    int size;

    str = my_clean_str(str);
    for (int a = 0; op_tab[a].mnemonique; ++a) {
        size = my_strlen(op_tab[a].mnemonique);
        if (my_strcmp_begin(str, op_tab[a].mnemonique) == true &&
            (str[size] == '\0' || str[size] == ' ' || str[size] == '\t')) {
            current->command = a;
            remove_command(str);
            return (SUCCESS);
        }
    }
    return (SUCCESS);
}
