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

int add_vitality(skill_s *skillpt)
{
    if (skillpt->skillpoints > 0) {
        skillpt->vitality += 1;
        skillpt->skillpoints -= 1;
        return (1);
    }
    return (3);
}

int reset(skill_s *skillpt)
{
    if (skillpt->reset == 0) {
        init_skill_point(skillpt, 0, "");
        return (2);
    }
    return (0);
}

int volume_setting(skill_s *skillpt)
{
    (void)skillpt;
    return (8);
}