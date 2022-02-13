/*
** EPITECH PROJECT, 2019
** setup_name_comment
** File description:
** Created by Emilien Delevoye
*/

#include "asm.h"

char setup_name(content_t **list, head_t *output)
{
    char *line;

    while ((*list) && (*list)->str[0] == '\0')
        (*list) = (*list)->next;
    line = (*list)->str;
    line = my_clean_str(line);
    if (my_strcmp_begin(line, my_strcat(NAME_CMD_STRING, " \"")) == false ||
        my_strcmp_end(line + my_strlen(NAME_CMD_STRING) + 1, "\"") == false) {
        write(2, "Name, Invalid or missing instruction.\n", 38);
        return (FAILURE);
    } else {
        if (my_strcpy_max(output->header.prog_name, line +
            my_strlen(NAME_CMD_STRING) + 2, PROG_NAME_LENGTH,
            "Name too long.\n") == FAILURE)
            return (FAILURE);
    }
    (*list) = (*list)->next;
    return (SUCCESS);
}

char setup_comment(content_t **list, head_t *output)
{
    char *line;

    while ((*list) && (*list)->str[0] == '\0')
        (*list) = (*list)->next;
    if (!(*list))
        return (FAILURE);
    line = my_clean_str((*list)->str);
    if (!my_strcmp_begin(line, my_strcat(COMMENT_CMD_STRING, " \"")) ||
        !my_strcmp_end(line + my_strlen(COMMENT_CMD_STRING) + 1, "\"")) {
        write(2, "Missing comment\n", 26);
        output->header.comment[0] = '\0';
        return (FAILURE);
    } else {
        if (my_strcpy_max(output->header.comment, line +
            my_strlen(COMMENT_CMD_STRING) + 2, COMMENT_LENGTH,
            "Comment too long.\n") == FAILURE)
            return (FAILURE);
    }
    (*list) = (*list)->next;
    return (SUCCESS);
}