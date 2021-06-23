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

sfTexture *get_death_mob(void)
{
    sfTexture *t = NULL;

    t = sfTexture_createFromFile("assets/slime_death.png", NULL);
    return (t);
}

sfTexture *get_atk_enn(void)
{
    sfTexture *t = NULL;

    t = sfTexture_createFromFile("assets/slime_atk.png", NULL);
    return (t);
}

sfTexture *get_move_enn(void)
{
    sfTexture *t = NULL;

    t = sfTexture_createFromFile("assets/slime_jmp.png", NULL);
    return (t);
}

sfTexture *get_idle_enn(void)
{
    sfTexture *t = NULL;

    t = sfTexture_createFromFile("assets/slime_idl.png", NULL);
    return (t);
}