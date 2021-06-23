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

int set_stats(scene_s *sc)
{
    sc->stats = malloc(sizeof(player_t));
    if (!sc->stats)
        return 84;
    sc->stats->life = 100 + 10 * sc->skills->vitality;
    sc->stats->physical_armor = 3 + 1 * sc->skills->strength;
    sc->stats->magical_armor = 3 + 1 * sc->skills->intelligence;
    sc->stats->physical_attack = 20 + 2 * sc->skills->strength;
    sc->stats->magical_attack = 50 + 4 * sc->skills->intelligence;
    sc->stats->magic = 100 + 5 * sc->skills->intelligence;
    sc->stats->crit_rate = 5 + 1 * sc->skills->accuracy ;
    sc->stats->crit_dmg = 120 + 15 * sc->skills->strength;
    sc->stats->miss_chance = 5 + 4 * sc->skills->chance;
    sc->stats->stamina = 100 + 15 * sc->skills->stamina;
    sc->stats->exp = 0;
    sc->stats->lvl = 0;
    sc->stats->crit_rate += 2 * sc->skills->chance;
    sc->stats->crit_dmg += 10 * sc->skills->accuracy;
    sc->stats->physical_armor += 1 * sc->skills->vitality;
    return 0;
}

int continue_init_disp(scene_s * sc)
{
    sfRectangleShape_setFillColor(sc->disp->bg1, sfBlack);
    sfRectangleShape_setFillColor(sc->disp->bg2, sfBlack);
    sfRectangleShape_setFillColor(sc->disp->bg3, sfBlack);
    sfRectangleShape_setPosition(sc->disp->red, (sfVector2f){652, 897});
    sfRectangleShape_setPosition(sc->disp->blue, (sfVector2f){652, 937});
    sfRectangleShape_setPosition(sc->disp->green, (sfVector2f){652, 977});
    sfRectangleShape_setPosition(sc->disp->bg1, (sfVector2f){650, 895});
    sfRectangleShape_setPosition(sc->disp->bg2, (sfVector2f){650, 935});
    sfRectangleShape_setPosition(sc->disp->bg3, (sfVector2f){650, 975});
    sfRectangleShape_setSize(sc->disp->red, (sfVector2f){331, 26});
    sfRectangleShape_setSize(sc->disp->green, (sfVector2f){331, 26});
    sfRectangleShape_setSize(sc->disp->blue, (sfVector2f){331, 26});
    sfRectangleShape_setSize(sc->disp->bg1, (sfVector2f){335, 30});
    sfRectangleShape_setSize(sc->disp->bg2, (sfVector2f){335, 30});
    sfRectangleShape_setSize(sc->disp->bg3, (sfVector2f){335, 30});
    if (init_exp_bar(sc) == 84)
        return 84;
    return (0);
}

int set_disp_stats(scene_s *sc)
{
    sc->disp = malloc(sizeof(stats_s));
    if (sc->disp == NULL)
        return (84);
    sc->disp->life = sc->stats->life;
    sc->disp->magic = sc->stats->magic;
    sc->disp->stamina = sc->stats->stamina;
    sc->disp->red = sfRectangleShape_create();
    sc->disp->green = sfRectangleShape_create();
    sc->disp->blue = sfRectangleShape_create();
    sc->disp->bg1 = sfRectangleShape_create();
    sc->disp->bg2 = sfRectangleShape_create();
    sc->disp->bg3 = sfRectangleShape_create();
    if (!sc->disp->red || !sc->disp->green || !sc->disp->blue
    || !sc->disp->bg1 || !sc->disp->bg2 || !sc->disp->bg3)
        return 84;
    sfRectangleShape_setFillColor(sc->disp->red, sfRed);
    sfRectangleShape_setFillColor(sc->disp->green, sfGreen);
    sfRectangleShape_setFillColor(sc->disp->blue, sfBlue);
    if (continue_init_disp(sc) == 84)
        return 84;
    return (0);
}

void set_size(scene_s *sc)
{
    sfVector2f size = {331, 26};

    size.x *= get_coeff(sc->disp->life, sc->stats->life);
    sfRectangleShape_setSize(sc->disp->red, size);
    size.x = 331;
    size.x *= get_coeff(sc->disp->magic, sc->stats->magic);
    sfRectangleShape_setSize(sc->disp->blue, size);
    size.x = 331;
    size.x *= get_coeff(sc->disp->stamina, sc->stats->stamina);
    sfRectangleShape_setSize(sc->disp->green, size);
    size.x = 650;
    size.y = 13;
    size.x *= get_coeff(sc->stats->exp, 100 * 1.25 * (sc->stats->lvl + 1));
    sfRectangleShape_setSize(sc->disp->exp, size);
}

void draw_stats(scene_s *sc)
{
    set_size(sc);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->bg1, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->bg2, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->bg3, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->bg4, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->red, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->blue, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->green, NULL);
    sfRenderWindow_drawRectangleShape(sc->window, sc->disp->exp, NULL);
    draw_gutlets(sc);
}