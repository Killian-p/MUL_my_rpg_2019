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

void key_managing(sfRenderWindow *window, sfEvent event,
        scene_s *scene, skill_s *skillpoint)
{
    if (event.key.code == sfKeyEscape)
        sfRenderWindow_close(window);
    if (event.key.code == sfKeyLeft) {
        if (scene->nb == 0)
            scene->nb = 2;
        else
            scene->nb -= 1;
    }
    if (event.key.code == sfKeyRight) {
        if (scene->nb == 2)
            scene->nb = 0;
        else
            scene->nb += 1;
    }
    sfMusic_stop(scene->character[scene->nb]->sound);
    sfMusic_play(scene->character[scene->nb]->sound);
    if (event.key.code == sfKeyEnter && scene->leave == 1) {
        scene->leave = 2;
        skillpoint->type_char = scene->nb;
    }
}

int check_place(int x, int y, button_s *temp)
{
    int n = 0;
    sfVector2f pos = sfRectangleShape_getPosition(temp->rect);
    sfVector2f size = sfRectangleShape_getSize(temp->rect);

    if (x > pos.x && x < pos.x + size.x)
        n += 1;
    if (y > pos.y && y < pos.y + size.y)
        n += 1;
    return (n);
}

int check_in_box(sfMouseButtonEvent m, scene_s *scene, skill_s *skillpt)
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

void manage_mouse_click(sfMouseButtonEvent m, scene_s *scene, skill_s *skillpt)
{
    int check = check_in_box(m, scene, skillpt);

    if (check == 1) {
        scene->ping->position.x = m.x;
        scene->ping->position.y = m.y;
        sfSprite_setPosition(scene->ping->sprite, scene->ping->position);
        scene->ping->drawable = 1;
        sfMusic_stop(scene->up_sound);
        sfMusic_play(scene->up_sound);
    }
    if (check == 3) {
        sfMusic_stop(scene->error_sound);
        sfMusic_play(scene->error_sound);
        scene->error_disp = 255;
    }
    if (check == 8)
        scene->switch_volume = 1;
}