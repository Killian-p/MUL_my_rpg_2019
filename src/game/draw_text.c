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

void draw_text(scene_s *sc)
{
    int idx = 0;

    while (sc->tuto[idx] != NULL) {
        sfRenderWindow_drawText(sc->window, sc->tuto[idx], NULL);
        idx += 1;
    }
}

void move_buttons_text(scene_s *sc, sfVector2f move, button_s **ref)
{
    button_s *tmp = *ref;
    int idx = 0;

    while (tmp != NULL) {
        sfSprite_move(tmp->plus->sprite, move);
        tmp = tmp->next;
    }
    while (sc->skills_text[idx] != NULL) {
        sfText_move(sc->skills_text[idx], move);
        idx += 1;
    }
}

void set_texts(scene_s *sc, sfVector2f move)
{
    sfVector2f pos = {sc->interface->p.x, sc->interface->p.y};
    int idx = 0;

    pos.x += 50;
    pos.y += 80;
    while (sc->tuto[idx] != NULL) {
        pos.y += 40;
        sfText_setPosition(sc->tuto[idx], pos);
        idx += 1;
    }
    sfSprite_setPosition(sc->banner->sprite,
    (sfVector2f){pos.x - 30, pos.y + 70});
    move_buttons_text(sc, move, &sc->buttons);
}