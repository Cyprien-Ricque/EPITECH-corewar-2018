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
bool my_strcmp(char const *, char const *);
long my_atoi(char const *);
char my_str_is_num_pos(char const *);
char *gnl(int fd);
char *m_scat(char *dest, char *src, int pos, int n);
int m_slen(char const *str);
int m_getnb(char const *str);
int octect_to_dec(char *str, int size);
char *m_retbase(long long nb, int base);
char *m_revs(char *str);
char *m_printf(int fd, char *str, ...);
char *m_iarray(va_list ap, char *str, char *buf);
char *m_maj_iarray(va_list ap, char *str, char *buf);
char *m_retbase_o(long long nb, int base);
char *m_int(va_list ap, char *str, char *buf);
char *m_char(va_list ap, char *str, char *buf);
char *m_string(va_list ap, char *str, char *buf);
char *m_array(va_list ap, char *str, char *buf);
int m_arraylen(char **src);
char *m_arrays(char **array, char c);
char *m_hex(va_list ap, char *str, char *buf);
char *m_maj_hex(va_list ap, char *str, char *buf);
void my_puts_fd(char const *str, int fd);

#endif //CPE_COREWAR_2018_LIB_H
