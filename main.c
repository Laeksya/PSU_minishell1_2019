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
    for (; str[i] == ' ' || str[i] == '\t'; ++i);
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

void remove_char(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            str[i] = '\0';
    }
}

int main(int ac, char **av, char **env)
{
    char *line = NULL;
    char **array = NULL;
    size_t size = 0;
    __ssize_t return_getline = 0;
    int exit_stat = 0;

    if (ac != 1)
        return (84);
    (void)(av);
    for (;;) {
        display_usr(env);
        return_getline = getline(&line, &size, stdin);
        if (return_getline == EOF) {
            my_putstr(" exit\n");
            return (0);
        }
        remove_char(line);
        tab_to_space(line);
        array = my_str_to_word_array(line);
        if (find_builtin(array, env) != 1) {
            my_putstr("exit\n");
            break;
        }
    }
    /* free(array); */
    return (my_exit(array, exit_stat));
}