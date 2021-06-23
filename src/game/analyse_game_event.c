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

void slash_atk(scene_s *sc)
{
    enn_s *tmp = sc->enn;

    sc->player->rect.left = 0;
    sc->disp->stamina -= 20;
    sc->player->texture = get_slash(sc);
    sfSprite_setTexture(sc->player->sprite, sc->player->texture, 0);
    sc->head->texture = get_slash(sc);
    sfSprite_setTexture(sc->head->sprite, sc->head->texture, 0);
    sc->atk = 1;
    while (tmp != NULL) {
        if (in_range(tmp, sc->player) == 1)
            take_damage(tmp, sc, 2);
        tmp = tmp->next;
    }
}

void gkey_managing(scene_s *sc, sfEvent event, pnj_quest_t *pq)
{
    if (event.key.code == sfKeyEscape)
        sc->pause->in_pause = 1;
    if (event.key.code == sfKeyA && sc->atk == 0
    && sc->disp->stamina >= 15 && pq->in_speak == 0)
        slash_atk(sc);
    if (event.key.code == sfKeyEnter)
        scenario(sc, pq);
    if (event.key.code == sfKeyZ) {
        if (sc->spell->cast == 0 && sc->disp->magic >= 80) {
            sc->disp->magic -= 80;
            sc->spell->cast = 1;
        } else if (sc->spell->cast == 1) {
            sc->disp->magic += 80;
            sc->spell->cast = 0;
        }
    }
}

void set_target(scene_s *sc, sfMouseButtonEvent m)
{
    float x = m.x + sc->interface->p.x;
    float y = m.y + sc->interface->p.y;

    if (click_on_ennemy(sc, x, y) == 1 || clic_item(sc, m, &sc->items) == 1)
        return;
    sc->focus = 0;
    sc->get_item = 0;
    if (sc->interface->p.x >= (size_map_x - 24) * 80)
        x = (size_map_x - 24) * 80 + m.x - 100;
    if (sc->interface->p.y >= (size_map_y - 14) * 80)
        y = (size_map_y - 14) * 80 + m.y + 50;
    sc->mv_kit->target.x = x;
    if (sc->player->p.x - sc->mv_kit->target.x == 0)
        x += 1;
    target_managing(sc, x, y);
}

void change_sprite(scene_s *sc)
{
    sfVector2f scale = {4, 4};

    if (sc->player->p.x > sc->mv_kit->target.x) {
        scale.x *= -1;
    }
    sfSprite_setScale(sc->player->sprite, scale);
    if (sc->run == 0) {
        sc->player->rect.left = 0;
        sfSprite_setTextureRect(sc->player->sprite, sc->player->rect);
        sfSprite_setTextureRect(sc->head->sprite, sc->head->rect);
    }
    sfTexture *t = get_texture(sc);
    sfSprite_setTexture(sc->player->sprite, t, 0);
    sfSprite_setTexture(sc->head->sprite, t, 0);
    sc->run = 1;
}

void manage_game_click(sfMouseButtonEvent m, scene_s *sc)
{
    if (m.button == sfMouseRight && sc->atk == 0) {
        if (click_is_in_house(sc->bat, m, sc->interface->p) == 0) {
            set_target(sc, m);
            change_sprite(sc);
            sc->mv_kit->has_reach = 0;
        }
    }
    if (m.button == sfMouseLeft) {
        if (sc->skills->skillpoints > 0)
            check_skill_tree(m, sc, sc->skills);
        if (sc->spell->cast == 1) {
            cast_spell(sc, m);
            sc->spell->cast = 0;
        }
        check_drop_item(sc, m);
    }
}