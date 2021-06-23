/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>

#include "rpg.h"

void set_levitation(items_s *tmp)
{
    int t = sfClock_getElapsedTime(tmp->obj->clock).microseconds;

    if (t >= 15000) {
        tmp->obj->p.y += sin(tmp->disp_effect) * 3;
        tmp->disp_effect += 0.1;
        if (tmp->disp_effect == 360)
            tmp->disp_effect = 0;
        sfSprite_setPosition(tmp->obj->sprite, tmp->obj->p);
        sfClock_restart(tmp->obj->clock);
    }
}

void draw_items(scene_s *sc, items_s **items)
{
    items_s *tmp = *items;

    while (tmp != NULL) {
        set_levitation(tmp);
        sfRenderWindow_drawSprite(sc->window, tmp->obj->sprite, NULL);
        tmp = tmp->next;
    }
}

void set_pos_order(items_s *tmp, int idx, scene_s *sc)
{
    sfVector2f p = {1660 + sc->interface->p.x, 890 + sc->interface->p.y};
    int check = 0;

    while (idx > 2) {
        idx -= 1;
        if (check == 1)
            p.x += 68;
        check = 1;
        p.y = 962 + sc->interface->p.y;
    }
    while (idx != 0 && check == 0) {
        p.x += 68;
        idx -= 1;
    }
    sfSprite_setPosition(tmp->obj->sprite, p);
    tmp->obj->p.x = p.x;
    tmp->obj->p.y = p.y;
}

void draw_player_items(scene_s *sc, items_s **items)
{
    items_s *tmp = *items;
    int idx = 0;

    while (tmp != NULL) {
        set_pos_order(tmp, idx, sc);
        sfRenderWindow_drawSprite(sc->window, tmp->obj->sprite, NULL);
        tmp = tmp->next;
        idx += 1;
    }
}