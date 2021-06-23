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

char *get_skill_game(int idx, skill_s *skillpt)
{
    switch (idx)
    {
        case 6:
            return (my_nbr(skillpt->strength));
        case 7:
            return (my_nbr(skillpt->intelligence));
        case 8:
            return (my_nbr(skillpt->stamina));
        case 9:
            return (my_nbr(skillpt->accuracy));
        case 10:
            return (my_nbr(skillpt->chance));
        case 11:
            return (my_nbr(skillpt->vitality));
    }
    return (NULL);
}

void set_skill_text_game(scene_s *sc, skill_s *skillpoint)
{
    int idx = 6;

    while (idx <= 11) {
        sfText_setString(sc->skills_text[idx], get_skill_game(idx, skillpoint));
        idx += 1;
    }
}

int check_skill_tree(sfMouseButtonEvent m, scene_s *scene, skill_s *skillpt)
{
    button_s *temp = scene->buttons;

    while (temp != NULL) {
        if (check_place(m.x, m.y, temp) == 2) {
            return (temp->callback(skillpt));
        }
        temp = temp->next;
    }
    return (0);
}

void draw_texts_game(scene_s *sc)
{
    int idx = 0;

    set_skill_text_game(sc, sc->skills);
    while (sc->skills_text[idx] != NULL) {
        sfRenderWindow_drawText(sc->window, sc->skills_text[idx], NULL);
        idx += 1;
    }
}

void draw_skill_tree(scene_s *sc, button_s **refb)
{
    button_s *temp = *refb;

    sfRenderWindow_drawSprite(sc->window, sc->banner->sprite, NULL);
    while (temp != NULL) {
        sfRenderWindow_drawSprite(sc->window, temp->plus->sprite, NULL);
        temp = temp->next;
    }
    draw_texts_game(sc);
}