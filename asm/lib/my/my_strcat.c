/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "lib.h"
#include <stdlib.h>

char *my_strcat(char *str1, char *str2)
{
    char *output;
    size_t counter = 0;

    if (str1 == NULL || str2 == NULL)
        return (NULL);
    output = malloc(sizeof(char) * (my_strlen(str1) + my_strlen(str2) + 1));
    if (output == NULL)
        return (NULL);
    for (size_t a = 0; str1[a] != '\0'; ++a) {
        output[counter] = str1[a];
        ++counter;
    }
    for (size_t a = 0; str2[a] != '\0'; ++a) {
        output[counter] = str2[a];
        ++counter;
    }
    output[counter] = '\0';
    return (output);
}