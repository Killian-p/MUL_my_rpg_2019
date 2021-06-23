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

int get_nb_size(int nb)
{
    int idx = 1;

    while (nb > 9) {
        nb = nb % 10;
        idx += 1;
    }
    return (idx);
}

char *my_nbr(int nb)
{
    int idx = 0;
    char *str = malloc(sizeof(char) * (get_nb_size(nb) + 1));

    if (nb == 0)
        return ("0");
    while (nb > 0) {
        if (idx == 0)
            str[idx] = nb % 10 + 48;
        else {
            str[idx] = str[idx - 1];
            str[idx - 1] = nb % 10 + 48;
        }
        nb = nb / 10;
        idx += 1;
    }
    str[idx] = '\0';
    return (str);
}

ret_s *return_create_char(scene_s *sc, skill_s *sk)
{
    ret_s *values = malloc(sizeof(ret_s));

    values->name = sc->name;
    values->event = sc->event;
    values->window = sc->window;
    values->skillpoint = sk;
    return (values);
}