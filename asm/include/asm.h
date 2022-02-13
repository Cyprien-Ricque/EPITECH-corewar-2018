/*
** EPITECH PROJECT, 2019
** asm
** File description:
** Created by Emilien Delevoye
*/

#ifndef ASM_ASM_H
#define ASM_ASM_H

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"
#include "op.h"

//MACRO DEFINITION FOR COMMAND REFERENCE

#define LIVE 1
#define LD 2
#define ST 3
#define ADD 4
#define SUB 5
#define AND 6
#define OR 7
#define XOR 8
#define ZJUMP 9
#define LDI 10
#define STI 11
#define FORK 12
#define LLD 13
#define LLDI 14
#define LFORK 15
#define AFF 16

//MACRO DEFINITION FOR INDEX FINDING

#define DIRECT_INDEX_ARG_1 ((cu->arg1 != NULL && cu->arg1[0] == '%' \
&& cu->arg1[1] == ':') || (cu->arg1 != NULL && cu->arg1[0] == ':')) \
&& cu->arg1[0] == '%' && my_strcmp(&cu->arg1[2], str) == true

#define INDIRECT_INDEX_ARG_1 ((cu->arg1 != NULL && cu->arg1[0] == '%' \
&& cu->arg1[1] == ':') || (cu->arg1 != NULL && cu->arg1[0] == ':')) \
&& cu->arg1[0] == ':' && my_strcmp(&cu->arg1[1], str) == true

#define DIRECT_INDEX_ARG_2 ((cu->arg2 != NULL && cu->arg2[0] == '%' \
&& cu->arg2[1] == ':') || (cu->arg2 != NULL && cu->arg2[0] == ':')) \
&& cu->arg2[0] == '%' && my_strcmp(&cu->arg2[2], str) == true

#define INDIRECT_INDEX_ARG_2 ((cu->arg2 != NULL && cu->arg2[0] == '%' \
&& cu->arg2[1] == ':') || (cu->arg2 != NULL && cu->arg2[0] == ':')) \
&& cu->arg2[0] == ':' && my_strcmp(&cu->arg2[1], str) == true

#define DIRECT_INDEX_ARG_3 ((cu->arg3 != NULL && cu->arg3[0] == '%' \
&& cu->arg3[1] == ':') || (cu->arg3 != NULL && cu->arg3[0] == ':')) \
&& cu->arg3[0] == '%' && my_strcmp(&cu->arg3[2], str) == true

#define INDIRECT_INDEX_ARG_3 ((cu->arg3 != NULL && cu->arg3[0] == '%' \
&& cu->arg3[1] == ':') || (cu->arg3 != NULL && cu->arg3[0] == ':')) \
&& cu->arg3[0] == ':' && my_strcmp(&cu->arg3[1], str) == true

//Check errors structures

struct chain_indexes {
    char *str;
    struct chain_indexes *next;
};

struct chain_labels {
    char *str;
    struct chain_labels *next;
};

typedef struct errors_struct {
    struct chain_indexes *first;
    struct chain_indexes *last;
    struct chain_labels *first_l;
    struct chain_labels *last_l;
} errors_t;

//Chained list struct declaration
typedef struct content_s_file {
    char *str;
    struct content_s_file *next;
} content_t;

typedef struct flute {
    char command;
    unsigned char code_byte;
    char *arg1;
    char *arg2;
    char *arg3;
    char *arg4;
    char *index;
    int pos;
    unsigned int index_pos;
    unsigned int call_pos;
    struct flute *next;
    struct flute *prev;
} main_t;

typedef struct content {
    char *file_name;
    header_t header;
    struct flute *first;
    struct flute *last;
} head_t;

//Functions declaration
int usage(char *);
bool read_file(int, content_t *);
int open_file_s(char *);
int main_asm(int, char *);
bool str_in_str(char const *, char const *);

//Functions chained list
char create_first_node(bool *, head_t *);
char create_following_node(bool const *, head_t *);

//Functions parsing
char setup_name(content_t **, head_t *);
char setup_comment(content_t **, head_t *);
char read_rest_file(content_t **, head_t *);
char index_check(main_t *, char *);
char command_check(main_t *, char *);
char params_check(main_t *, char *);

