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

int more_init_boss(enn_s *enn)
{
    enn->anim_death = 0;
    enn->spawn_number = 3;
    enn->move = get_move_boss();
    enn->atk = get_atk_boss();
    enn->idle = get_idle_boss();
    enn->trigger.x = 700;
    enn->trigger.y = 700;
    enn->offset = 96;
    enn->has_reach = 0;
    enn->life = 9000;
    enn->health = 9000;
    enn->m_armor = 20;
    enn->disp_speed = 150000;
    enn->atk_rate = sfClock_create();
    enn->mv_kit = malloc(sizeof(move_s));
    if (!enn->move || !enn->atk || !enn->idle || !enn->mv_kit)
        return 84;
    return 0;
}

int init_boss(enn_s *enn)
{
    sfVector2f pos = {(size_map_x - 5) * 80, (size_map_y - 5) * 80};
    sfVector2f s = {8, 8};
    sfIntRect r = {0, 0, 96, 96};

    enn->max = 192;
    enn->next = NULL;
    enn->tuto = 0;
    enn->p_armor = 30;
    enn->damage = 500;
    enn->type_dmg = 1;
    enn->exp = 500;
    enn->drop_chance = 100;
    enn->obj = create_obj("assets/boss/idle.png", pos, r, 3);
    if (more_init_boss(enn) == 84 || !enn->obj)
        return 84;
    sfSprite_setOrigin(enn->obj->sprite, (sfVector2f){48, 48});
    sfSprite_setPosition(enn->obj->sprite, pos);
    enn->obj->scale = s;
    sfSprite_setScale(enn->obj->sprite, (sfVector2f){8, 8});
    return 0;
}

void add_boss(enn_s **ref, enn_s *boss)
{
    enn_s *tmp = *ref;

    if (tmp == NULL) {
        *ref = boss;
        return;
    }
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = boss;
}

int create_boss(scene_s *sc)
{
    enn_s *boss = malloc(sizeof(enn_s));

    if (boss == NULL)
        return (84);
    if (init_boss(boss) == 84)
        return 84;
    add_boss(&sc->enn, boss);
    return (0);
}