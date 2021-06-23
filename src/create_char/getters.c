/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "unistd.h"
#include "create_char.h"
#include "math.h"

int get_nb_number(char *buffer, int nb)
{
    int idx = 0;
    int check = 0;
    int set = 0;
    int res = 0;

    while ((buffer[idx] <= '9' && buffer[idx] >= '0') || check < nb) {
        if (buffer[idx] == '\0')
            return (0);
        if ((buffer[idx] >= '0' && buffer[idx] <= '9') && set == 0) {
            check += 1;
            set = 1;
        }
        if (buffer[idx] < '0' || buffer[idx] > '9')
            set = 0;
        idx += 1;
    }
    get_res(buffer, idx, &res);
    return (res);
}

sfVector2f get_pos(char *buffer)
{
    sfVector2f pos;

    pos.x = get_nb_number(buffer, 0);
    pos.y = get_nb_number(buffer, 1);
    return (pos);
}

sfVector2f get_origin(char *buffer)
{
    sfVector2f pos;

    pos.x = get_nb_number(buffer, 2);
    pos.y = get_nb_number(buffer, 3);
    return (pos);
}

sfColor get_color(char *buffer)
{
    sfColor color;

    color.r = get_nb_number(buffer, 4);
    color.g = get_nb_number(buffer, 5);
    color.b = get_nb_number(buffer, 6);
    color.a = get_nb_number(buffer, 7);
    return (color);
}

char *get_font(char *buffer)
{
    char *str = malloc(sizeof(char) * (get_size_str(buffer, 3)));
    int idx = 0;
    int check = 0;
    int idx2 = 0;

    if (!str)
        return NULL;
    while (check != 3) {
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