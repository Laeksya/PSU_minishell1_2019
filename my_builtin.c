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
#include "my_printf/my.h"

int my_exit(char *line, int exit_status)
{
    if (my_strncmp(line, "exit", 4) == 0) {
        if (my_str_isnum(line + 5) == 0) {
            my_printf("%s: Expression Syntax.\n", line + 5);
            return (1);
        }
        else {
            exit_status = my_getnbr(line + 4);
            return (exit_status);
        }
    }
    return (1);
}

void env_f(char **env, char *line)
{
    if (my_strcmp(line, "env") == 0)
        for (int i = 0; env[i] != NULL; i++) {
            my_putstr(env[i]);
            my_putchar ('\n');
        }
}

void cd_f(char **env, char *line)
{
    if (my_strcmp(line, "cd") == 0)
        chdir(find_str(env, "HOME="));
    else if (line[0] == 'c' && line[1] == 'd')
        if (chdir(line + 3) == -1)
            my_printf("%s: No such file or directory.\n", line + 3);
}