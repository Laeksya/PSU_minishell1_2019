/*
** EPITECH PROJECT, 2020
** my_setenv.c
** File description:
** my_setenv
*/

#include "minishell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf/my.h"

char **envdup(char **env)
{
    char **envcp = NULL;

    for (int i = 0; env[i] != NULL; i++)
        envcp[i] = my_strdup(env[i]);
    return (envcp);
}

int check_setenv_arg(char *str)
{
    int c = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ' && str[i + 1] != ' ')
            c++;
    }
    return (c);
}

void my_setenv(char **env, char *line)
{
    if (my_strncmp(line, "setenv", 6) == 0)
        check_setenv_arg();
}

void alloc_bigger_env(char **env, char *line)
{

}