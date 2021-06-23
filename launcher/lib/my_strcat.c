/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** my_strcat
*/

#include "my.h"
#include <stdlib.h>

char *my_strcat(char *s1, char *s2)
{
    char *result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

    for (int f = 0; s1[f]; f++, i++)
        result[i] = s1[f];
    for (int f = 0; s2[f]; f++, i++)
        result[i] = s2[f];
    result[i] = '\0';
    return (result);
}
