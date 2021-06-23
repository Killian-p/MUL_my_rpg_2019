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

void set_coor(float *x, float *y, scene_s *sc, sfMouseButtonEvent m)
{
    if (sc->player->p.x < m.x + sc->player->p.x - 960) {
        *x += 24 * 4;
        *y += 24 * 4;
    } else {
        *x += 24 * 2.5;
        *y += 24 * 4;
    }
}

void change_to_idle(scene_s *sc)
{
    sc->player->rect.left = 0;
    sfSprite_setTextureRect(sc->player->sprite, sc->player->rect);
    sfSprite_setTextureRect(sc->head->sprite, sc->head->rect);
    sfTexture *t = get_idle(sc);
    sfSprite_setTexture(sc->player->sprite, t, 0);
    sfSprite_setTexture(sc->head->sprite, t, 0);
    sc->run = 0;
}

void change_to_attack(scene_s *sc)
{
    sc->player->rect.left = 0;
    sfSprite_setTextureRect(sc->player->sprite, sc->player->rect);
    sfSprite_setTextureRect(sc->head->sprite, sc->head->rect);
    sfTexture *t = get_attack(sc);
    sfSprite_setTexture(sc->player->sprite, t, 0);
    sfSprite_setTexture(sc->head->sprite, t, 0);
    sc->run = 0;
}

void draw_attack(scene_s *sc, int t)
{
    if (sc->death == 1 && t >= 150000) {
        anim_offset(sc->player, 6 * 48, 48);
        sfClock_restart(sc->player->clock);
        return;
    }
    if (sc->atk == 1)
        anim_atk(sc, t);
    if (t >= 150000) {
        if (sc->run == 0)
            anim_offset(sc->player, 144, 48);
        else
            anim_offset(sc->player, 240, 48);
        sfClock_restart(sc->player->clock);
    }
    if (sc->skills->skillpoints > 0) {
        draw_skill_tree(sc, &sc->buttons);
    }
}