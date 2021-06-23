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

game_object *create_obj(const char *path_to_spritesheet,
                    sfVector2f pos, sfIntRect rect, float speed)
{
    struct game_object *object = malloc(sizeof(game_object));
    object->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    object->sprite = sfSprite_create();

    if (!object || !object->texture || !object->sprite)
        return NULL;
    object->p = pos;
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, rect);
    sfSprite_setPosition(object->sprite, pos);
    object->rect = rect;
    object->clock = sfClock_create();
    object->speed = speed;
    object->disp = 1;
    return (object);
}

int set_graphics_totem(items_s *dag, enn_s *tmp, char *path)
{
    sfIntRect r = {0, 0, 160, 160};
    sfVector2f p = {tmp->obj->p.x, tmp->obj->p.y};

    dag->obj = create_obj(path, p, r, 0);
    if (!dag->obj)
        return 84;
    sfSprite_setOrigin(dag->obj->sprite, (sfVector2f){16, 16});
    sfSprite_setScale(dag->obj->sprite, (sfVector2f){0.5, 0.5});
    return (0);
}