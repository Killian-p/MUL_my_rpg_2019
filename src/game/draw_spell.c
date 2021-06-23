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

void draw_spell_anim(scene_s *sc)
{
    int t = sfClock_getElapsedTime(sc->spell->spell->clock).microseconds;

    if (sc->spell->anim == 1) {
        sfRenderWindow_drawSprite(sc->window, sc->spell->spell->sprite, NULL);
        if (t >= 50000) {
            anim_offset(sc->spell->spell, 2250, 250);
            sfClock_restart(sc->spell->spell->clock);
        }
        if (sc->spell->spell->rect.left == 2000) {
            sc->spell->anim = 0;
            sc->spell->spell->rect.left = 0;
        }
    }
}