/*
** EPITECH PROJECT, 2020
** my_minishell.h
** File description:
** minishell
*/

#ifndef MINISHELL_H_
#define MINISHELL_H_

typedef struct minishell minishell_t;
struct minishell {
    char *name;
    char *value;
    char **env;
    minishell_t *next;
};

int my_strncmp(char const *s1, char const *s2, int n);
int my_strcmp(char const *s1, char const *s2);
char *my_strdup(char const *src);
int my_putstr(char const *str);
void my_putchar(char c);
int my_strlen(char const *str);
char *my_strcat(char *dest, char const *src);

//
char *find_str(char **env, char *str_tofind);
void display_usr(char **env);
int cd_f(char **env, char **array);
int env_f(char **env);
int my_exit(char **array, int exit_stat);
int find_builtin(char **array, char **env);
int find_fbuilting(char **array, char **env);
int count_arr(char **array);

//setenv
char **envdup(char **env);
char **my_setenv(char **env, char **array);

//array_handling
void tab_to_space(char *str);
int space_nb(char *str, char c);
char **arr_alloc(int lines, int col);
char **my_str_to_word_array(char *str, char c);
void remove_char(char *str);

char *find_path(char **env, char **array);
int exec_path(char **env, char **array);
int handling_path(char **array, char **env);

int my_isnb(char c);
int my_getnbr(char const *str);
int my_str_isnum(char const *str);

#endif /* !MINISHELL_H_ */
