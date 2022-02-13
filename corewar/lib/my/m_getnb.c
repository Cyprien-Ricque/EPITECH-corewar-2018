/*
** EPITECH PROJECT, 2018
** my_getnbr
** File description:
** my_getnbr
*/

#include <stdlib.h>
#include "lib.h"

int m_getnb(char const *str)
{
    int nb = 0;
    int neg = 1;

    if (!str)
        return (84);
    for (int i = 0; str[i] != '\0' && ((str[i] <= '9' && str[i] >= '0') ||
        (str[i] == '-' || str[i] == '+')); ++i) {
        neg *= (str[i] == '-') ? -1 : 1;
        nb = str[i] >= '0' && str[i] <= '9' ? nb * 10 + str[i] - 48 : nb;
    }
    return (nb * neg);
}

int octect_to_dec(char *str, int size)
{
    int nb = 0;
    long max = 256;

    for (int i = 0; i < size; ++i) {
        nb *= 256;
        nb += (unsigned char)str[i];
        max *= i + 1 < size ? max : 1;
    }
    if (nb >= max / 2)
        nb -= max;
    return (nb);
}