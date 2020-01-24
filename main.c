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

int my_isnb(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}

int my_getnbr(char const *str)
{
    int res = 0;
    int sign = 1;
    int i = 0;

    for (; str[i] == '+' || str[i] == '-'; i++)	{
    	if (str[i] == '-')
            sign *= -1;
    }
    for (; str[i] == ' '; ++i);
    for (; str[i] != '\0' && my_isnb(str[i]); i++) {
    	res = res * 10 + str[i] - '0';
    }
    return (sign * res);
}

char *find_str(char **env, char *str_tofind)
{
    int len_ofstr = my_strlen(str_tofind);

    for (int i = 0; env[i] != NULL; i++)
        if (my_strncmp(env[i], str_tofind, len_ofstr) == 0)
            return (env[i] + len_ofstr);
    return (NULL);
}

static void remove_newline(char *line)
{
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == '\n')
            line[i] = '\0';
    }
}

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    size_t size = 0;
    __ssize_t return_getline = 0;
    int exit_stat = 0;

    (void)(ac);
    (void)(av);
    for (;;) {
        display_usr(env);
        return_getline = getline(&line, &size, stdin);
        if (return_getline == EOF)
            return (33);
        remove_newline(line);
        cd_f(env, line);
        env_f(env, line);
        if (my_exit(line, exit_stat) != 1) {
            my_putstr("exit\n");
            break;
        }
    }
    return (my_exit(line, exit_stat));
}