/*
** EPITECH PROJECT, 2019
** my_putstr.c
** File description:
** displays_characters_one_by_one
*/

#include <unistd.h>
#include "minishell.h"

void display_usr(char **env)
{
    my_putchar('[');
    my_putstr(find_str(env, "USER="));
    my_putchar('@');
    my_putstr(find_str(env, "HOSTNAME="));
    my_putchar(']');
    my_putchar('>');
}