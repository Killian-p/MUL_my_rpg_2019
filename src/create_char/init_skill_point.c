/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "create_char.h"
#include "math.h"

void set_skill_text(sfText* *texts, skill_s *skillpoint)
{
    int idx = 8;

    while (idx <= 14) {
        sfText_setString(texts[idx], get_skill(idx, skillpoint));
        idx += 1;
    }
}

void init_skill_point(skill_s *skillpoint, int bool, char *name)
{
    if (bool == 0) {
        skillpoint->skillpoints = 10;
        skillpoint->accuracy = 0;
        skillpoint->stamina = 0;
        skillpoint->strength = 0;
        skillpoint->chance = 0;
        skillpoint->vitality = 0;
        skillpoint->intelligence = 0;
        skillpoint->skillpoints = 10;
        skillpoint->type_char = 10;
        skillpoint->reset = 0;
    } else {
        parsed_stats(name, skillpoint);
    }
}