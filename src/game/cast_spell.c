/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include "rpg.h"

int in_spell_area(enn_s *tmp, sfVector2f p)
{
    float x = tmp->obj->p.x;
    float y = tmp->obj->p.y;

    if (sqrt(pow(x - p.x, 2) + pow(y - p.y, 2)) <= 260) {
        return (1);
    }
    return (0);
}

void take_spell_dmg(scene_s *sc, enn_s *tmp)
{
    int rd = rand() % 100;

    tmp->life -= sc->stats->magical_attack * (100 - tmp->m_armor) / 100;
    if (rd <= sc->stats->crit_rate) {
        tmp->life -= sc->stats->crit_dmg;
    }
}

void set_damage_spell(enn_s **ref, scene_s *sc, sfVector2f p)
{
    enn_s *tmp = *ref;

    while (tmp != NULL) {
        if (in_spell_area(tmp, p) == 1)
            take_spell_dmg(sc, tmp);
        tmp = tmp->next;
    }
}

void draw_spell(scene_s *sc)
{
    sfSprite* s = sc->spell->spell_area->sprite;

    sfVector2f p = {0, 0};
    if (sc->spell->cast == 1) {
        p.x = sfMouse_getPosition(NULL).x + sc->interface->p.x;
        p.y = sfMouse_getPosition(NULL).y + sc->interface->p.y;
        sc->spell->spell_area->p = p;
        sfSprite_setPosition(sc->spell->spell_area->sprite, p);
        sfRenderWindow_drawSprite(sc->window, s, NULL);
    }
    draw_spell_anim(sc);
}

void cast_spell(scene_s *sc, sfMouseButtonEvent m)
{
    sc->spell->anim = 1;
    sc->spell->spell->p.x = m.x + sc->interface->p.x;
    sc->spell->spell->p.y = m.y + sc->interface->p.y;
    sfSprite_setPosition(sc->spell->spell->sprite, sc->spell->spell->p);
    set_damage_spell(&sc->enn, sc, sc->spell->spell->p);
}