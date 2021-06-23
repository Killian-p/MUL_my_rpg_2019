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

void follow_switch(int (**callback)(skill_s *skillpt), int c)
{
    switch (c)
    {
        case 6:
            *callback = &add_vitality;
            return;
        case 7:
            *callback = &reset;
            return;
        case 8:
            *callback = &volume_setting;
    }
}

void set_callback(int (**callback)(skill_s *skillpt), int c)
{
    switch (c) {
        case 1:
            *callback = &add_strength;
            return;
        case 2:
            *callback = &add_intelligence;
            return;
        case 3:
            *callback = &add_stamina;
            return;
        case 4:
            *callback = &add_accuracy;
            return;
        case 5:
            *callback = &add_chance;
            return;
    }
    follow_switch(callback, c);
}

int add_button(button_s **button, sfRectangleShape *rect,
        int c, game_object *plus)
{
    button_s *temp = *button;
    button_s *element = malloc(sizeof(button_s));

    if (!element)
        return (84);
    element->rect = rect;
    element->plus = plus;
    element->next = NULL;
    set_callback(&element->callback, c);
    if (*button == NULL) {
        *button = element;
    } else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = element;
    }
    return (0);
}

int init_button(char *buffer, button_s **button)
{
    sfVector2f pos = get_pos_button(buffer);
    sfIntRect r = {0, 0, 31, 31};
    sfIntRect rres = {0, 0, 41, 41};
    game_object *plus = create_object("assets/plus.png", pos, r, 0);
    sfRectangleShape *rect;

    if (get_callback(buffer) == 7)
        plus = create_object("assets/reset.png", pos, rres, 0);
    if (get_callback(buffer) == 8) {
        r.width += 19;
        r.height += 19;
        plus = create_object("assets/sound.png", pos, rres, 0);
    }
    if ((rect = sfRectangleShape_create()) && plus == NULL)
        return (84);
    sfRectangleShape_setSize(rect, get_size_button(buffer));
    sfRectangleShape_setPosition(rect, get_pos_button(buffer));
    if (add_button(button, rect, get_callback(buffer), plus) == 84)
        return (84);
    return (0);
}

button_s *init_buttons(void)
{
    button_s *button = NULL;
    FILE *fd = fopen("config/buttons.txt", "r");
    char *buffer = NULL;
    size_t len = 0;

    if (fd == NULL)
        return (NULL);
    while (getline(&buffer, &len, fd) > 0) {
        if (init_button(buffer, &button) == 84)
            return (NULL);
    }
    fclose(fd);
    return (button);
}