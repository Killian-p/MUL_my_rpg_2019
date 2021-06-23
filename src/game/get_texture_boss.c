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

sfTexture *get_death_boss(enn_s *enn)
{
    sfTexture *t = NULL;

    enn->max = 10 * 96;
    enn->disp_speed = 150000;
    t = sfTexture_createFromFile("assets/boss/death.png", NULL);
    return (t);
}

sfTexture *get_atk_boss(void)
{
    sfTexture *t = NULL;


    t = sfTexture_createFromFile("assets/boss/basic_atk.png", NULL);
    return (t);
}

sfTexture *get_move_boss(void)
{
    sfTexture *t = NULL;

    t = sfTexture_createFromFile("assets/boss/boss_move.png", NULL);
    return (t);
}

sfTexture *get_idle_boss(void)
{
    sfTexture *t = NULL;

    t = sfTexture_createFromFile("assets/boss/idle.png", NULL);
    return (t);
}