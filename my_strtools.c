/*
** EPITECH PROJECT, 2019
** my_string.c
** File description:
** help
*/

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
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