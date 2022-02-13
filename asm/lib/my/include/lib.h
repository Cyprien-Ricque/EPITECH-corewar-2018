/*
** EPITECH PROJECT, 2019
** lib
** File description:
** Created by Emilien Delevoye
*/

#ifndef CPE_COREWAR_2018_LIB_H
#define CPE_COREWAR_2018_LIB_H


#include <stdio.h>
#include <stdbool.h>

/** nb_to_str and put_nbr functions **/

char *add_minus_to_str(char *, int, long long *);
char nb_negative_ret(long long );
long long nb_negative(long long *);
long long nb_char_int(long long );
char *add_error_zero(char *);

/** END **/

/** Macros **/

#define UNUSED __attribute__ ((unused))
#define SUCCESS 0
#define FAILURE 84
#define TRUE 1
#define FALSE 0

/** End macros **/

ssize_t my_strlen(char const *);
void my_puts(char const *);
char *my_strdup(char const *);
ssize_t my_arraylen(char **);
char *my_strcat(char *, char *);
bool my_strcmp(char const *, char const *);
char *my_clean_str(char *);
char **my_str_to_array(char *);
char *get_next_line(int);
char *remove_spaces_end(char *);
int count_words(char const *);
size_t size_of_next_word(char const *, int);
void move_str(char *, int);
long my_atoi(char const *);
bool my_strcmp_begin(char const *, char const *);
bool my_strcmp_end(char const *, char const *);
char *my_clean_str_begin(char *);
char my_strcpy_max(char *, char const *, int, char *);

#endif //CPE_COREWAR_2018_LIB_H
