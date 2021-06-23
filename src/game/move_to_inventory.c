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

void adjust_player_stat(items_s *tmp, scene_s *sc)
{
    sc->stats->life += tmp->bonus[0];
    sc->disp->life += tmp->bonus[0];
    sc->stats->physical_armor += tmp->bonus[1];
    sc->stats->magical_armor += tmp->bonus[2];
    sc->stats->physical_attack += tmp->bonus[3];
    sc->stats->magical_attack += tmp->bonus[4];
    sc->stats->magic += tmp->bonus[5];
    sc->disp->magic += tmp->bonus[5];
    sc->stats->crit_rate += tmp->bonus[6];
    sc->stats->crit_dmg += tmp->bonus[7];
    sc->stats->miss_chance += tmp->bonus[8];
    sc->stats->stamina += tmp->bonus[9];
    sc->disp->stamina += tmp->bonus[9];
}

void add_item_to_player(items_s *tmp, items_s **ref, scene_s *sc)
{
    items_s *items = *ref;

    sfSprite_setScale(tmp->obj->sprite, (sfVector2f){1.4, 1.4});
    adjust_player_stat(tmp, sc);
    tmp->next = NULL;
    if (items == NULL) {
        *ref = tmp;
        return;
    }
    while (items->next != NULL) {
        items = items->next;
    }
    items->next = tmp;
}

int nb_item_inv(items_s **ref)
{
    items_s *tmp = *ref;
    int idx = 0;

    while (tmp != NULL) {
        tmp = tmp->next;
        idx += 1;
    }
    return (idx);
}

void move_item(scene_s *sc, items_s **items, items_s **player)
{
    items_s *prev = *items;
    items_s *tmp = *items;
    int idx = 0;

    if (nb_item_inv(player) == 6)
        return;
    if (idx == sc->get_item - 1)        {
        *items = tmp->next;
        add_item_to_player(tmp, player, sc);
        return;
    }
    while (idx != sc->get_item - 1) {
        prev = tmp;
        tmp = tmp->next;
        idx += 1;
    }
    prev->next = tmp->next;
    add_item_to_player(tmp, player, sc);
}