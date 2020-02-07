/*
** EPITECH PROJECT, 2019
** my_string.c
** File description:
** help
*/

#include <stdlib.h>
#include "minishell.h"
#include "my_printf/my.h"

int my_str_isnum(char const *str)
{
    while (*str != '\0') {
        if (!((*str >= '0' && *str <= '9') || (*str <= '\n')))
            return (0);
        str++;
    }
    return (1);
}

int my_strcmp(char const *s1, char const *s2)
{
    while (*s1) {
        if (*s1 != *s2) {
            return (*s1 - *s2);
        }
    s1++;
    s2++;
    }
    return (*s1 - *s2);
}

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (*s1 == *s2 && i <= n) {
        s1++;
        s2++;
        i++;
    }
    if (i == n)
        return (0);
    return (my_strcmp(s1, s2));
}

char *my_strdup(char const *src)
{
    int i = 0;
    int n = my_strlen(src);
    char *str = malloc(sizeof(char) * (n + 1));

    while (i <= n) {
        str[i] = src[i];
        i++;
    }
    return (str);
}

char *my_strcat(char *dest, char const *src)
{
    int c;
    int n;

    for ( n = 0; dest[n] != '\0'; n++) {
    }
    for (c = 0; src[c] != '\0'; c++) {
        dest[n+c] = src[c];
    }
    dest[n+c] = '\0';
    return (dest);
}