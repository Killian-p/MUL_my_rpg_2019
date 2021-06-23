/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>

#include "rpg.h"

void add_to_spawn(spawn_s *spawn, spawn_s **ref)
{
    spawn_s *tmp = *ref;

    if (tmp == NULL) {
        *ref = spawn;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = spawn;
}

int add_spawn_point(float y, float width, scene_s *sc, float height)
{
    spawn_s *spawn = malloc(sizeof(spawn_s));
    static int type = 1;

    if (!spawn)
        return (84);
    spawn->pos.x = 0;
    spawn->pos.y = y;
    spawn->size.x = width;
    spawn->size.y = height;
    spawn->nb_enn = 0;
    spawn->type = type;
    spawn->next = NULL;
    type += 1;
    if (type == 4)
        type = 0;
    add_to_spawn(spawn, &sc->spawner);
    return (0);
}

int init_spawner(scene_s *sc)
{
    float y = 2000;
    float width = size_map_x * 80;
    float add = (size_map_y * 80 - 2000) / 3;

    sc->spawner = NULL;
    sc->spawn_rate = sfClock_create();
    if ((size_map_y * 80 - 2000) / 3 <= 1000)
        add = 2500;
    while (y <= size_map_y * 80) {
        if (add_spawn_point(y, width, sc, add) == 84)
            return (84);
        y += add;
    }
    return (0);
}
