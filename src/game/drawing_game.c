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

void draw_head(scene_s *sc)
{
    sc->head->rect.left = sc->player->rect.left + 5;
    sc->head->rect.top = sc->player->rect.top + 10;
    sfSprite_setTextureRect(sc->head->sprite, sc->head->rect);
    sfRenderWindow_drawSprite(sc->window, sc->head->sprite, NULL);
}

int in_cam(map_s *tmp, scene_s *sc)
{
    sfVector2f p = sfRectangleShape_getPosition(sc->cam);
    sfVector2f s = sfRectangleShape_getSize(sc->cam);
    float x = tmp->tile->p.x;
    float y = tmp->tile->p.y;

    if (x >= (p.x - s.x / 2) && x <= (p.x + s.x / 2)) {
        if (y >= (p.y - s.y / 2) && y <= (p.y + s.y / 2))
            return (1);
    }
    return (0);
}

void draw_map(map_s **map, scene_s *sc)
{
    map_s *tmp = *map;

    while (tmp != NULL) {
        if (in_cam(tmp, sc) == 1)
            sfRenderWindow_drawSprite(sc->window, tmp->tile->sprite, NULL);
        tmp = tmp->next;
    }
}

void set_interfacex(scene_s *scene, sfVector2f move)
{
    float x = scene->interface->p.x;
    sfVector2f p = scene->player->p;

    if (p.x < (size_map_x - 14) * 80 && p.x > 900) {
        scene->interface->p.x = scene->player->p.x - 900;
        scene->head->p.x = scene->player->p.x - 850;
        move.x = scene->interface->p.x - x;
        sfRectangleShape_move(scene->cam, move);
        sfView_move(scene->view, move);
        sfRenderWindow_setView(scene->window, scene->view);
        sfSprite_setPosition(scene->head->sprite, scene->head->p);
        sfSprite_setPosition(scene->interface->sprite, scene->interface->p);
        set_stats_posx(scene);
        set_texts(scene, move);
    }
}

void set_interfacey(scene_s *scene, sfVector2f move)
{
    sfVector2f p = scene->player->p;
    float y = scene->interface->p.y;

    if (p.y < (size_map_y - 7) * 80 && p.y > 400) {
        scene->interface->p.y = scene->player->p.y - 400;
        scene->head->p.y = scene->player->p.y + 430;
        move.y = scene->interface->p.y - y;
        sfRectangleShape_move(scene->cam, move);
        sfView_move(scene->view, move);
        sfRenderWindow_setView(scene->window, scene->view);
        sfSprite_setPosition(scene->head->sprite, scene->head->p);
        sfSprite_setPosition(scene->interface->sprite, scene->interface->p);
        set_stats_posy(scene);
        set_texts(scene, move);
    }
}