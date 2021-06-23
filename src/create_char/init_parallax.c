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

int get_time(int idx, scene_s *sc)
{
    return (sfClock_getElapsedTime(sc->bg[idx]->clock).microseconds);
}

void move_parallax(scene_s *sc)
{
    int i = 0;

    draw_parallax(sc);
    while (i < 11) {
        if (get_time(i, sc) > 25000) {
            sc->bg[i]->position.x -= sc->bg[i]->speed;
            sfClock_restart(sc->bg[i]->clock);
        }
        if (sc->bg[i]->position.x - sc->bg[i]->speed < -1920)
            sc->bg[i]->position.x = 1920;
        if (get_time(i + 11, sc) > 25000) {
            sc->bg[i + 11]->position.x -= sc->bg[i + 11]->speed;
            sfClock_restart(sc->bg[i + 11]->clock);
        }
        if (sc->bg[i + 11]->position.x  - sc->bg[i + 11]->speed < -1920)
            sc->bg[i + 11]->position.x = 1920;
        i += 1;
    }
}

void change_path(int i, char *path)
{
    if (i != 10)
        path[24] = i + 48;
    else {
        path[24] = '0';
        path[23] = '1';
    }
}

void draw_parallax(scene_s *sc)
{
    int i = 10;

    while (i >= 0) {
        if (i == 0)
            sfRenderWindow_drawSprite(sc->window,
            sc->character[sc->nb]->sprite, NULL);
        sfSprite_setPosition(sc->bg[i]->sprite, sc->bg[i]->position);
        sfRenderWindow_drawSprite(sc->window, sc->bg[i]->sprite, NULL);
        sfSprite_setPosition(sc->bg[i + 11]->sprite, sc->bg[i + 11]->position);
        sfRenderWindow_drawSprite(sc->window, sc->bg[i + 11]->sprite, NULL);
        i -= 1;
    }
}

game_object **init_parallax(void)
{
    game_object **layer = malloc(sizeof(game_object *) * 22);
    int i = 0;
    float speed = 6;
    char path[] = "assets/forest/png/layer00.png";

    if (layer == NULL)
        return (NULL);
    while (i < 11) {
        change_path(i, path);
        if (loop_init_parallax(layer, speed, i, path) == 84)
            return (NULL);
        speed = speed / 2;
        i += 1;
    }
    return (layer);
}