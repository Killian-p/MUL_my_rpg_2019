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

void move_x_enn(enn_s *tmp)
{
    int idx = 1;

    if (tmp->mv_kit->memx > tmp->mv_kit->target.x)
        idx = -1;
    if (tmp->obj->scale.x > 0 && idx == -1)
        tmp->obj->scale.x *= -1;
    if (tmp->obj->scale.x < 0 && idx == 1)
        tmp->obj->scale.x *= -1;
    tmp->obj->p.x += tmp->mv_kit->speedx * idx;
    sfSprite_setPosition(tmp->obj->sprite, tmp->obj->p);
}

void move_y_enn(enn_s *tmp)
{
    float x = tmp->obj->p.x;

    tmp->obj->p.y = tmp->mv_kit->a * x + tmp->mv_kit->b;
    sfSprite_setPosition(tmp->obj->sprite, tmp->obj->p);
}

void move_y_line_enn(enn_s *tmp)
{
    int idx = 1;

    if (tmp->mv_kit->memy > tmp->mv_kit->target.y)
        idx = -1;
    tmp->obj->p.y += tmp->obj->speed * idx;
    sfSprite_setPosition(tmp->obj->sprite, tmp->obj->p);
}

int move_enn(enn_s *tmp, int has_reach)
{
    if (tmp->obj->p.x >= tmp->mv_kit->target.x - 70
        && tmp->obj->p.x <= tmp->mv_kit->target.x + 70)
        has_reach += 1;
    else {
        move_x_enn(tmp);
    }
    if (tmp->obj->p.y >= tmp->mv_kit->target.y - 70
        && tmp->obj->p.y <= tmp->mv_kit->target.y + 70)
        has_reach += 1;
    else {
        if (has_reach == 1)
            move_y_line_enn(tmp);
        else
            move_y_enn(tmp);
    }
    return (has_reach);
}

void take_damage_enn(scene_s *sc, enn_s *tmp)
{
    int t = sfClock_getElapsedTime(tmp->atk_rate).microseconds;

    if (t >= 2000000) {
        sc->disp->life -= tmp->damage;
        sfClock_restart(tmp->atk_rate);
    }
}