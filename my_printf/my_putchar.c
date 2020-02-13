/*
** EPITECH PROJECT, 2019
** my_putchar.c
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(2, &c, 1);
}