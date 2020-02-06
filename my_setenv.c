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

char **my_unsetenv(char **env, char **array)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp(env[i], array[1]) == 0)
            env[i][0] = '\0';
        else {
            env = env;
        }
    }
    return (env);
}

char **my_setenv(char **env, char **array)
{
    int len_name = my_strlen(array[1]);
    int len_value = my_strlen(array[2]);

    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp(env[i], array[1]) == 0) {
            env[i] = malloc(sizeof(char) * (len_name + len_value + 2));
            env[i][0] = '\0';
            my_strcat(env[i], array[1]);
            my_strcat(env[i], "=");
            my_strcat(env[i], array[2]);
        }
        return (env);
    }
    return (NULL);
}
