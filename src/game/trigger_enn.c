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

int trigger_on(enn_s *tmp, game_object *player)
{
    float x = player->p.x;
    float y = player->p.y;
    float x2 = tmp->obj->p.x;
    float y2 = tmp->obj->p.y;

    if (x2 - tmp->trigger.x < x && x2 + tmp->trigger.x > x &&
    y2 - tmp->trigger.y < y && y2 + tmp->trigger.y > y)
        return (1);
    return (0);
}

void target_managing_enn(float x, float y, enn_s *e)
{
    float v = 0;
    float x2 = e->obj->p.x;
    float y2 = e->obj->p.y;

    e->mv_kit->target.y = y;
    e->mv_kit->memx = x2;
    e->mv_kit->memy = y2;
    if (y2 - y == 0)
        y2 += 1;
    e->mv_kit->a = (y2 - y) / (x2 - x);
    e->mv_kit->b = y2 - (e->mv_kit->a * x2);
    v = sqrt(pow(((-e->mv_kit->b/e->mv_kit->a) - x2), 2) + pow(y2, 2));
    e->mv_kit->v = v;
    if (v == 0)
        v += 0.1;
    e->mv_kit->d = sqrt(pow(e->mv_kit->v, 2) - pow(y2, 2));
    e->mv_kit->speedx = (e->obj->speed * e->mv_kit->d) / e->mv_kit->v;
}

void set_path_enn(enn_s *tmp, scene_s *sc)
{
    float x = sc->player->p.x;
    float y = sc->player->p.y;

    tmp->mv_kit->target.x = x;
    if (tmp->obj->p.x - sc->mv_kit->target.x == 0)
        x += 1;
    target_managing_enn(x, y, tmp);
}

void move_attack_enn(enn_s *tmp, scene_s *sc)
{
    if (tmp->focus == 0) {
        sfSprite_setTexture(tmp->obj->sprite, tmp->move, 0);
        set_anim_stat(tmp, 1088, 1);
        tmp->disp_speed = 80000;
    }
    set_path_enn(tmp, sc);
    if (move_enn(tmp, 0) == 2) {
        if (tmp->has_reach == 0) {
            sfSprite_setTexture(tmp->obj->sprite, tmp->atk, 0);
            set_anim_stat(tmp, 832, 2);
            tmp->disp_speed = 100000;
        }
        take_damage_enn(sc, tmp);
        tmp->has_reach = 1;
    } else {
        tmp->has_reach = 0;
    }
}

void trigger_enn(scene_s *sc, enn_s **ref)
{
    enn_s *tmp = *ref;
    int idx = 0;

    while (tmp != NULL) {
        if (trigger_on(tmp, sc->player) == 1 && tmp->tuto != 1 &&
        tmp->life > 0 && in_cam_enn(tmp, sc) == 1) {
            move_attack_enn(tmp, sc);
            tmp->focus = 1;
        } else if (tmp->life > 0) {
            tmp->focus = 0;
            sfSprite_setTexture(tmp->obj->sprite, tmp->idle, 0);
            set_anim_stat(tmp, 192, 0);
            tmp->disp_speed = 150000;
        } else
            tmp->life = 0;
        collision_enn(ref, tmp, sc, idx);
        tmp = tmp->next;
        idx += 1;
    }
}