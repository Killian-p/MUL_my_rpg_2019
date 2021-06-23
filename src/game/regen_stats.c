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

void regen_stats(scene_s *sc)
{
    int check = 0;
    int t = sfClock_getElapsedTime(sc->regen).microseconds;

    if (sc->disp->stamina < sc->stats->stamina && t >= 10000) {
        sc->disp->stamina += 0.05 + sc->stats->stamina * 0.5/1000;
        sfClock_restart(sc->regen);
        check = 1;
    }
    if (sc->disp->life < sc->stats->life && (t >= 10000 || check == 1))
        sc->disp->life += 0.03 + sc->stats->life * 0.25/1000;
    if (sc->disp->magic < sc->stats->magic && (t >= 10000 || check == 1))
        sc->disp->magic += 0.03 + sc->stats->magic * 0.25/1000;
    while (sc->stats->exp >= 100 * 1.25 * (sc->stats->lvl + 1)) {
        sc->stats->exp -= 100 * 1.25 * (sc->stats->lvl + 1);
        sc->stats->lvl += 1;
        sc->skills->skillpoints += 2;
    }
}