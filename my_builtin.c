/*
** EPITECH PROJECT, 2020
** my_builtin.c
** File description:
** my_builtin
*/

#include "minishell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int my_exit(char *line)
{
    if (my_strcmp(line, "exit\n") == 0)
        return (0);
}

void env_f(char **env, char *line)
{
    if (my_strcmp(line, "env\n") == 0)
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar ('\n');
        }
}

void cd_f(char **env, char *line)
{
    for (int i = 0; line[i] != '\n'; i++) {
        if (my_strcmp(line, "cd ") == 0) {
            chdir(line + 3);
            my_putstr(line + 3);
        }
        if (my_strcmp(line, "cd\n") == 0)
            chdir(find_str(env, "HOME="));
    }
}