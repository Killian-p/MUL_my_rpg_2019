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

void set_stats_posx(scene_s *sc)
{
    sfVector2f p = sfRectangleShape_getPosition(sc->disp->bg1);
    float x = sc->interface->p.x + 650;
    float y = p.y;

    sfRectangleShape_setPosition(sc->disp->bg1, (sfVector2f){x, y});
    sfRectangleShape_setPosition(sc->disp->bg2, (sfVector2f){x, y + 40});
    sfRectangleShape_setPosition(sc->disp->bg3, (sfVector2f){x, y + 80});
    sfRectangleShape_setPosition(sc->disp->bg4, (sfVector2f){x, y + 130});
    x += 2;
    sfRectangleShape_setPosition(sc->disp->red, (sfVector2f){x, y + 2});
    sfRectangleShape_setPosition(sc->disp->blue, (sfVector2f){x, y + 42});
    sfRectangleShape_setPosition(sc->disp->green, (sfVector2f){x, y + 82});
    sfRectangleShape_setPosition(sc->disp->exp, (sfVector2f){x, y + 132});
    set_pos_gutletx(sc);
}

void set_stats_posy(scene_s *sc)
{
    sfVector2f p = sfRectangleShape_getPosition(sc->disp->bg1);
    float y = sc->interface->p.y + 895;
    float x = p.x;

    sfRectangleShape_setPosition(sc->disp->bg1, (sfVector2f){x, y});
    sfRectangleShape_setPosition(sc->disp->bg2, (sfVector2f){x, y + 40});
    sfRectangleShape_setPosition(sc->disp->bg3, (sfVector2f){x, y + 80});
    sfRectangleShape_setPosition(sc->disp->bg4, (sfVector2f){x, y + 130});
    x += 2;
    sfRectangleShape_setPosition(sc->disp->red, (sfVector2f){x, y + 2});
    sfRectangleShape_setPosition(sc->disp->blue, (sfVector2f){x, y + 42});
    sfRectangleShape_setPosition(sc->disp->green, (sfVector2f){x, y + 82});
    sfRectangleShape_setPosition(sc->disp->exp, (sfVector2f){x, y + 132});
    set_pos_gutlety(sc);
}

int init_exp_bar(scene_s *sc)
{
    sc->disp->exp = sfRectangleShape_create();
    sc->disp->bg4 = sfRectangleShape_create();
    if (!sc->disp->exp || !sc->disp->bg4)
        return 84;
    sfRectangleShape_setFillColor(sc->disp->exp, sfWhite);
    sfRectangleShape_setFillColor(sc->disp->bg4, sfBlack);
    sfRectangleShape_setPosition(sc->disp->bg4, (sfVector2f){650, 1025});
    sfRectangleShape_setPosition(sc->disp->exp, (sfVector2f){652, 1027});
    sfRectangleShape_setSize(sc->disp->exp, (sfVector2f){546, 13});
    sfRectangleShape_setSize(sc->disp->bg4, (sfVector2f){550, 15});
    return 0;
}