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

int ping_offset(game_object *obj, int max, int offset)
{
    if (obj->rect.left >= max) {
        obj->rect.left = 0;
        obj->rect.top += offset;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        return (1);
    }
    obj->rect.left += offset;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return (0);
}

void draw_ping(scene_s *sc)
{
    int t = sfClock_getElapsedTime(sc->ping->clock).microseconds;

    if (sc->ping->drawable == 0)
        return;
    if (t >= 20000) {
        ping_offset(sc->ping, 576, 192);
        sfClock_restart(sc->ping->clock);
    }
    if (sc->ping->rect.top == 384 && sc->ping->rect.left == 384) {
        sc->ping->rect.top = 0;
        sc->ping->rect.left = 0;
        sc->ping->drawable = 0;
    }
    sfRenderWindow_drawSprite(sc->window, sc->ping->sprite, NULL);
}