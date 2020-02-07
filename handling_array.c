/*
** EPITECH PROJECT, 2018
** my_str_to_word_array
** File description:
** Function that splits a string into words
*/

#include "minishell.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "my_printf/my.h"

void tab_to_space(char *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\t')
            str[i] = ' ';
    }
}

int space_nb(char *str, char c)
{
    int space = 0;

    tab_to_space(str);
    if (my_strlen(str) >= 1)
        space++;
    for (int i = 0; i < my_strlen(str); i++) {
        if (str[i] == c && str[i + 1] != c)
            space++;
    }
    return (space);
}

char **tab_alloc(int lines, int col)
{
    char **array  = NULL;
    array = malloc(sizeof(char *) * lines);

    if (!array)
        return (NULL);
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < col; j++)
            array[i] = malloc(sizeof(char) * col);
    }
    return (array);
}

char **my_str_to_word_array(char *str, char c)
{
    char **array;
    int x = 0;

    array = tab_alloc(space_nb(str, c), 200);

    for (int i, y = 0; str[i] != '\0'; i++) {
        array[x][y] = str[i];
        y++;
        if (str[i] == c && str[i + 1] != c) {
            x++;
            y = 0;
        }
    }
    array[x + 1] = NULL;
    return (array);
}