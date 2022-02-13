/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include <corewar.h>
#include <zconf.h>

int get_function_name(unsigned char *map, int *i, char *function)
{
    *function = map[*i];
    (*i)++;
    *i %= MEM_SIZE;
    return (0);
}

char get_byte_code(unsigned char *map, int *i)
{
    char byte_code = map[(*i)];

    (*i)++;
    *i %= MEM_SIZE;
    return byte_code;
}

int get_function(fct_t *function, unsigned char map[MEM_SIZE], int i)
{
    char byte_code = 0;

    function->valid = true;
    if (map[i] != 0 && map[i] <= 16) {
        get_function_name(map, &i, &function->function);
        if (function->function != 1 && function->function != 9 &&
            function->function != 12 && function->function != 15) {
            byte_code = get_byte_code(map, &i);
        }
        if (check_byte_code(function, byte_code) == FAILURE) {
            function->valid = false;
            return 0;
        }
        if (get_args(map, &i, function, byte_code) == 84)
            return (84);
    } else
        function->function = 0;
    return (0);
}