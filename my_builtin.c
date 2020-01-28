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

int find_builtin(char **array, char **env)
{
    if (my_strncmp(array[0], "cd", 2) == 0)
        cd_f(env, array);
    if (my_strncmp(array[0], "exit", 4) == 0)
        my_exit(array, 0);
    if (my_strncmp(array[0], "env", 3) == 0)
        env_f(env);
/*     if (my_strncmp(array[0], "setenv", 6) == 0)
        my_setenv(env, array);
    if (my_strncmp(array[0], "unsetenv", 8) == 0)
        my_unsetenv(env, array); */
    return (0);
}

int my_exit(char **array, int exit_status)
{
    if (my_str_isnum(array[1]) == 0) {
        my_printf("%s: Expression Syntax.\n", array[1]);
        return (1);
    }
    else {
        exit_status = my_getnbr(array[1]);
        return (exit_status);
    }
    return (1);
}

void env_f(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
}

void cd_f(char **env, char **array)
{
    if (my_strncmp(array[0], "cd", 2) == 0 && array[1] == NULL)
        chdir(find_str(env, "HOME="));
    else if (my_strncmp(array[0], "cd", 2))
        if (chdir(array[1]) == -1)
            my_printf("%s: No such file or directory.\n", array[1]);
}