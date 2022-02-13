/*
** EPITECH PROJECT, 2019
** my_str_to_array_funct
** File description:
** my_str_to_array_funct
*/

#include "lib.h"

size_t size_of_next_word(char const *str, int pos)
{
    size_t counter = 0;

    while (str[pos] != ' ' && str[pos] != '\0') {
        ++counter;
        ++pos;
    }
    return (counter);
}

int count_words(char const *str)
{
    int counter = 1;

    for (int a = 0; str[a] != '\0'; ++a) {
        if (str[a] == ' ')
            ++counter;
    }
    return (counter);
}

void move_str(char *str, int a)
{
    while (str[a] != '\0' && str[a + 1] != '\0') {
        str[a] = str[a + 1];
        ++a;
    }
    str[a] = '\0';
}

char *remove_spaces_end(char *str)
{
    for (int a = 0; str[a] != '\0'; ++a) {
        if ((str[a] == ' ' || str[a] == '\t') && str[a + 1] == '\0') {
            str[a] = '\0';
        } else if ((str[a] == ' ' || str[a] == '\t') &&
            (str[a + 1] == '\n' && str[a + 2] == '\0')) {
            str[a] = '\n';
            str[a + 1] = '\0';
        }
    }
    for (int a = 0; str[a] != '\0'; ++a) {
        if (str[a] == '\t')
            str[a] = ' ';
    }
    return (str);
}