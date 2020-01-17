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

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    size_t size = 0;
    __ssize_t return_getline = 0;

    for (;;) {
        display_usr(env);
        return_getline = getline(&line, &size, stdin);
        if (return_getline == EOF)
            return (33);
        cd_f(env, line);
        env_f(env, line);
        if (my_exit(line) == 0)
            break;
    }
    free(line);
    return (0);
}