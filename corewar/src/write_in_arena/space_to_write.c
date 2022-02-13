/*
** EPITECH PROJECT, 2019
** corewar
** File description:
** corewar
*/

#include "corewar.h"
#include <unistd.h>
#include <stdlib.h>
#include "lib.h"

char is_space(int e, int pos[5][2])
{
    for (int i = 0; pos[i][0] != -2; ++i)
        if (pos[i][0] != -1 && i != e &&
            ((pos[i][0] >= pos[e][0] && pos[i][0] <= pos[e][0] + pos[e][1]) ||
            (pos[i][0] + pos[i][1] >= pos[e][0] &&
            pos[i][0] + pos[i][1] <= pos[e][0] + pos[e][1])))
            return (false);
    return (true);
}