/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

void destroy_bat(bat_t *all)
{
    bat_t *bat = all;

    while (bat) {
        all = all->next;
        sfTexture_destroy(bat->bat_t);
        sfSprite_destroy(bat->bat_s);
        free(bat);
        bat = all;
    }
}

void destroy_stat(stats_s *stat)
{
    sfRectangleShape_destroy(stat->bg1);
    sfRectangleShape_destroy(stat->bg2);
    sfRectangleShape_destroy(stat->bg3);
    sfRectangleShape_destroy(stat->bg4);
    sfRectangleShape_destroy(stat->exp);
    sfRectangleShape_destroy(stat->red);
    sfRectangleShape_destroy(stat->blue);
    sfRectangleShape_destroy(stat->green);
    free(stat);
}

void destroy_map(map_s *all)
{
    map_s *map = all;

    while (map) {
        all = all->next;
        sfSprite_destroy(map->tile->sprite);
        sfTexture_destroy(map->tile->texture);
        sfClock_destroy(map->tile->clock);
        free(map);
        map = all;
    }
}

void destroy_spawn(spawn_s *spawn)
{
    spawn_s *sp = spawn;

    while (sp) {
        spawn = spawn->next;
        free(sp);
        sp = spawn;
    }
}

void destroy_enemy(enn_s *all)
{
    enn_s *enn = all;

    while (enn) {
        all = all->next;
        sfTexture_destroy(enn->move);
        sfClock_destroy(enn->atk_rate);
        free(enn->mv_kit);
        sfClock_destroy(enn->obj->clock);
        sfTexture_destroy(enn->obj->texture);
        sfSprite_destroy(enn->obj->sprite);
        free(enn);
        enn = all;
    }
}