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

sfVector2f get_size_button(char *buffer)
{
    sfVector2f pos;

    pos.x = get_nb_number(buffer, 2);
    pos.y = get_nb_number(buffer, 3);
    return (pos);
}

sfVector2f get_pos_button(char *buffer)
{
    sfVector2f pos;

    pos.x = get_nb_number(buffer, 0);
    pos.y = get_nb_number(buffer, 1);
    return (pos);
}

int get_callback(char *buffer)
{
    return (get_nb_number(buffer, 4));
}