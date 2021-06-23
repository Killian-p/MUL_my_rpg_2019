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
#include <math.h>

int check_tile(map_s *tmp)
{
    if (tmp->tile->rect.left == 16 * 6)
        return (1);
    return (0);
}

int check_for_gravel(sfVector2f p, map_s **map, int x, int y)
{
    map_s *tmp = *map;
    int savex = 0;
    int savey = 0;
    int check = 0;

    while (savey != y && tmp != NULL) {
        if (tmp->tile->p.y == p.y + savey * 80
        && tmp->tile->p.x == p.x + savex * 80) {
            check = check_tile(tmp);
            savex += 1;
        }
        if (check == 1)
            return (1);
        if (savex == x) {
            savex = 0;
            savey += 1;
        }
        tmp = tmp->next;
    }
    return (0);
}

void target_managing(scene_s *sc, float x, float y)
{
    float v = 0;
    float x2 = sc->player->p.x;
    float y2 = sc->player->p.y;

    sc->mv_kit->target.y = y;
    sc->mv_kit->memx = x2;
    sc->mv_kit->memy = y2;
    if (y2 - y == 0)
        y2 += 1;
    sc->mv_kit->a = (y2 - y) / (x2 - x);
    if (sc->mv_kit->a == 0)
        sc->mv_kit->a = 0.0001;
    sc->mv_kit->b = y2 - (sc->mv_kit->a * x2);
    v = sqrt(pow(((-sc->mv_kit->b/sc->mv_kit->a) - x2), 2) + pow(y2, 2));
    sc->mv_kit->v = v;
    if (v == 0)
        v += 0.001;
    sc->mv_kit->d = sqrt(pow(sc->mv_kit->v, 2) - pow(y2, 2));
    sc->mv_kit->speedx = (sc->player->speed * sc->mv_kit->d) / sc->mv_kit->v;
}

int create_map_loop(int *idx, int *idy)
{
    *idx += 80;
    if (*idx == size_map_x * 80) {
        *idx = 0;
        *idy += 80;
    }
    return (0);
}