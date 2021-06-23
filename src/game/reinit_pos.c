/*
** EPITECH PROJECT, 2020
** reinit
** File description:
** rpg
*/

#include "rpg.h"

void reinit_pause_text(scene_s *sc, pause_t *pause)
{
    sfVector2f pos_a = {sc->interface->p.x + 855, sc->interface->p.y + 410};
    sfVector2f pos_b = {sc->interface->p.x + 880, sc->interface->p.y + 560};
    sfVector2f pos_c = {sc->interface->p.x + 830, sc->interface->p.y + 710};
    sfVector2f pos_d = {sc->interface->p.x + 890, sc->interface->p.y + 860};
    sfVector2f pos_e = {sc->interface->p.x + 795, sc->interface->p.y + 210};

    sfText_setPosition(pause->text[0]->text, pos_a);
    sfText_setPosition(pause->text[1]->text, pos_b);
    sfText_setPosition(pause->text[2]->text, pos_c);
    sfText_setPosition(pause->text[3]->text, pos_d);
    sfText_setPosition(pause->text[4]->text, pos_e);
}

void reinit_pause_button(scene_s *sc, pause_t *pause)
{
    sfVector2f pos_a = {sc->interface->p.x + 800, sc->interface->p.y + 410};
    sfVector2f pos_b = {sc->interface->p.x + 800, sc->interface->p.y + 560};
    sfVector2f pos_c = {sc->interface->p.x + 800, sc->interface->p.y + 710};
    sfVector2f pos_d = {sc->interface->p.x + 800, sc->interface->p.y + 860};
    sfVector2f scale = {1.5, 1.5};

    sfSprite_setPosition(pause->button[0]->sprite, pos_a);
    sfSprite_setPosition(pause->button[1]->sprite, pos_b);
    sfSprite_setPosition(pause->button[2]->sprite, pos_c);
    sfSprite_setPosition(pause->button[3]->sprite, pos_d);
    sfSprite_setScale(pause->button[0]->sprite, scale);
    sfSprite_setScale(pause->button[1]->sprite, scale);
    sfSprite_setScale(pause->button[2]->sprite, scale);
    sfSprite_setScale(pause->button[3]->sprite, scale);
}