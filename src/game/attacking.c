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

int is_in_hitbox(float x, float y, enn_s *tmp)
{
    sfVector2f pos = tmp->obj->p;
    sfIntRect rect = tmp->obj->rect;

    if (x >= pos.x - 20 && x <= pos.x + rect.width * 2 && y >= pos.y - 20 &&
    y <= pos.y + rect.height * 4)
        return (1);
    return (0);
}

int click_on_ennemy(scene_s *sc, float x, float y)
{
    enn_s *tmp = sc->enn;
    int idx = 0;

    while (tmp != NULL) {
        if (is_in_hitbox(x, y, tmp) == 1) {
            sc->focus = 1 + idx;
            return (1);
        }
        idx += 1;
        tmp = tmp->next;
    }
    return (0);
}

sfVector2f get_target_pos(scene_s *sc)
{
    enn_s *tmp = sc->enn;
    int idx = 0;

    while (idx != sc->focus - 1 && tmp != NULL) {
        tmp = tmp->next;
        idx += 1;
    }
    if (tmp == NULL) {
        return ((sfVector2f){sc->player->p.x, sc->player->p.y});
    } else {
        return ((sfVector2f){tmp->obj->p.x, tmp->obj->p.y});
    }
}

void set_path(scene_s *sc)
{
    sfVector2f target = get_target_pos(sc);
    float x = target.x;
    float y = target.y;
    sfVector2f scale = sfSprite_getScale(sc->player->sprite);

    sc->mv_kit->target.x = x;
    if (sc->player->p.x - sc->mv_kit->target.x == 0)
        x += 1;
    if (sc->player->p.x > target.x && scale.x > 0)
        sfSprite_setScale(sc->player->sprite, (sfVector2f){-4, 4});
    if (sc->player->p.x < target.x && scale.x < 0)
        sfSprite_setScale(sc->player->sprite, (sfVector2f){4, 4});
    target_managing(sc, x, y);
}

void change_action(scene_s *sc)
{
    if (sc->focus == 0 || sc->atk == 1)
        change_to_idle(sc);
    else
        change_to_attack(sc);
}