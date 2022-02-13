/*
** EPITECH PROJECT, 2019
** error_zero
** File description:
** error_zero
*/

#include "lib.h"

char *add_error_zero(char *output)
{
    if (output[0] == '\0') {
        output[0] = '0';
        output[1] = '\0';
    }
    return (output);
}

long long nb_char_int(long long nb)
{
    long long counter = 0;

    while (nb > 0) {
        nb = nb / 10;
        counter++;
    }
    return (counter);
}

long long nb_negative(long long *nb)
{
    if (*nb < 0) {
        *nb = *nb * (-1);
    }
    return (*nb);
}

char nb_negative_ret(long long nb)
{
    if (nb < 0) {
        return (1);
    } else {
        return (0);
    }
}

char *add_minus_to_str(char *output, int nb, long long *nb_char)
{
    if (output == NULL)
        return (NULL);
    if (nb == 0) {
        return (output);
    } else if (nb == 1) {
        output[0] = '-';
        *nb_char += 1;
        return (output);
    }
    return (output);
}
