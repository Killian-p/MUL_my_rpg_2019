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

void draw_buttons(scene_s *sc, button_s *button)
{
    button_s *temp = button;

    while (temp != NULL) {
        sfRenderWindow_drawSprite(sc->window, temp->plus->sprite, NULL);
        temp = temp->next;
    }
}

float manage_rotate(float rotate)
{
    static float buff = 0.01;
    int reset = 1;

    if (buff >= 0.06)
        reset = -1;
    if (buff <= 0.01)
        reset = 1;
    if (rotate <= 0.782 || (rotate >= 2.355 && rotate <= 3.925)
    || rotate >= 5.495) {
        rotate += 0.01;
        buff = 0.01;
    } else {
        rotate += buff;
        buff += 0.006 * reset;
    }
    if (rotate >= 3.14)
        rotate = 0;
    return (rotate);
}

void draw_enter(scene_s *sc)
{
    static int zoom = 1;
    static float rotate = 0;
    int t = sfClock_getElapsedTime(sc->keys[2]->clock).microseconds;

    if (t >= 30000) {
        sc->keys[2]->scale.y += 0.03 * zoom;
        sc->keys[2]->scale.x += 0.03 * zoom;
        if (sc->keys[2]->scale.x >= 2)
            zoom = -1;
        if (sc->keys[2]->scale.x <= 0.8)
            zoom = 1;
        sfClock_restart(sc->keys[2]->clock);
        rotate = manage_rotate(rotate);
        sfSprite_setRotation(sc->keys[2]->sprite, 360 - 360 * cos(rotate));
    }
    sfSprite_setScale(sc->keys[2]->sprite, sc->keys[2]->scale);
    sfRenderWindow_drawSprite(sc->window, sc->keys[2]->sprite, NULL);
}

void draw_icons(scene_s *sc, skill_s * sk)
{
    static int zoom = 1;
    int t = sfClock_getElapsedTime(sc->keys[0]->clock).microseconds;

    if (t >= 30000) {
        sc->keys[0]->scale.y += 0.03 * zoom;
        sc->keys[0]->scale.x += 0.03 * zoom;
        if (sc->keys[0]->scale.x >= 0.5)
            zoom = -1;
        if (sc->keys[0]->scale.x <= 0.3)
            zoom = 1;
        sfClock_restart(sc->keys[0]->clock);
        sfClock_restart(sc->keys[1]->clock);
    }
    sfSprite_setScale(sc->keys[0]->sprite, sc->keys[0]->scale);
    sfSprite_setScale(sc->keys[1]->sprite, sc->keys[0]->scale);
    sfRenderWindow_drawSprite(sc->window, sc->keys[0]->sprite, NULL);
    sfRenderWindow_drawSprite(sc->window, sc->keys[1]->sprite, NULL);
    if (sk->skillpoints == 0)
        draw_enter(sc);
}