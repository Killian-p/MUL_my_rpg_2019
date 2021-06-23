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

void set_volume(sfMusic* music, scene_s *sc)
{
    if (sc->switch_volume == 1)
        switch_volume(sc);
    sfMusic_setVolume(music, sc->volume);
    sfMusic_setVolume(sc->up_sound, sc->volume);
    sfMusic_setVolume(sc->error_sound, sc->volume);
    sfMusic_setVolume(sc->character[0]->sound, sc->volume);
    sfMusic_setVolume(sc->character[1]->sound, sc->volume);
    sfMusic_setVolume(sc->character[2]->sound, sc->volume);
}

void switch_volume(scene_s *sc)
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

void draw_volume(scene_s *sc)
{
    sfVector2f size = {sc->volume, 20};
    sfVector2f pos2 = {1805 + sc->volume, 1030};

    sfRectangleShape_setSize(sc->disp_v[1], size);
    sfRectangleShape_setPosition(sc->disp_v[2], pos2);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp_v[0], NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp_v[1], NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp_v[2], NULL);
}

int init_volume_display(scene_s *sc)
{
    sc->disp_v[0] = sfRectangleShape_create();
    sc->disp_v[1] = sfRectangleShape_create();
    sc->disp_v[2] = sfRectangleShape_create();
    if (!sc->disp_v[0] || !sc->disp_v[1] || !sc->disp_v[2])
        return (84);
    sfRectangleShape_setPosition(sc->disp_v[0], (sfVector2f){1805, 1040});
    sfRectangleShape_setPosition(sc->disp_v[1], (sfVector2f){1805, 1040});
    sfRectangleShape_setPosition(sc->disp_v[2], (sfVector2f){1805, 1030});
    sfRectangleShape_setSize(sc->disp_v[0], (sfVector2f){100, 20});
    sfRectangleShape_setSize(sc->disp_v[1], (sfVector2f){100, 20});
    sfRectangleShape_setSize(sc->disp_v[2], (sfVector2f){10, 40});
    sfRectangleShape_setFillColor(sc->disp_v[0], (sfColor){0, 100, 0, 255});
    sfRectangleShape_setFillColor(sc->disp_v[1], (sfColor){255, 255, 0, 255});
    sfRectangleShape_setFillColor(sc->disp_v[2], (sfColor){0, 0, 255, 255});
    return (0);
}

void destroy_music(scene_s *scene)
{
    sfMusic_destroy(scene->up_sound);
    sfMusic_destroy(scene->error_sound);
    sfMusic_destroy(scene->character[0]->sound);
    sfMusic_destroy(scene->character[1]->sound);
    sfMusic_destroy(scene->character[2]->sound);
}