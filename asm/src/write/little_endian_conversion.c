/*
** EPITECH PROJECT, 2019
** little_endian_conversion.c
** File description:
** convert big endian into little endian
*/

#include "asm.h"

unsigned short little_to_big_endian_short(short x)
{
    return (((x<<8) & 0x0000ff00) | ((x>>8) & 0x000000ff));
}

unsigned int little_to_big_endian_int(int x)
{
    return (((x>>24) & 0x000000ff) | ((x>>8) & 0x0000ff00) |
    ((x<<8) & 0x00ff0000) | ((x<<24) & 0xff000000));
}