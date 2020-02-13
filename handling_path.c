/*
** EPITECH PROJECT, 2020
** handling_path.c
** File description:
** handling_path
*/

#include "minishell.h"
#include <stddef.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

static void signal_print(int status)
{
    if (WIFSIGNALED(status)) {
        if (WTERMSIG(status) == 8)
            my_putstr("Floating exception");
        else
            my_putstr(strsignal(WTERMSIG(status)));
        if (WCOREDUMP(status))
            write(2, " (core dumped)", 14);
        my_putchar('\n');
    }
}

char *find_path(char **env, char **array)
{
    char **path_in_path = NULL;
    char *total  = NULL;
    path_in_path = my_str_to_word_array(find_str(env, "PATH="), ':');

    if (access(array[0], X_OK) == 0)
            return (array[0]);
    for (int i = 0; path_in_path[i] != NULL; i++) {
        total = malloc(sizeof(char) * (my_strlen(path_in_path[i]) +
        my_strlen(array[0]) + 2));
        total[0] = '\0';
        my_strcat(total, path_in_path[i]);
        if (total[i] == ':')
            total = '\0';
        my_strcat(total, "/");
        my_strcat(total, array[0]);
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
        exit (1);
    } else {
        wait(&status);
        signal_print(status);
        return (1);
    }
    return (0);
}

int handling_path(char **array, char **env)
{
    if (find_path(env, array) == NULL) {
        write(2, array[0], my_strlen(array[0]) + 1);
        write(2, ": Command not found.\n", 21);
        return (1);
    } else {
        exec_path(env, array);
        return (1);
    }
}

void remove_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            str[i] = '\0';
    }
}