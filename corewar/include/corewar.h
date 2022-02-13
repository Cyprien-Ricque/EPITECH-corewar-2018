/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** Created by Emilien Delevoye
*/

#ifndef COREWAR_COREWAR_H
#define COREWAR_COREWAR_H

/** INCLUDES **/

#include "lib.h"
#include "op.h"

/** DEFINES **/

#define MAX_PARAMS 3
#define DIRECT_SIZE 4
#define INDIRECT_SIZE 2
#define REGISTER_SIZE 1

/** STRUCTURES **/

typedef struct params {
    char type;
    char size;
    char value[4];
} prm_t;

typedef struct function {
    char function;
    bool valid;
    prm_t params[MAX_PARAMS];
} fct_t;

typedef struct proc {
    int registers[REG_NUMBER];
    int pc;
    char carry;
    int load_address;
    char *name;
    int fd;
    int prog_nb;
    struct proc *next;
    char *prog;
    size_t prog_size;
    int *cycle_live;
    bool origin;
    ssize_t wait;
} proc_t;

typedef struct corewar {
    long nbr_cycle;
    int cycle;
    int cycle_to_die;
    proc_t *procs_head;
    proc_t *tmp;
    unsigned char map[MEM_SIZE];
    int live_done;
} corewar_t;

/** FUNCTIONS **/

char corewar(char **);
void display_map(corewar_t *crw);
char parse(char **, corewar_t *);
char error(char *);
char init_proc(corewar_t *, char);
char nbr_cycle(char **, int *, corewar_t *);
char prog_number(char **, int *, corewar_t *);
char load_address(char **, int *, corewar_t *);
char file(char *, corewar_t *);
char write_progs(corewar_t *crw);

int get_function(fct_t *function, unsigned char map[MEM_SIZE], int i);
int get_args(unsigned char *map, int *i, fct_t *function, char byte_code);
char read_progs(corewar_t *crw);
char invalid_prog_number(corewar_t *crw);
bool find_pos(int pos[5][2], int save[5][2]);
char organize_progs(corewar_t *crw);
char is_space(int e, int pos[5][2]);

char exec_progs(corewar_t *crw);
void get_args_value(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char nb_args(char function);
void get_indirect(prm_t *param, unsigned char map[MEM_SIZE], int *i, char type);
void get_direct(prm_t *param, unsigned char map[MEM_SIZE], int *i, char type);
void get_register(prm_t *param, unsigned char map[MEM_SIZE], int *i);


char live_f(corewar_t *crw, fct_t *fct);
char ld_f(corewar_t *crw, fct_t *fct);
char st_f(corewar_t *crw, fct_t *fct);
char add_f(corewar_t *crw, fct_t *fct);
char sub_f(corewar_t *crw, fct_t *fct);
char and_f(corewar_t *crw, fct_t *fct);
char or_f(corewar_t *crw, fct_t *fct);
char xor_f(corewar_t *crw, fct_t *fct);
char zjump_f(corewar_t *crw, fct_t *fct);
char ldi_f(corewar_t *crw, fct_t *fct);
char sti_f(corewar_t *crw, fct_t *fct);
char fork_f(corewar_t *crw, fct_t *fct);
char lld_f(corewar_t *crw, fct_t *fct);
char lldi_f(corewar_t *crw, fct_t *fct);
char lfork_f(corewar_t *crw, fct_t *fct);
char aff_f(corewar_t *crw, fct_t *fct);
char *get_map_str(char *str, int pos, int size, int max);

char f_add(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    UNUSED char *byte_code);
char f_aff(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    UNUSED char *byte_code);
char f_and(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_fork(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_ld(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_ldi(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_lfork(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_live(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_lld(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_lldi(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_or(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_st(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_sti(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_sub(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_xor(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);
char f_zjump(fct_t *function, unsigned char map[MEM_SIZE], int *i,
    char *byte_code);

int check_byte_code(fct_t *function, char byte_code);
int check_byte_code_value(const char *byte_code,
    const char byte_code_value[3][4], int nb);

int get_index_value(char *id_bin);
char wait(corewar_t *crw, fct_t *fct);
void fill_mem(corewar_t *crw, int pos, char *str);
int *get_regv(corewar_t *crw, char *arg);
int get_dirv(corewar_t *crw, char *arg);
int get_indv(corewar_t *crw, char *arg, int size);
int get_lindv(corewar_t *crw, char *arg, int size);
void new_assignement(corewar_t *crw, proc_t *new_proc);
char *get_map_str(char *str, int pos, int size, int max);
char init_execution(corewar_t *crw);
bool progs_are_alive(corewar_t *crw);
bool new_pos(int pos[5][2], int save[5][2], int space, int j);

#endif //COREWAR_COREWAR_H