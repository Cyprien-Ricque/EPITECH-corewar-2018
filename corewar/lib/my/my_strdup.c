/*
** EPITECH PROJECT, 2019
** my_strdup
** File description:
** my_strdup
*/

#include "lib.h"
#include <stdlib.h>

char *my_strdup(char const *string)
{
    char *output = malloc(sizeof(char) * (my_strlen(string) + 1));
    unsigned int a = 0;

    if (output == NULL)
        return (NULL);
    while (string[a] != '\0') {
        output[a] = string[a];
        ++a;
    }
    output[a] = '\0';
    return (output);
}