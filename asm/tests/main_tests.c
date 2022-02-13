/*
** EPITECH PROJECT, 2019
** main_tests
** File description:
** main_tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "asm.h"

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
}

Test(Check_usage, Usage_output_check, .init=redirect_all_stdout)
{
    usage("./asm");
    cr_assert_stdout_eq_str("USAGE\n\t./asm file_name[.s]\n\nDESCRIPTION\n\t" \
        "file_name\tfile in assembly language to be converted into " \
        "file_name.cor, an executable in the Virtual Machine.\n", "");
}

Test(Read_file_check, Function_check)
{
    content_t list;
    int fd = open("tests/main_tests.c", O_RDONLY);

    cr_assert_eq(read_file(-1, &list), false, "Salut");
    cr_assert_eq(read_file(fd, &list), true, "Pourquoi faire ?");
    cr_assert(-1);
    open_file_s("oui");
    cr_assert_neq(open_file_s("tests/main_tests.c"), -1);
    cr_assert_eq(open_file_s("ui"), -1);
}

Test(Check_chained_list, first_checks)
{
    bool status = false;
    head_t output;

    cr_assert_eq(create_first_node(&status, &output), 0);
    cr_assert_eq(create_first_node(&status, &output), 0);
    cr_assert_eq(create_following_node(&status, &output), 0);
}