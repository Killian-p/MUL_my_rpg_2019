/*
** EPITECH PROJECT, 2020
** check mouse click for know if moving is possible
** File description:
** rpg
*/

#include "rpg.h"

void get_coords_sprite(sfSprite *spt, sfVector2f *ul, sfVector2f *br)
{
    sfVector2f pos = sfSprite_getPosition(spt);
    sfFloatRect localb = sfSprite_getLocalBounds(spt);

    ul->x = pos.x;
    ul->y = pos.y;
    br->x = pos.x + localb.width * 2;
    br->y = pos.y + localb.height * 2;
}

int click_is_in_house(bat_t *bat, sfMouseButtonEvent m, sfVector2f p)
{
    sfVector2f p_pos = {m.x + p.x, m.y + p.y};
    sfVector2f ul = {0, 0};
    sfVector2f br = {0, 0};

    while (bat != NULL) {
        get_coords_sprite(bat->bat_s, &ul, &br);
        if (p_pos.x > ul.x && p_pos.x < br.x
        && p_pos.y > ul.y && p_pos.y < br.y)
            return (-1);
        bat = bat->next;
    }
    return (0);
}