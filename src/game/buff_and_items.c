/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

#include "rpg.h"

char *get_file_id(items_s *item)
{
    int idx = 0;
    char *ex = "config/\0";
    char *str = malloc(sizeof(char) * 14);

    while (ex[idx] != '\0') {
        str[idx] = ex[idx];
        idx += 1;
    }
    str[7] = item->id[0] + 48;
    str[8] = item->id[1] + 48;
    str[9] = '.';
    str[10] = 't';
    str[11] = 'x';
    str[12] = 't';
    str[13] = '\0';
    return (str);
}

float atoi_for_items(char *str)
{
    int i = 0;
    float v = 0;

    while (str[i] != '\0' && str[i] != '\n') {
        if (str[i] >= '0' && str[i] <= '9')
            v = v * 10 + (str[i] - 48);
        i += 1;
    }
    return (v);
}