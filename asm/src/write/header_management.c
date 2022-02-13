/*
** EPITECH PROJECT, 2019
** header_mangagement.c
** File description:
** header management for the asm
*/

#include "asm.h"

int check_index_with_arg(int fd, head_t *info, main_t *cu)
{
    char *str;

    str = my_strdup(cu->index);
    if (str == NULL)
        return (FAILURE);
    str[my_strlen(str)] = '\0';
    if (str[my_strlen(str) - 1] == ':')
        str[my_strlen(str) - 1] = '\0';
    if (cu->command > 0 || cu->next == NULL) {
        if (cu->command == 0)
            fill_index_ref(fd, info, str, cu->index_pos + 1);
        else
            fill_index_ref(fd, info, str, cu->index_pos);
    } else {
        cu = cu->next;
        fill_index_ref(fd, info, str, cu->prev->index_pos + 1);
    }
    return (SUCCESS);
}

void fill_header(header_t *header)
{
    int i;

    header->magic = COREWAR_EXEC_MAGIC;
    for (i = 0; header->prog_name[i] != '\0'; i++);
    for (; i <= (PROG_NAME_LENGTH + 1); i++)
        header->prog_name[i] = '\0';
    for (i = 0; header->comment[i] != '\0'; i++);
    for (; i <= (COMMENT_LENGTH + 1); i++)
        header->comment[i] = '\0';
    header->prog_size = 0;
}

int delete_prog_name_folder(char *file_name, int y)
{
    int i;
    int stop = 0;

    for (i = 0; file_name[i] != '\0'; i++) {
        if (file_name[i] == '/')
            stop++;
        if (stop == y) {
            i++;
            break;
        }
    }
    for (y = 0; file_name[i] != '\0'; i++) {
        file_name[y] = file_name[i];
        y++;
    }
    for (; y <= (PROG_NAME_LENGTH + 1); y++)
        file_name[y] = '\0';
    return (0);
}

void get_cor_name(char file_cor[PROG_NAME_LENGTH], char *file_name)
{
    int i;
    int y = 0;

    for (i = 0; file_name[i] != '\0'; i++) {
        if (file_name[i] == '/')
            y++;
    }
    if (y != 0)
        delete_prog_name_folder(file_name, y);
    for (i = 0; file_name[i] != '.' && file_name[i] != '\0'; i++)
        file_cor[i] = file_name[i];
    file_cor[i] = '.';
    file_cor[i + 1] = 'c';
    file_cor[i + 2] = 'o';
    file_cor[i + 3] = 'r';
    file_cor[i + 4] = '\0';
}

void init_value_of_node(int fd, head_t *info, main_t *cu)
{
    cu->code_byte = 0;
    cu->command = cu->command + 1;

    if (cu->command > 0) {
        info->header.prog_size += 1;
        write(fd, &cu->command, sizeof(char));
    }
    if (cu->index != NULL)
        cu->index_pos = info->header.prog_size;
}