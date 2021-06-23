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

void rm_enn(enn_s **enn, scene_s *sc)
{
    enn_s *tmp = *enn;
    enn_s *prev = *enn;

    if (tmp->life <= 0 && tmp->anim_death >= 10) {
        drop_items(tmp, sc);
        *enn = tmp->next;
        return;
    }
    while ((tmp->life > 0 || tmp->anim_death < 10) && tmp != NULL) {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == NULL)
        return;
    else {
        drop_items(tmp, sc);
        prev->next = tmp->next;
    }
}

void refresh_char_action(scene_s *sc, enn_s **enn)
{
    enn_s *tmp = *enn;
    int idx = 0;

    while (idx != sc->focus - 1) {
        tmp = tmp->next;
        idx += 1;
    }
    if (tmp->life <= 0 && tmp->anim_death == 0) {
        sc->focus = 0;
        tmp->obj->rect.left = 0;
        tmp->obj->texture = get_death_mob();
        sfSprite_setTexture(tmp->obj->sprite, tmp->obj->texture, 0);
        change_action(sc);
    }
}

int deads(scene_s *sc)
{
    enn_s *tmp = sc->enn;

    while (tmp != NULL) {
        if (tmp->life <= 0 && tmp->anim_death >= 10) {
            return (1);
        }
        tmp = tmp->next;
    }
    return (0);
}

void set_anim_death(enn_s **enn)
{
    enn_s *tmp = *enn;

    while (tmp != NULL) {
        if (tmp->life <= 0 && tmp->anim_death == 0 && tmp->spawn_number != 3) {
            tmp->obj->texture = get_death_mob();
            sfSprite_setTexture(tmp->obj->sprite, tmp->obj->texture, 0);
            tmp->max = 704;
        } else if (tmp->life <= 0 && tmp->anim_death == 0 &&
        tmp->spawn_number == 3) {
            tmp->obj->texture = get_death_boss(tmp);
            sfSprite_setTexture(tmp->obj->sprite, tmp->obj->texture, 0);
        }
        tmp = tmp->next;
    }
}

void regen(scene_s *sc)
{
    if (death_player(sc) == 1)
        return;
    if (sc->focus > 0)
        refresh_char_action(sc, &sc->enn);
    set_anim_death(&sc->enn);
    while (deads(sc) == 1)
        rm_enn(&sc->enn, sc);
    regen_stats(sc);
}