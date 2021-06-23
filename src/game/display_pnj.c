/*
** EPITECH PROJECT, 2020
** display pnj
** File description:
** rpg
*/

#include "rpg.h"

void display_pnj(scene_s *sc, pnj_t *pnj)
{
    int time = 0;

    while (pnj) {
        time = sfClock_getElapsedTime(pnj->clock).microseconds;
        if (time >= 150000) {
            if (pnj->rect.left == 0)
                pnj->rect.left += 55;
            else
                pnj->rect.left = 0;
            sfSprite_setTextureRect(pnj->pnj_s, pnj->rect);
            sfClock_restart(pnj->clock);
        }
        sfRenderWindow_drawSprite(sc->window, pnj->pnj_s, NULL);
        sfRenderWindow_drawText(sc->window, pnj->name->text, NULL);
        pnj = pnj->next;
    }
}