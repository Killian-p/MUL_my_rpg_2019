/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>

#include "rpg.h"

int check_nb_enn(enn_s **ref, int type)
{
    enn_s *tmp = *ref;
    int idx = 0;

    while (tmp != NULL) {
        if (tmp->spawn_number == type)
            idx += 1;
        tmp = tmp->next;
    }
    if (idx > 20)
        return (0);
    return (1);
}

void add_to_list_enn(enn_s *enn, enn_s **ref)
{
    enn_s *tmp = *ref;

    if (tmp == NULL) {
        *ref = enn;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = enn;
}

void spawn_ennemie(int type, spawn_s *tmp, enn_s **ref)
{
    enn_s *enn = malloc(sizeof(enn_s));

    if (!enn)
        return;
    if (set_stat_enn(enn, type, tmp) == 84)
        return;
    add_to_list_enn(enn, ref);
}

void check_spawn_cap(spawn_s **ref_s, enn_s **ref_e)
{
    spawn_s *tmp = *ref_s;

    while (tmp != NULL) {
        if (check_nb_enn(ref_e, tmp->type) == 1)
            spawn_ennemie(tmp->type, tmp, ref_e);
        tmp = tmp->next;
    }
}

void spawning(scene_s *sc)
{
    int t = sfClock_getElapsedTime(sc->spawn_rate).microseconds;

    trigger_enn(sc, &sc->enn);
    if (t >= 1000000) {
        check_spawn_cap(&sc->spawner, &sc->enn);
        sfClock_restart(sc->spawn_rate);
    }
}