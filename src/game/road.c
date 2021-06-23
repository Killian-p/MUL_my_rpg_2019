/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <time.h>
#include "rpg.h"
#include "math.h"

int get_cover(int savex, int x, int savey, int y)
{
    if (savex == 0 && savey == 0)
        return (0);
    if (savex == 0 && savey == y - 1)
        return (1);
    if (savex == x - 1 && savey == 0)
        return (2);
    if (savex == x - 1 && savey == y - 1)
        return (3);
    if (savey == 0 && savex != 0 && savex != x - 1)
        return (4);
    if (savey != 0 && savey != y - 1 && savex == x - 1)
        return (5);
    if (savey != y - 1 && savex == 0 && savey != 0)
        return (6);
    if (savey == y - 1 && savex != 0 && savex != x - 1)
        return (7);
    return (8);
}

void add_cover(int nb, map_s *tmp, map_s **map)
{
    if (nb == 0)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 0);
    if (nb == 1)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 14);
    if (nb == 2)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 2);
    if (nb == 3)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 16);
    if (nb == 4)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 1);
    if (nb == 5)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 9);
    if (nb == 6)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 7);
    if (nb == 7)
        add_tile(map, tmp->tile->p.x, tmp->tile->p.y, 15);
    if (nb == 8)
        return;
}

void reset_index(int *savex, int *savey, int x)
{
    if (*savex == x) {
        *savex = 0;
        *savey += 1;
    }
}

void set_gravel(sfVector2f p, map_s **map)
{
    map_s *tmp = *map;
    int x = (rand() % 3) + 2;
    int y = (rand() % 3) + 2;
    int savex = 0;
    int savey = 0;

    if (check_for_gravel(p, map, x + 3, y + 3) == 1)
        return;
    while (savey != y && tmp != NULL) {
        if (tmp->tile->p.y == p.y + savey * 80
        && tmp->tile->p.x == p.x + savex * 80) {
            tmp->tile->rect.left = 6 * 16;
            sfSprite_setTextureRect(tmp->tile->sprite, tmp->tile->rect);
            add_cover(get_cover(savex, x, savey, y), tmp, map);
            savex += 1;
        }
        reset_index(&savex, &savey, x);
        tmp = tmp->next;
    }
}

int put_gravel(map_s **map)
{
    int chance = 0;
    map_s *tmp = *map;

    if (map == NULL)
        return (84);
    while (tmp != NULL) {
        chance = rand() % 12;
        if (chance == 2)
            set_gravel(tmp->tile->p, map);
        tmp = tmp->next;
    }
    return (0);
}