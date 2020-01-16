/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** the_main_function
*/

#include "minishell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *find_str(char **env, char *str_tofind)
{
    int len_ofstr = my_strlen(str_tofind);

    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], str_tofind, len_ofstr) == 0)
            return (env[i] + len_ofstr);
    return (NULL);
}

void name_user(char **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strncmp(env[i], "USER=", 5) == 0) {
            my_putchar('[');
            my_putstr(env[i] + 5);
            my_putchar(']');
        }
    }
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
        if (my_strcmp(line, "cd ") == 0)
            chdir(line + 3);
        if (my_strcmp(line, "cd\n") == 0)
            chdir(find_str(env, "HOME="));
    }
}

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    size_t size = 0;

    for (;;) {
        name_user(env);
        getline(&line, &size, stdin);
        cd_f(env, line);
        env_f(env, line);
    }
    free(line);
    return (0);
}