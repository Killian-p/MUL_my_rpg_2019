/*
** EPITECH PROJECT, 2019
** create_char
** File description:
** intit_scene
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "create_char.h"

int setup_more_init(scene_s *scene)
{
    sfVector2f scale = {1.5, 1.5};

    if (init_character(scene) == 84)
        return (84);
    if ((scene->bg = init_parallax()) == NULL)
        return (84);
    if ((scene->textclock = sfClock_create()) == NULL)
        return (84);
    scene->textscale = scale;
    if ((scene->buttons = init_buttons()) == NULL)
        return (84);
    if (init_texts(scene) == 84)
        return (84);
    return (0);
}

int init_scene(scene_s *scene, char *name)
{
    sfRenderWindow *window;
    sfVideoMode mode = {1920, 1080, 32};

    scene->name = name;
    scene->nb = 0;
    window = sfRenderWindow_create(mode, "my_rpg_2019", sfFullscreen, NULL);
    if (window == NULL)
        return (84);
    sfRenderWindow_setFramerateLimit(window, 60);
    scene->window = window;
    if (setup_more_init(scene) == 84)
        return (84);
    return (0);
}