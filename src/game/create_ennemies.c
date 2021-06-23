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

int more_init_mob(enn_s *enn)
{
    enn->anim_death = 0;
    enn->spawn_number = 1;
    enn->move = get_move_enn();
    enn->atk = get_atk_enn();
    enn->idle = get_idle_enn();
    enn->trigger.x = 500;
    enn->trigger.y = 500;
    enn->disp_speed = 150000;
    enn->offset = 64;
    enn->has_reach = 0;
    enn->p_armor = 0;
    enn->damage = 0;
    enn->atk_rate = sfClock_create();
    enn->mv_kit = malloc(sizeof(move_s));
    if (!enn->mv_kit || !enn->move || !enn->atk || !enn->idle)
        return 84;
    return 0;
}

int init_first_enn(enn_s *enn)
{
    sfVector2f pos = {1300, 100};
    sfVector2f s = {6, 6};
    sfIntRect r = {0, 0, 64, 41};

    enn->max = 192;
    enn->next = NULL;
    enn->tuto = 1;
    enn->life = 250;
    enn->health = 250;
    enn->m_armor = 0;
    enn->type_dmg = 0;
    enn->exp = 150;
    enn->drop_chance = 100;
    enn->obj = create_obj("assets/slime_idl.png", pos, r, 0);
    if (more_init_mob(enn) == 84 || !enn->obj)
        return 84;
    sfSprite_setOrigin(enn->obj->sprite, (sfVector2f){32, 20.5});
    sfSprite_setPosition(enn->obj->sprite, pos);
    enn->obj->scale = s;
    sfSprite_setScale(enn->obj->sprite, (sfVector2f){6, 6});
    return 0;
}

int create_an_ennemy(scene_s *sc)
{
    sc->enn = malloc(sizeof(enn_s));
    if (sc->enn == NULL)
        return (84);
    if (init_first_enn(sc->enn) == 84)
        return 84;
    return (0);
}

void set_anim_stat(enn_s *tmp, int max, int type)
{
    tmp->max = max;
    if (tmp->spawn_number == 3) {
        if (type == 0) {
            tmp->obj->rect.left = 0;
            tmp->disp_speed = 150000;
            tmp->max = 4 * 96;
        }
        if (type == 1) {
            tmp->obj->rect.left = 0;
            tmp->disp_speed = 150000;
            tmp->max = 3 * 96;
        }
        if (type == 2) {
            tmp->obj->rect.left = 0;
            tmp->disp_speed = 50000;
            tmp->max = 13 * 96;
        }
    }
}
