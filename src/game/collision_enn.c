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

int is_in_collision(enn_s *tmp, enn_s *enn)
{
    float x = tmp->obj->p.x;
    float y = tmp->obj->p.y;
    float x2 = enn->obj->p.x;
    float y2 = enn->obj->p.y;

    if (x2 - 100 < x && x2 + 100 > x &&
        y2 - 100 < y && y2 + 100 > y)
        return (1);
    return (0);
}

void eject(enn_s *tmp, sfVector2f p, int *push, int *nb)
{
    if (tmp->obj->p.x > p.x)
        tmp->obj->p.x += *push;
    else if (tmp->obj->p.x < p.x)
        tmp->obj->p.x -= *push;
    if (tmp->obj->p.y > p.y)
        tmp->obj->p.y += *push;
    else if (tmp->obj->p.y < p.y)
        tmp->obj->p.y -= *push;
    *push -= 5;
    if (*push <= 0) {
        *nb += 2;
        *push = 7 + *nb;
    }
}

void check_collision(enn_s *tmp, enn_s *enn, int *push, int *nb) {
    if (is_in_collision(tmp, enn) == 0) {
        return;
    }
    eject(tmp, enn->obj->p, push, nb);
}

void collision_enn(enn_s **ref, enn_s *enn, scene_s *sc, int idx)
{
    enn_s *tmp = *ref;
    int idx2 = 0;
    int push = 7;
    int nb = 0;

    while (tmp != NULL) {
        if (in_cam_enn(tmp, sc) == 1 && idx2 != idx
        && enn->has_reach != 1) {
            check_collision(tmp, enn, &push, &nb);
        }
        tmp = tmp->next;
        idx2 += 1;
    }
}