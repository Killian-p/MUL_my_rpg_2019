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

int check_click_in_items(sfMouseButtonEvent m)
{
    sfVector2f p = {1660, 890};
    sfVector2f p2 = {1820, 985};

    if (m.x >= p.x && m.x <= p2.x && m.y >= p.y && m.y <= p2.y)
        return (1);
    return (0);
}

int compare_pos(items_s *tmp, sfMouseButtonEvent m, scene_s *sc)
{
    sfVector2f cmp = tmp->obj->p;

    cmp.x -= sc->interface->p.x;
    cmp.y -= sc->interface->p.y;
    if (m.x >= cmp.x - 32 && m.x <= cmp.x + 32 &&
    m.y >= cmp.y - 32 && m.y <= cmp.y + 32)
        return (1);
    return (0);
}

void drop_from_inv(scene_s *sc, int idx, items_s **ref2)
{
    items_s *tmp2 = *ref2;
    items_s *prev2 = *ref2;
    int idx2 = 0;

    if (error_drop(idx, ref2) == 84)
        return;
    if (idx == 0) {
        *ref2 = tmp2->next;
        put_on_map(tmp2, &sc->items, sc);
        return;
    }
    while (idx2 != idx) {
        idx2 += 1;
        prev2 = tmp2;
        tmp2 = tmp2->next;
    }
    prev2->next = tmp2->next;
    put_on_map(tmp2, &sc->items, sc);
}

int idrop(sfMouseButtonEvent m, items_s **ref, scene_s *sc)
{
    items_s *tmp = *ref;
    int idx = 0;

    while (tmp != NULL) {
        if (compare_pos(tmp, m, sc) == 1)
            return (idx);
        tmp = tmp->next;
        idx += 1;
    }
    return (-1);
}

void check_drop_item(scene_s *sc, sfMouseButtonEvent m)
{
    if (sc->player_items == NULL) {
        return;
    }
    if (check_click_in_items(m) == 1) {
        drop_from_inv(sc, idrop(m, &sc->player_items, sc), &sc->player_items);
    }
}