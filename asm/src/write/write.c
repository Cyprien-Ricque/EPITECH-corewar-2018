/*
** EPITECH PROJECT, 2019
** write_in_file.c
** File description:
** write in file.cor
*/

#include "asm.h"

void write_register(int fd, char *arg)
{
    unsigned char c_arg;

    c_arg = (unsigned char)my_atoi(&arg[1]);
    write(fd, &c_arg, sizeof(unsigned char));
}

void write_zjump_arg_1(int fd, char *arg)
{
    unsigned short s_arg = 0;

    if (arg[0] == '%' && ((arg[1] >= '0' && arg[1] <= '9') || arg[1] == '-'))
        s_arg = little_to_big_endian_short((unsigned short)my_atoi(&arg[1]));
    else if (arg[0] == '%' && arg[1] ==':')
        s_arg = little_to_big_endian_short((unsigned short)my_atoi(&arg[2]));
    write(fd, &s_arg, sizeof(unsigned short));
}

void writing_of_arguments(int fd, const main_t *cu)
{
    if (cu->arg1 != NULL)
        write_argument_1(fd, cu->command, cu->arg1);
    if (cu->arg2 != NULL)
        write_argument_2(fd, cu->command, cu->arg2);
    if (cu->arg3 != NULL)
        write_argument_3(fd, cu->command, cu->arg3);
}

void write_loop(int fd, head_t *info)
{
    main_t *cu = info->first;
    char power;

    for (power = 7; cu != NULL; power = 7) {
        init_value_of_node(fd, info, cu);
        compute_coding_byte(info, cu, &power);
        if (cu->command == LIVE || cu->command == ZJUMP || cu->command
        == FORK || cu->command == LFORK)
            cu->code_byte = 0;
        if (cu->code_byte > 0) {
            info->header.prog_size += 1;
            write(fd, &cu->code_byte, sizeof(char));
        }
        writing_of_arguments(fd, cu);
        cu = cu->next;
    }
}

int write_in_cor(head_t *info)
{
    char file_cor[PROG_NAME_LENGTH];
    int fd;

    fill_header(&info->header);
    get_cor_name(file_cor, info->file_name);
    fd = open(file_cor, O_CREAT | O_WRONLY | O_TRUNC, 0644);
    if (fd == -1)
        return (FAILURE);
    info->header.magic = little_to_big_endian_int(info->header.magic);
    write(fd, &info->header, sizeof(header_t));
    write_loop(fd, info);
    lseek(fd, 0, 0);
    info->header.prog_size = little_to_big_endian_int(info->header.prog_size);
    write(fd, &info->header, sizeof(header_t));
    if (add_index_ref(fd, info) == FAILURE)
        return (FAILURE);
    lseek(fd, 0, 0);
    close(fd);
    return (SUCCESS);
}