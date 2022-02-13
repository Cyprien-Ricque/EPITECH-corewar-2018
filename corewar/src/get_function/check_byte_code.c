/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include <corewar.h>

int check_byte_code(fct_t *function, char byte_code)
{
    if (function->function != 1 && function->function != 9 &&
        function->function != 12 && function->function != 15 &&
        byte_code == 0) {
        return FAILURE;
    }
    return SUCCESS;
}

int check_byte(char byte, const char *byte_value)
{
    for (int i = 0; byte_value[i] != '\0'; i++) {
        if (byte == byte_value[i])
            return 0;
    }
    return 1;
}

int check_byte_code_value(const char *byte_code,
    const char byte_code_value[3][4], UNUSED int nb)
{
    for (int i = 0; byte_code[i] != '\0'; i++) {
        if (check_byte(byte_code[i], byte_code_value[i]) == 1)
            return false;
    }
    return true;
}