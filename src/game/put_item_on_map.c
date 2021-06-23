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

void put_on_map(items_s *item, items_s **ref, scene_s *sc)
{
    items_s *tmp = *ref;

    item->next = NULL;
    item->obj->p.x = sc->player->p.x;
    item->obj->p.y = sc->player->p.y;
    sfSprite_setScale(item->obj->sprite, (sfVector2f){2, 2});
    if (item == NULL)
        return;
    if (tmp == NULL) {
        *ref = item;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = item;
}

int error_drop(int idx, items_s **ref)
{
    items_s *tmp = *ref;
    int idx2 = 0;

    if (idx == -1)
        return (84);
    while (tmp != NULL) {
        tmp = tmp->next;
        idx2 += 1;
    }
    if (idx2 <= idx)
        return (84);
    return (0);
}