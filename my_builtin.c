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

int find_fbuilting(char **array, char **env)
{
    if (my_strncmp(array[0], "cd", 2) == 0) {
        cd_f(env, array);
        return (1);
    }
    if (my_strncmp(array[0], "env", 3) == 0) {
        env_f(env);
        return (1);
    }
    if (my_strncmp(array[0], "setenv", 6) == 0) {
        my_setenv(env, array);
        env = my_setenv(env, array);
        return (1);
    }
    if (my_strncmp(array[0], "exit", 4) == 0 && my_str_isnum(array[1]) == 0) {
        write(2, array[1], my_strlen(array[1]));
        write(2, ": Expression Syntax.", 20);
        return (1);
    }
    if (my_strncmp(array[0], "exit", 4) == 0 && my_str_isnum(array[1]) == 1) {
        return (2);
    }
    return (0);
}

int find_builtin(char **array, char **env)
{
    if (find_fbuilting(array, env) == 2) {
        my_exit (array, 0);
        return (0);
    }
    else if (find_fbuilting(array, env) == 0) {
        handling_path(array, env);
        return (1);
    }
    return (1);
}

int my_exit(char **array, int exit_status)
{
    exit_status = my_getnbr(array[1]);
    return (exit_status);
}

int env_f(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        my_putstr(env[i]);
        my_putchar('\n');
    }
    return (1);
}

int cd_f(char **env, char **array)
{
    if (array[1] == NULL) {
        chdir(find_str(env, "HOME="));
        return (1);
    }
    else if (chdir(array[1]) == -1) {
            my_printf("%s: No such file or directory.\n", array[1]);
            return (1);
        }
    return (0);
}