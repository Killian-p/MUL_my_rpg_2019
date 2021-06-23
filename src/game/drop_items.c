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

int set_graphics_item(items_s *dag, enn_s *tmp, char *path)
{
    sfIntRect r = {0, 0, 32, 32};
    sfVector2f p = {tmp->obj->p.x + 20, tmp->obj->p.y + 25};

    dag->obj = create_obj(path, p, r, 0);
    if (dag->obj == NULL)
        return (84);
    sfSprite_setOrigin(dag->obj->sprite, (sfVector2f){16, 16});
    sfSprite_setScale(dag->obj->sprite, (sfVector2f){2, 2});
    return (0);
}

void add_item(items_s *item, items_s **sc)
{
    items_s *tmp = *sc;

    if (tmp == NULL) {
        *sc = item;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = item;
}

void drop_dagger(scene_s *sc, enn_s *tmp)
{
    items_s *dagger = malloc(sizeof(items_s));

    if (dagger == NULL)
        return;
    dagger->disp_effect = 0;
    dagger->next = NULL;
    dagger->path = "assets/items/3/6.png";
    if (set_graphics_item(dagger, tmp, "assets/items/3/6.png") == 84)
        return;
    if (set_stats_item(dagger, "assets/items/3/6.png") == 84)
        return;
    add_item(dagger, &sc->items);
}

void drop_totem(scene_s *sc, enn_s *tmp)
{
    items_s *totem = malloc(sizeof(items_s));

    if (totem == NULL)
        return;
    totem->next = NULL;
    totem->disp_effect = 0;
    totem->path = "assets/totem.png";
    sc->totem += 1;
    if (set_graphics_totem(totem, tmp, "assets/totem.png") == 84)
        return;
    if (set_stats_item(totem, "assets/items/3/6.png") == 84)
        return;
    add_item(totem, &sc->items);
}

void drop_items(enn_s *tmp, scene_s *sc)
{
    int type = tmp->spawn_number;
    sfText* text = sc->gutlet->text[type - 1];

    sc->stats->exp += tmp->exp;
    sc->gutlet->gutlets[type - 1] += 1;
    sfText_setString(text, int_to_str(sc->gutlet->gutlets[type - 1]));
    if (tmp->tuto == 1) {
        drop_dagger(sc, tmp);
    } else if (tmp->health == 5000) {
        drop_totem(sc, tmp);
    } else {
        drop_random(sc, tmp);
    }
}