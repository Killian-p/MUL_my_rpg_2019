/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "create_char.h"
#include "math.h"

int get_size_str(char *buffer, int nb)
{
    int idx = 0;
    int res = 0;
    int check = 0;

    while (check != nb) {
        if (buffer[idx] == '"')
            check += 1;
        idx += 1;
    }
    while (buffer[idx] != '"') {
        idx += 1;
        res += 1;
    }
    return (res + 1);
}

char *get_str(char *buffer)
{
    char *str = malloc(sizeof(char) * get_size_str(buffer, 1));
    int idx = 0;
    int check = 0;
    int idx2 = 0;

    if (!str)
        return NULL;
    while (check != 1) {
        if (buffer[idx] == 34)
            check += 1;
        idx += 1;
    }
    while (buffer[idx] != 34) {
        str[idx2] = buffer[idx];
        idx += 1;
        idx2 += 1;
    }
    str[idx2] = '\0';
    return (str);
}

int get_size(char *buffer)
{
    int res = get_nb_number(buffer, 8);

    return (res);
}

void get_res(char *buffer, int idx, int *res)
{
    while (buffer[idx] < '0' || buffer[idx] > '9')
    {
        idx += 1;
    }
    while (buffer[idx] >= '0' && buffer[idx] <= '9') {
        *res = *res * 10 + buffer[idx] - 48;
        idx += 1;
    }
}

char *get_skill(int idx, skill_s *skillpt)
{
    switch (idx)
    {
        case 8:
            return (my_nbr(skillpt->strength));
        case 9:
            return (my_nbr(skillpt->intelligence));
        case 10:
            return (my_nbr(skillpt->stamina));
        case 11:
            return (my_nbr(skillpt->accuracy));
        case 12:
            return (my_nbr(skillpt->chance));
        case 13:
            return (my_nbr(skillpt->vitality));
        case 14:
            return (my_nbr(skillpt->skillpoints));
    }
    return (NULL);
}