//Write functions
int write_in_cor(head_t *info);
void write_short_and_char(int fd, const char *arg, unsigned char *c_arg,
unsigned short *s_arg);
int write_index_management(int fd, char *arg);
void write_ldi_arg_1(int fd, char *a);
unsigned short ldi_offset_arg1_index(int fd, const head_t *info, unsigned
    short pos, const main_t *cu);
void write_sti_arg3(int fd, char *a);
void write_sti_arg_3_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu);
void write_sti_arg_2_index(int fd, const head_t *info, unsigned short pos,
    const main_t *cu);
void write_register(int fd, char *arg);
void write_xor_or_and_arg2_index(int fd, const head_t *info,
    unsigned short pos, const main_t *cu);
void write_and_arg_1(int fd, char *a);
void write_live_arg_1(int fd, char *arg);
void write_ld_arg_1(int fd, char *a);
void write_ld_or_live_arg1_index(int fd, const head_t *info,
    unsigned short pos, const main_t *cu);
void write_st_arg2(int fd, char *a);
void write_zjump_arg_1(int fd, char *arg);
void write_argument_3(int fd, char cmd, char *arg);
void write_argument_2(int fd, char cmd, char *arg);
void write_argument_1(int fd, char cmd, char *arg);

//Free functions
void free_flute_t(main_t *);
void free_content_t(content_t);

//compute functions
void compute_cb_with_indirect(head_t *info, char *power, main_t *new_node);
void compute_cb_with_direct(head_t *info, char *power, main_t *new_node);
void compute_cb_with_register(head_t *info, char *power, main_t *new_node);
void compute_coding_byte(head_t *info, main_t *cu, char *power);
void compute_cb_with_and_arg_1(head_t *info, char *power, main_t *cu,
    const char *a);
void compute_ld_arg_1(head_t *info, char *power, main_t *cu, const char *a);
void compute_cb_with_sti_arg_2(head_t *info, char *power, main_t *cu,
    const char *a);
void compute_cb_with_ldi_arg_1(head_t *info, char *power, main_t *cu,
    const char *a);
void compute_cb_with_st_arg2(head_t *info, char *power, main_t *cu,
    const char *a);
void compute_cb_with_sti_arg3(head_t *info, char *power, main_t *cu,
    const char *a);

//little endian conversion functions
unsigned int little_to_big_endian_int(int x);
unsigned short little_to_big_endian_short(short x);

//index functions
int add_index_ref(int fd, head_t *info);
void fill_index_ref(int fd, head_t *info, const char *str, unsigned short pos);
int check_index_with_arg(int fd, head_t *info, main_t *cu);

//header and chained list functions for asm
void fill_header(header_t *header);
void get_cor_name(char file_cor[PROG_NAME_LENGTH], char *file_name);
void init_value_of_node(int fd, head_t *info, main_t *cu);

//Check errors functions
char check_errors(head_t *);

//Pointers on functions tab
char check_args_alone(main_t *, errors_t *);
char check_missing_params(main_t *, errors_t *);
char check_valid_args(main_t *, errors_t *);
char check_labels(main_t *, errors_t *);

//Commands functions check
char check_live(main_t *, errors_t *);
char check_add(main_t *, errors_t *);
char check_aff(main_t *, errors_t *);
char check_and(main_t *, errors_t *);
char check_fork(main_t *, errors_t *);
char check_ld(main_t *, errors_t *);
char check_ldi(main_t *, errors_t *);
char check_lfork(main_t *, errors_t *);
char check_lld(main_t *, errors_t *);
char check_lldi(main_t *, errors_t *);
char check_or(main_t *, errors_t *);
char check_st(main_t *, errors_t *);
char check_sti(main_t *, errors_t *);
char check_sub(main_t *, errors_t *);
char check_xor(main_t *, errors_t *);
char check_zjmp(main_t *, errors_t *);

//Check direct indirect and register
bool check_direct(char const *);
bool check_indirect(char const *);
bool check_register(char const *);
bool check_index(char const *);

//Check labels and indexes
char add_index(char *, errors_t *);
char check_validity_indexes(errors_t *);

#endif //ASM_ASM_H
