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

int add_strength(skill_s *skillpt)
{
    if (skillpt->skillpoints > 0) {
        skillpt->strength += 1;
        skillpt->skillpoints -= 1;
        return (1);
    }
    return (3);
}

int add_intelligence(skill_s *skillpt)
{
    if (skillpt->skillpoints > 0) {
        skillpt->skillpoints -= 1;
        skillpt->intelligence += 1;
        return (1);
    }
    return (3);
}

int add_stamina(skill_s *skillpt)
{
    if (skillpt->skillpoints > 0) {
        skillpt->skillpoints -= 1;
        skillpt->stamina += 1;
        return (1);
    }
    return (3);
}

int add_accuracy(skill_s *skillpt)
{
    if (skillpt->skillpoints > 0) {
        skillpt->skillpoints -= 1;
        skillpt->accuracy += 1;
        return (1);
    }
    return (3);
}

int add_chance(skill_s *skillpt)
{
    if (skillpt->skillpoints > 0) {
        skillpt->chance += 1;
        skillpt->skillpoints -= 1;
        return (1);
    }
    return (3);
}