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
#include <math.h>

int bad_number(int nb)
{
    if (nb >= 0 && nb <= 2)
        return (1);
    if (nb >= 7 && nb <= 9)
        return (1);
    if (nb >= 14 && nb <= 16)
        return (1);
    if (nb == 6 || nb == 13 || nb == 20)
        return (1);
    return (0);
}

sfIntRect get_rect(int nb)
{
    sfIntRect rect = {0, 0, 16, 16};

    while (nb >= 7) {
        nb = nb - 7;
        rect.top += 16;
    }
    rect.left = nb * 16;
    return (rect);
}

void add_node(map_s **map, map_s *part)
{
    map_s *tmp = *map;

    if (tmp == NULL) {
        *map = part;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = part;
}

int add_tile(map_s **map, int idx, int idy, int nb)
{
    sfVector2f pos = {idx, idy};
    sfIntRect rect = get_rect(nb);
    sfVector2f scale = {5, 5};
    map_s *part = malloc(sizeof(map_s));

    if (!part)
        return (84);
    part->next = NULL;
    part->tile = create_obj("assets/Grass.png", pos, rect, 0);
    if (part->tile == NULL)
        return (84);
    sfSprite_setScale(part->tile->sprite, scale);
    add_node(map, part);
    return (0);
}

map_s *create_map(scene_s *scene)
{
    loading_t *load = create_load();
    int idx = 0;
    int idy = 0;
    map_s *map = NULL;
    int nb = 0;

    while (idy <= size_map_y * 80) {
        nb = rand() % 20;
        while (bad_number(nb) == 1)
            nb = 10;
        if (add_tile(&map, idx, idy, nb) == 84)
            return (NULL);
        create_map_loop(&idx, &idy);
        load->total_load += 1;
        display_loading(load, scene);
    }
    if (put_gravel(&map) == 84)
        return (NULL);
    return (map);
}