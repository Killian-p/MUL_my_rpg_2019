/*
** EPITECH PROJECT, 2020
** destroy pnj quest
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

void destroy_pnj(pnj_t *all)
{
    pnj_t *pnj = all;

    while (pnj) {
        all = all->next;
        sfClock_destroy(pnj->clock);
        sfTexture_destroy(pnj->pnj_t);
        sfSprite_destroy(pnj->pnj_s);
        sfText_destroy(pnj->name->text);
        sfFont_destroy(pnj->name->font);
        free(pnj);
        pnj = all;
    }
}

void destroy_texts(sfText **text)
{
    int idx = 0;

    while (text[idx]) {
        sfText_destroy(text[idx]);
        idx += 1;
    }
    free(text);
}