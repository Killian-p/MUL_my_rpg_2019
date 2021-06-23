/*
** EPITECH PROJECT, 2020
** function for loading bar
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

void create_load_scd_part(loading_t *load)
{
    sfRectangleShape_setFillColor(load->yellow, sfYellow);
    sfRectangleShape_setFillColor(load->top, sfGreen);
    sfRectangleShape_setFillColor(load->back, sfBlack);
    sfRectangleShape_setSize(load->yellow, (sfVector2f){504, 44});
    sfRectangleShape_setSize(load->back, (sfVector2f){500, 40});
}

loading_t *create_load(void)
{
    sfFont *font = sfFont_createFromFile("assets/font/chocolat.ttf");
    loading_t *load = malloc(sizeof(loading_t));

    if (!load || !font)
        return (NULL);
    load->total_to_load = size_map_x * size_map_y;
    load->total_load = 0;
    load->back = sfRectangleShape_create();
    load->yellow = sfRectangleShape_create();
    load->top = sfRectangleShape_create();
    load->load = sfText_create();
    sfRectangleShape_setPosition(load->back, (sfVector2f){710, 520});
    sfRectangleShape_setPosition(load->yellow, (sfVector2f){708, 518});
    sfRectangleShape_setPosition(load->top, (sfVector2f){710, 520});
    sfText_setPosition(load->load, (sfVector2f){930, 520});
    sfText_setFont(load->load, font);
    create_load_scd_part(load);
    return (load);
}

float get_coeff(float total_load, float total_to_load)
{
    float total = total_load;
    float total_to = total_to_load;
    float res = total / total_to;

    return (res);
}

char *str_add(char *str, char c)
{
    int idx = 0;
    char *tmp = malloc(sizeof(char) * (my_strlen(str) + 2));

    while (str[idx] != '\0') {
        tmp[idx] = str[idx];
        idx += 1;
    }
    tmp[idx] = c;
    tmp[idx + 1] = '\0';
    return (tmp);
}

void display_loading(loading_t *load, scene_s *scene)
{
    sfVector2f size = {496, 40};
    char *loaded_text = int_to_str(((load->total_load * 100)
    / load->total_to_load));
    size.x *= get_coeff(load->total_load, load->total_to_load);

    if (loaded_text == NULL)
        return;
    loaded_text = str_add(loaded_text, '%');
    sfRenderWindow_clear(scene->window, sfBlack);
    sfText_setString(load->load, loaded_text);
    free(loaded_text);
    sfRectangleShape_setSize(load->top, size);
    sfRenderWindow_drawRectangleShape(scene->window, load->yellow, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, load->back, NULL);
    sfRenderWindow_drawRectangleShape(scene->window, load->top, NULL);
    sfRenderWindow_drawText(scene->window, load->load, NULL);
    sfRenderWindow_display(scene->window);
}