/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stddef.h>

#include "rpg.h"

int more_init_slime(enn_s *enn, spawn_s *tmp, int drop_chance, int exp)
{
    enn->anim_death = 0;
    enn->spawn_number = tmp->type;
    enn->next = NULL;
    enn->tuto = 0;
    enn->exp = exp;
    enn->focus = 0;
    enn->m_armor = 0;
    enn->has_reach = 0;
    enn->drop_chance = drop_chance;
    enn->move = get_move_enn();
    enn->atk = get_atk_enn();
    enn->idle = get_idle_enn();
    enn->trigger.x = 250;
    enn->trigger.y = 250;
    enn->disp_speed = 150000;
    enn->offset = 64;
    enn->atk_rate = sfClock_create();
    if ((enn->mv_kit = malloc(sizeof(move_s))) == NULL)
        return (84);
    return (0);
}

int create_green_slime(enn_s *enn, spawn_s *tmp)
{
    int x = tmp->size.x;
    int y = tmp->size.y;
    sfVector2f pos = {rand() % x, tmp->pos.y + rand() % y};
    sfVector2f s = {6, 6};
    sfIntRect r = {0, 0, 64, 41};

    enn->max = 192;
    enn->life = 250;
    enn->health = 250;
    enn->p_armor = 0;
    enn->damage = 10;
    enn->type_dmg = 0;
    if (more_init_slime(enn, tmp, 5, 10) == 84)
        return (84);
    if ((enn->obj = create_obj("assets/slime_idl.png", pos, r, 5)) == NULL)
        return (84);
    sfSprite_setOrigin(enn->obj->sprite, (sfVector2f){32, 20.5});
    sfSprite_setPosition(enn->obj->sprite, pos);
    enn->obj->scale = s;
    sfSprite_setScale(enn->obj->sprite, (sfVector2f){6, 6});
    return (0);
}

int create_blue_slime(enn_s *enn, spawn_s *tmp)
{
    int x = tmp->size.x;
    int y = tmp->size.y;
    sfVector2f pos = {rand() % x, tmp->pos.y + rand() % y};
    sfVector2f s = {6, 6};
    sfIntRect r = {0, 41, 64, 41};

    enn->max = 192;
    enn->life = 400;
    enn->health = 400;
    enn->p_armor = 0;
    enn->damage = 25;
    enn->type_dmg = 1;
    if (more_init_slime(enn, tmp, 10, 50) == 84)
        return (84);
    if ((enn->obj = create_obj("assets/slime_idl.png", pos, r, 7)) == NULL)
        return (84);
    sfSprite_setOrigin(enn->obj->sprite, (sfVector2f){32, 20.5});
    sfSprite_setPosition(enn->obj->sprite, pos);
    enn->obj->scale = s;
    sfSprite_setScale(enn->obj->sprite, (sfVector2f){6, 6});
    return (0);
}

int create_red_slime(enn_s *enn, spawn_s *tmp)
{
    int x = tmp->size.x;
    int y = tmp->size.y;
    sfVector2f pos = {rand() % x, tmp->pos.y + rand() % y};
    sfVector2f s = {6, 6};
    sfIntRect r = {0, 82, 64, 41};

    enn->max = 192;
    enn->life = 650;
    enn->health = 650;
    enn->p_armor = 40;
    enn->damage = 60;
    enn->type_dmg = 2;
    if (more_init_slime(enn, tmp, 15, 130) == 84)
        return (84);
    if ((enn->obj = create_obj("assets/slime_idl.png", pos, r, 8)) == NULL)
        return (84);
    sfSprite_setOrigin(enn->obj->sprite, (sfVector2f){32, 20.5});
    sfSprite_setPosition(enn->obj->sprite, pos);
    enn->obj->scale = s;
    sfSprite_setScale(enn->obj->sprite, (sfVector2f){6, 6});
    return (0);
}

int set_stat_enn(enn_s *enn, int type, spawn_s *tmp)
{
    int res = 0;

    if (type == 1)
        res = create_green_slime(enn, tmp);
    else if (type == 2)
        res = create_blue_slime(enn, tmp);
    else
        res = create_red_slime(enn, tmp);
    return (res);
}