/*
** EPITECH PROJECT, 2019
** index
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

bool char_in_str(char to_check, char const *str)
{
    if (to_check == LABEL_CHAR)
        return (true);
    for (int a = 0; str[a] != '\0'; ++a) {
        if (to_check == str[a])
            return (true);
    }
    return (false);
}

char setup_index(main_t *current, char *str)
{
    current->index = my_strdup(str);
    if (!current->index)
        return (FAILURE);
    for (int a = 0; current->index[a]; ++a) {
        move_str(str, 0);
        if (current->index[a] == ' ' || current->index[a] == '\t') {
            current->index[a] = '\0';
            break;
        }
    }
    return (SUCCESS);
}

char index_check(main_t *current, char *str)
{
    int a = 0;

    str = my_clean_str_begin(str);
    while (str[a] && str[a] != ' ' && str[a] != '\t' && str[a] != '\n'
        && char_in_str(str[a], LABEL_CHARS) == true) {
        if (str[a] == LABEL_CHAR &&
            (str[a + 1] == ' ' || str[a + 1] == '\t' || str[a] != '\n'))
            return (setup_index(current, str));
        ++a;
    }
    return (SUCCESS);
}
