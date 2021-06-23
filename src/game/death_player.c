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

void reset_view(scene_s *sc)
{
    float x = sc->interface->p.x;
    float y = sc->interface->p.y;
    sfVector2f move = {0 - x, 0 - y};

    sfRectangleShape_move(sc->cam, move);
    sfView_move(sc->view, move);
}

void reset_pos(scene_s *sc)
{
    sc->player->p.x = 900;
    sc->player->p.y = 400;
    sc->interface->p.x = 0;
    sc->interface->p.y = 0;
    sc->head->p.x = 50;
    sc->head->p.y = 830;
    sc->focus = 0;
    sc->get_item = 0;
    sc->atk = 0;
    sc->run = 0;
    sc->mv_kit->has_reach = 1;
    sfSprite_setPosition(sc->player->sprite, sc->player->p);
    sfSprite_setPosition(sc->interface->sprite, sc->interface->p);
    sfSprite_setPosition(sc->head->sprite, sc->head->p);
}

void reset_stats(scene_s *sc)
{
    float x = sc->player->p.x;
    float y = sc->player->p.y;

    sc->disp->life = sc->stats->life;
    sc->disp->stamina = sc->stats->stamina;
    target_managing(sc, x, y);
}

void anim_death(scene_s *sc)
{
    sfTexture* t = NULL;

    if (sc->nb_char == 0) {
        t = sfTexture_createFromFile("assets/woodcutter/death.png", NULL);
    } else if (sc->nb_char == 1) {
        t = sfTexture_createFromFile("assets/graverobber/death.png", NULL);
    } else {
        t = sfTexture_createFromFile("assets/steamman/death.png", NULL);
    }
    sfSprite_setTexture(sc->player->sprite, t, 0);
}

int death_player(scene_s *sc)
{
    if (sc->disp->life <= 0 && sc->death == 0) {
        sc->death = 1;
        sc->player->rect.left = 0;
        anim_death(sc);
        return (1);
    }
    if (sc->death == 1 && sc->player->rect.left == 5 * 48) {
        reset_view(sc);
        reset_pos(sc);
        reset_stats(sc);
        sc->death = 0;
        sc->player->rect.left = 0;
        sfSprite_setTexture(sc->player->sprite, get_idle(sc), 0);
        return (1);
    }
    if (sc->death > 0)
        return (1);
    return (0);
}