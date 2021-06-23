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

int in_range(enn_s *tmp, game_object *player)
{
    float x = tmp->obj->p.x - 20;
    float x2 = tmp->obj->p.x + tmp->obj->scale.x * tmp->obj->rect.width;
    float x3 = tmp->obj->p.x + (tmp->obj->scale.x * tmp->obj->rect.width) / 2;
    float y = tmp->obj->p.y + (tmp->obj->scale.y * tmp->obj->rect.height) / 2;

    if (x >= player->p.x + 10 && x <= player->p.x + 250 &&
    y >= player->p.y && y <= player->p.y + 400)
        return (1);
    if (x2 >= player->p.x + 10 && x2 <= player->p.x + 250 &&
        y >= player->p.y && y <= player->p.y + 400)
        return (1);
    if (x3 >= player->p.x + 10 && x3 <= player->p.x + 250 &&
        y >= player->p.y && y <= player->p.y + 400)
        return (1);
    return (0);
}

void draw_atk(scene_s *sc)
{
    if (enn_offset(sc->player, 288, 48) == 1) {
        sc->atk = 0;
        if (sc->run == 1) {
            sc->player->texture = get_texture(sc);
            sfSprite_setTexture(sc->player->sprite, sc->player->texture, 0);
        } else if (sc->focus == 0){
            sc->player->texture = get_idle(sc);
            sfSprite_setTexture(sc->player->sprite, sc->player->texture, 0);
            sfSprite_setTexture(sc->head->sprite, sc->player->texture, 0);
        } else {
            sc->player->texture = get_attack(sc);
            sfSprite_setTexture(sc->player->sprite, sc->player->texture, 0);
            sfSprite_setTexture(sc->head->sprite, sc->player->texture, 0);
        }
    }
}

void take_damage(enn_s *tmp, scene_s *sc, int type)
{
    int crit = rand() % 100;
    float armor = (100 - sc->stats->physical_armor) / 100;

    armor += (100 - sc->stats->magical_armor) / 100;
    if (armor <= 0.1)
        armor = 0.01;
    tmp->life -= (sc->stats->physical_attack * type) * armor;
    if (sc->stats->crit_rate <= crit) {
        tmp->life -= sc->stats->crit_dmg;
    }
}

void anim_atk(scene_s *sc, int t)
{
    if (t >= 100000) {
        draw_atk(sc);
        sfClock_restart(sc->player->clock);
    }
}

void deal_damage(scene_s *sc)
{
    enn_s *tmp = sc->enn;
    int idx = 0;

    while (idx != sc->focus - 1) {
        idx += 1;
        tmp = tmp->next;
    }
    take_damage(tmp, sc, 1);
}