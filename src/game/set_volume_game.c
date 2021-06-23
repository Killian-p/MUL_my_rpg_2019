/*
** EPITECH PROJECT, 2019
** volume
** File description:
** pause
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "rpg.h"

void check_volume_click(scene_s *sc, float x, float y)
{
    x -= sc->interface->p.x;
    y -= sc->interface->p.y;
    if (x >= 1805 && x <= 1905 && y >= 1040 && y <= 1060)
        sc->switch_volume = 1;
}

void switch_volume_game(scene_s *sc)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(sc->window);
    sfVector2f pos = {mouse.x, mouse.y};
    float res = 0;

    res =  pos.x - 1805;
    if (res < 0)
        sc->volume = 0;
    else if (res > 100)
        sc->volume = 100;
    else
        sc->volume = res;
}

void set_volume_game(scene_s *sc)
{
    int idx = 0;

    if (sc->switch_volume == 1)
        switch_volume_game(sc);
    else
        return;
    while (sc->sound_music->sound[idx] != NULL) {
        sfSound_setVolume(sc->sound_music->sound[idx]->sound, sc->volume);
        idx += 1;
    }
    idx = 0;
    while (sc->sound_music->music[idx] != NULL) {
        sfMusic_setVolume(sc->sound_music->music[idx]->music, sc->volume);
        idx += 1;
    }
}

int init_game_volume_display(scene_s *sc)
{
    sfVector2f p = sc->interface->p;

    p.x += 1805;
    p.y += 1040;
    sc->disp_v[0] = sfRectangleShape_create();
    sc->disp_v[1] = sfRectangleShape_create();
    sc->disp_v[2] = sfRectangleShape_create();
    if (!sc->disp_v[0] || !sc->disp_v[1] || !sc->disp_v[2])
        return (84);
    sfRectangleShape_setPosition(sc->disp_v[0], p);
    sfRectangleShape_setPosition(sc->disp_v[1], p);
    p.y -= 10;
    sfRectangleShape_setPosition(sc->disp_v[2], p);
    sfRectangleShape_setSize(sc->disp_v[0], (sfVector2f){100, 20});
    sfRectangleShape_setSize(sc->disp_v[1], (sfVector2f){100, 20});
    sfRectangleShape_setSize(sc->disp_v[2], (sfVector2f){10, 40});
    sfRectangleShape_setFillColor(sc->disp_v[0], (sfColor){0, 100, 0, 255});
    sfRectangleShape_setFillColor(sc->disp_v[1], (sfColor){255, 255, 0, 255});
    sfRectangleShape_setFillColor(sc->disp_v[2], (sfColor){0, 0, 255, 255});
    return (0);
}