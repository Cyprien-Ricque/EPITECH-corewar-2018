/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** my_strcmp
*/

#include "lib.h"

bool my_strcmp_end(char const *str1, char const *str2)
{
    if (my_strlen(str1) <= my_strlen(str2))
        return (false);
    while (my_strlen(str1) != my_strlen(str2)) {
        if (*str1 == '\0' || *str2 == '\0')
            return (false);
        ++str1;
    }
    return (my_strcmp(str1, str2));
}

bool my_strcmp_begin(char const *str1, char const *str2)
{
    ssize_t size1 = my_strlen(str1);
    ssize_t size2 = my_strlen(str2);

    if (size1 < size2 || size1 == -1 || size2 == -1)
        return (false);
    for (int a = 0; str2[a] != '\0'; ++a) {
        if (str1[a] != str2[a])
            return (false);
    }
    return (true);
}

bool my_strcmp(char const *str1, char const *str2)
{
    ssize_t size1 = my_strlen(str1);
    ssize_t size2 = my_strlen(str2);

    if (size1 != size2 || size1 == -1 || size2 == -1)
        return (false);
    for (int a = 0; str1[a] != '\0' && str2[a] != '\0'; ++a) {
        if (str1[a] != str2[a])
            return (false);
    }
    return (true);
}