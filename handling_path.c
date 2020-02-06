/*
** EPITECH PROJECT, 2020
** handling_path.c
** File description:
** handling_path
*/

#include "minishell.h"
#include "stddef.h"
#include "stdlib.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

char *find_path(char **env, char **array)
{
    char **path_in_path = NULL;
    char *total  = NULL;
    path_in_path = my_str_to_word_array(find_str(env, "PATH="), ':');

    if (access(array[0], X_OK) == 0)
            return (array[0]);
    for (int i = 0; path_in_path[i] != NULL; i++) {
        total = malloc(sizeof(char) * (my_strlen(path_in_path[i]) +
        my_strlen(array[1]) + 2));
        total[0] = '\0';
        my_strcat(total, path_in_path[i]);
        my_strcat(total, "/");
        my_strcat(total, array[1]);
        if (access(total, X_OK) == 0)
            return (total);
        free(total);
    }
    return (NULL);
}

int exec_path(char **env, char **array)
{
    __pid_t pid = fork();
    struct stat info;
    char *path = find_path(env, array);
    int status;

    stat(array[0], &info);
    if (pid == -1)
        return (1);
    else if (pid == 0) {
        execve(path, array, env);
        return (1);
    }
    else {
        wait(&status);
        return (1);
    }
}

int handling_path(char **array, char **env)
{
    if (find_path(env, array) == NULL) {
        write(2, array[1], my_strlen(array[1]) + 1);
        write(2, ": command not found.\n", 21);
        return (1);
    }
    else {
        exec_path(env, array);
        return (1);
    }
}