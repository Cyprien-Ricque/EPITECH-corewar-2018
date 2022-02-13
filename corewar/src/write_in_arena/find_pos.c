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

bool new_pos(int pos[5][2], int save[5][2], int space, int j)
{
    bool ok = true;

    for (int i = 0; pos[i][0] != -2; ++i) {
        if (save[i][0] == -1)
            pos[i][0] = 0;
        while (is_space(i, pos) == false) {
            ok = pos[i][0] > MEM_SIZE || save[i][0] != -1 ? false : ok;
            if (pos[i][0] > MEM_SIZE || save[i][0] != -1)
                break;
            pos[i][0] += space - j;
        }
        if (ok == false)
            break;
    }
    return (ok);
}