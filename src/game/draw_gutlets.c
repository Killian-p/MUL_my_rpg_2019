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

void set_pos_gutletx(scene_s *sc)
{
    sfVector2f p = sfSprite_getPosition(sc->gutlet->green->sprite);
    float x = sc->interface->p.x + 1100;
    float y = p.y;

    sfSprite_setPosition(sc->gutlet->green->sprite, (sfVector2f){x, y});
    sfSprite_setPosition(sc->gutlet->blue->sprite, (sfVector2f){x, y + 40});
    sfSprite_setPosition(sc->gutlet->red->sprite, (sfVector2f){x, y + 80});
    x += 40;
    sfText_setPosition(sc->gutlet->text[0], (sfVector2f){x, y});
    sfText_setPosition(sc->gutlet->text[1], (sfVector2f){x, y + 40});
    sfText_setPosition(sc->gutlet->text[2], (sfVector2f){x, y + 80});
}

void set_pos_gutlety(scene_s *sc)
{
    sfVector2f p = sfSprite_getPosition(sc->gutlet->green->sprite);
    float y = sc->interface->p.y + 895;
    float x = p.x;

    sfSprite_setPosition(sc->gutlet->green->sprite, (sfVector2f){x, y});
    sfSprite_setPosition(sc->gutlet->blue->sprite, (sfVector2f){x, y + 40});
    sfSprite_setPosition(sc->gutlet->red->sprite, (sfVector2f){x, y + 80});
    x += 40;
    sfText_setPosition(sc->gutlet->text[0], (sfVector2f){x, y});
    sfText_setPosition(sc->gutlet->text[1], (sfVector2f){x, y + 40});
    sfText_setPosition(sc->gutlet->text[2], (sfVector2f){x, y + 80});
}

void draw_gutlets(scene_s *sc)
{
    sfRenderWindow_drawSprite(sc->window, sc->gutlet->red->sprite, NULL);
    sfRenderWindow_drawSprite(sc->window, sc->gutlet->blue->sprite, NULL);
    sfRenderWindow_drawSprite(sc->window, sc->gutlet->green->sprite, NULL);
    sfRenderWindow_drawText(sc->window, sc->gutlet->text[0], NULL);
    sfRenderWindow_drawText(sc->window, sc->gutlet->text[1], NULL);
    sfRenderWindow_drawText(sc->window, sc->gutlet->text[2], NULL);
}