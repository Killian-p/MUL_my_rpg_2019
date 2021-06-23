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

void move_x(scene_s *scene)
{
    int idx = 1;
    sfVector2f move = {scene->mv_kit->speedx, 0};

    if (scene->mv_kit->memx > scene->mv_kit->target.x)
        idx = -1;
    move.x *= idx;
    scene->player->p.x += scene->mv_kit->speedx * idx;
    sfSprite_setPosition(scene->player->sprite, scene->player->p);
    set_interfacex(scene, move);
}

void move_y(scene_s *scene)
{
    float x = scene->player->p.x;
    float y = scene->player->p.y;
    sfVector2f move = {0, 0};

    scene->player->p.y = scene->mv_kit->a * x + scene->mv_kit->b;
    move.y = scene->player->p.y - y;
    sfSprite_setPosition(scene->player->sprite, scene->player->p);
    set_interfacey(scene, move);
}

void move_y_line(scene_s *scene)
{
    int idx = 1;
    float y = scene->player->p.y;
    sfVector2f move = {0, 0};

    if (scene->mv_kit->memy > scene->mv_kit->target.y)
        idx = -1;
    scene->player->p.y += scene->player->speed * idx;
    move.y = scene->player->p.y - y;
    sfSprite_setPosition(scene->player->sprite, scene->player->p);
    set_interfacey(scene, move);
}

void moving_player(scene_s *sc, int has_reach)
{
    if (sc->player->p.x >= sc->mv_kit->target.x - 10
    && sc->player->p.x <= sc->mv_kit->target.x + 6)
        has_reach += 1;
    else {
        move_x(sc);
    }
    if (sc->player->p.y >= sc->mv_kit->target.y - 10
        && sc->player->p.y <= sc->mv_kit->target.y + 6)
        has_reach += 1;
    else {
        if (has_reach == 1)
            move_y_line(sc);
        else
            move_y(sc);
    }
    reaching_action(sc, has_reach);
}

void move_player(scene_s *sc)
{
    int t = sfClock_getElapsedTime(sc->clock2).microseconds;
    int t2 = sfClock_getElapsedTime(sc->atk_rate).microseconds;

    if (sc->mv_kit->has_reach == 0 && t >= 15000 && sc->atk == 0) {
        if (sc->focus > 0)
            set_path(sc);
        if (sc->get_item > 0)
            set_path_to_item(sc);
        moving_player(sc, 0);
        sfClock_restart(sc->clock2);
    }
    if (t2 >= 500000 && sc->focus > 0 && sc->mv_kit->has_reach == 1 &&
    sc->atk == 0) {
        deal_damage(sc);
        sfClock_restart(sc->atk_rate);
    }
}