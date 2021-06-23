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

int loop_init_parallax(game_object **layer, float speed, int i, char *path)
{
    sfVector2f pos = {0, 0};
    sfVector2f pos2 = {1920, 0};
    sfIntRect rect = {0, 0, 828, 793};

    if ((layer[i] = create_object(path, pos, rect, speed)) == NULL)
        return (84);
    sfSprite_setScale(layer[i]->sprite, (sfVector2f){2.32, 1.362});
    if ((layer[i + 11] = create_object(path, pos2, rect, speed)) == NULL)
        return (84);
    sfSprite_setScale(layer[i + 11]->sprite, (sfVector2f){2.32, 1.362});
    return (0);
}