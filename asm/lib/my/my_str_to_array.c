/*
** EPITECH PROJECT, 2019
** my_str_to_array
** File description:
** my_str_to_array
*/

#include "lib.h"
#include <stdlib.h>

struct str_to_array {
    int pos;
    unsigned int tmp;
};

bool content_array(char *str, char **output, struct str_to_array *cont, int *a)
{
    if (*a == 0 || str[*a] == ' ') {
        output[++(*cont).pos] = malloc((size_of_next_word(str, *a + 1)) + 10);
        if (output[(*cont).pos] == NULL)
            return (false);
        output[(*cont).pos + 1] = NULL;
        (*cont).tmp = 0;
        if (*a != 0)
            ++(*a);
    }
    output[(*cont).pos][(*cont).tmp] = str[*a];
    output[(*cont).pos][++(*cont).tmp] = '\0';
    return (true);
}

char **my_str_to_array(char *str)
{
    char **output = NULL;
    struct str_to_array cont = {.pos = -1, .tmp = 0};

    if (*str == '\0')
        return (NULL);
    str = my_clean_str(str);
    output = malloc(sizeof(char *) * (count_words(str) + 10));
    if (output == NULL)
        return (NULL);
    for (int a = 0; str[a] != '\0'; ++a) {
        if (content_array(str, output, &cont, &a) == false)
            return (NULL);
    }
    return (output);
}