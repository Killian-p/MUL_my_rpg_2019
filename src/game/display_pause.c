/*
** EPITECH PROJECT, 2019
** volume
** File description:
** lobby
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "rpg.h"

void draw_volume_pause(scene_s *sc)
{
    sfVector2f size = {sc->volume, 20};
    sfVector2f pos2 = {1805 + sc->volume, 1030};
    sfVector2f p = {1745 + sc->interface->p.x, 1025 + sc->interface->p.y};

    pos2.x += sc->interface->p.x;
    pos2.y += sc->interface->p.y;
    sfRectangleShape_setSize(sc->disp_v[1], size);
    sfRectangleShape_setPosition(sc->disp_v[2], pos2);
    pos2.x -= sc->volume;
    pos2.y += 10;
    sfRectangleShape_setPosition(sc->disp_v[0], pos2);
    sfRectangleShape_setPosition(sc->disp_v[1], pos2);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp_v[0], NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp_v[1], NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp_v[2], NULL);
    sfSprite_setPosition(sc->sound_music->icon->sprite, p);
    sfRenderWindow_drawSprite(sc->window, sc->sound_music->icon->sprite, NULL);
}

void display_text(text_t **text, scene_s *sc)
{
    int i = 0;

    while (i < 5) {
        if (text[i] != NULL)
            sfRenderWindow_drawText(sc->window, text[i]->text, NULL);
        i += 1;
    }
}

void display_button(button_t **button, scene_s *sc)
{
    int i = 0;

    while (i < 4) {
        if (button[i] != NULL)
            sfRenderWindow_drawSprite(sc->window, button[i]->sprite, NULL);
        i += 1;
    }
}

void display_pause(scene_s *sc)
{
    sfVector2f pos = {0, 0};

    sfSprite_setPosition(sc->pause->back_s, sc->interface->p);
    sfRenderWindow_drawSprite(sc->window, sc->pause->back_s, NULL);
    display_button(sc->pause->button, sc);
    display_text(sc->pause->text, sc);
    draw_volume_pause(sc);
    if (sc->pause->htop == 1) {
        pos.x = sc->interface->p.x + 250;
        pos.y = sc->interface->p.y + 150;
        sfSprite_setPosition(sc->pause->htop_s, pos);
        sfRenderWindow_drawSprite(sc->window, sc->pause->htop_s, NULL);
    }
}