/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by charles,
*/

#include "corewar.h"
#include <stdlib.h>

int get_bit(int bin)
{
    int val = 0;

    val = bin % 10;
    bin = bin / 10;
    val += (bin % 10) * 10;
    return val;
}

char *separate_bin(int bin, int UNUSED size)
{
    char *bin_array = malloc(sizeof(char) * (5));

    if (!bin_array)
        return NULL;
    for (int i = 0; i < 5; i++)
        bin_array[i] = '\0';
    for (int i = 0; bin > 0; ++i, bin /= 100)
        bin_array[i] = (char)get_bit(bin);
    bin_array[4] = '\0';
    return bin_array;
}

char *my_rev_bin(char *bin)
{
    char tmp;
    int i = 0;

    if (!bin)
        return (NULL);
    while (i < 2) {
        tmp = bin[4 - i - 1];
        bin[4 - i - 1] = bin[i];
        bin[i] = tmp;
        ++i;
    }
    return bin;
}

int get_args(unsigned char *map, int *i, fct_t *function, char byte_code)
{
    char n_arg = nb_args(function->function);
    char *bin_array = my_rev_bin(
        separate_bin(m_getnb(m_retbase((unsigned char)byte_code, 2)), n_arg));

    if (!bin_array)
        return 84;
    get_args_value(function, map, i, bin_array);
    return 0;
}