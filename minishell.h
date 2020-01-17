/*
** EPITECH PROJECT, 2020
** my_minishell.h
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);

char *find_str(char **env, char *str_tofind);
void display_usr(char **env);
void cd_f(char **env, char *line);
void env_f(char **env, char *line);
int my_exit(char *line);



#endif /* !MINISHELL_H_ */
