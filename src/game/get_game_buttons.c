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

int init_button_game(char *buffer, button_s **button)
{
    sfVector2f pos = get_pos_button(buffer);
    sfIntRect r = {0, 0, 31, 31};
    game_object *plus = create_obj("assets/plus.png", pos, r, 0);
    sfRectangleShape *rect = sfRectangleShape_create();

    if (!plus || !rect)
        return 84;
    sfRectangleShape_setSize(rect, get_size_button(buffer));
    sfRectangleShape_setPosition(rect,  get_pos_button(buffer));
    add_button(button, rect, get_callback(buffer), plus);
    return 0;
}

button_s *get_buttons_skill(void)
{
    button_s *button = NULL;
    FILE *fd = fopen("config/game_buttons.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;

    if (!fd)
        return NULL;
    while (getline(&buffer, &len, fd) > 0) {
        init_button_game(buffer, &button);
        idx += 1;
    }
    if (!button)
        return NULL;
    fclose(fd);
    return (button);
}