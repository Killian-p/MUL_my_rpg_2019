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

int is_in_hitbox2(float x, float y, items_s *tmp)
{
    sfVector2f pos = tmp->obj->p;

    if (x >= pos.x - 100 && x <= pos.x + 100 && y >= pos.y - 100 &&
        y <= pos.y + 100)
        return (1);
    return (0);
}

sfVector2f get_item_pos(scene_s *sc, items_s **ref)
{
    items_s *tmp = *ref;
    int idx = 0;

    while (idx != sc->get_item - 1) {
        tmp = tmp->next;
        idx += 1;
    }
    if (tmp == NULL) {
        return ((sfVector2f){sc->player->p.x, sc->player->p.y});
    } else {
        return ((sfVector2f){tmp->obj->p.x, tmp->obj->p.y});
    }
}

void set_path_to_item(scene_s *sc)
{
    sfVector2f target = get_item_pos(sc, &sc->items);
    sfVector2f scale = sfSprite_getScale(sc->player->sprite);
    float x = target.x;
    float y = target.y;

    sc->mv_kit->target.x = x;
    if (sc->player->p.x > target.x && scale.x > 0)
        sfSprite_setScale(sc->player->sprite, (sfVector2f){-4, 4});
    if (sc->player->p.x < target.x && scale.x < 0)
        sfSprite_setScale(sc->player->sprite, (sfVector2f){4, 4});
    if (sc->player->p.x - sc->mv_kit->target.x == 0)
        x += 1;
    target_managing(sc, x, y);
}

int clic_item(scene_s *sc, sfMouseButtonEvent m, items_s **ref)
{
    items_s *tmp = *ref;
    float x = m.x + sc->interface->p.x;
    float y = m.y + sc->interface->p.y;
    int idx = 1;

    while (tmp != NULL) {
        if (is_in_hitbox2(x, y, tmp) == 1) {
            sc->focus = 0;
            sc->get_item = idx;
            return (1);
        }
        idx += 1;
        tmp = tmp->next;
    }
    return (0);
}

void reaching_action(scene_s *sc, int has_reach)
{
    if (has_reach == 2) {
        change_action(sc);
        sc->mv_kit->has_reach = 1;
        if (sc->get_item > 0) {
            move_item(sc, &sc->items, &sc->player_items);
            sc->get_item = 0;
        }
    } else
        sc->mv_kit->has_reach = 0;
}