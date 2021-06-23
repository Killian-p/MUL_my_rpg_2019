/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** check_str
*/

#include <my.h>

int check_equals(char *str, char *compare)
{
    int i = 0;

    while (str[i] == compare[i] && str[i] != '\0' && compare[i] != '\0') {
        i++;
    }
    if (str[i] == '\0' && compare[i] == '\0') {
        return TRUE;
    }
    return FALSE;
}