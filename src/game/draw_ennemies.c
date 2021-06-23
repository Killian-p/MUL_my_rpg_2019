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

int enn_offset(game_object *obj, int max, int offset)
{
    if (obj->rect.left >= max) {
        obj->rect.left = 0;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        return (1);
    }
    obj->rect.left += offset;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return (0);
}

int in_cam_enn(enn_s *tmp, scene_s *sc)
{
    sfVector2f p = sfRectangleShape_getPosition(sc->cam);
    sfVector2f s = sfRectangleShape_getSize(sc->cam);
    float x = tmp->obj->p.x;
    float y = tmp->obj->p.y;

    if (x >= (p.x - s.x / 2) && x <= (p.x + s.x / 2)) {
        if (y >= (p.y - s.y / 2) && y <= (p.y + s.y / 2))
            return (1);
    }
    return (0);
}

void draw_life(enn_s *tmp, scene_s *sc)
{
    sfRectangleShape *total = sfRectangleShape_create();
    sfRectangleShape *actual = sfRectangleShape_create();
    float x = tmp->obj->p.x - 50;
    float y = tmp->obj->p.y;
    float sx = tmp->obj->rect.width + 50;
    float sy = 15;
    float sx2 = sx * get_coeff(tmp->life, tmp->health);

    sfRectangleShape_setFillColor(total, (sfColor){255, 0, 0, 255});
    sfRectangleShape_setFillColor(actual, (sfColor){0, 255, 0, 255});
    sfRectangleShape_setPosition(total, (sfVector2f){x, y});
    sfRectangleShape_setPosition(actual, (sfVector2f){x, y});
    sfRectangleShape_setSize(total, (sfVector2f){sx, sy});
    sfRectangleShape_setSize(actual, (sfVector2f){sx2, sy});
    sfRenderWindow_drawRectangleShape(sc->window, total, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, actual, NULL);
}

void draw_it(enn_s *tmp, scene_s *sc)
{
    int t = sfClock_getElapsedTime(tmp->obj->clock).microseconds;

    draw_life(tmp, sc);
    if (t >= tmp->disp_speed) {
        if (tmp->life > 0)
            enn_offset(tmp->obj, tmp->max, tmp->offset);
        else {
            tmp->anim_death += 1;
            enn_offset(tmp->obj, tmp->max, tmp->offset);
        }
        sfClock_restart(tmp->obj->clock);
    }
    sfRenderWindow_drawSprite(sc->window, tmp->obj->sprite, NULL);
}

void draw_ennemies(scene_s *sc, enn_s **enn)
{
    enn_s *tmp = *enn;

    while (tmp != NULL) {
        if (in_cam_enn(tmp, sc) == 1)
            draw_it(tmp, sc);
        tmp = tmp->next;
    }
}