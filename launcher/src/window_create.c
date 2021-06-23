/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** create_window
*/

#include "my.h"

static sfVideoMode init_window(void)
{
    sfVideoMode video;

    video = sfVideoMode_getDesktopMode();
    return (video);
}

sfRenderWindow *window_create(void)
{
    sfVideoMode video = init_window();
    sfRenderWindow *window;

    window = sfRenderWindow_create
    (video, "Launcher Rpg", sfFullscreen | sfClose , NULL);
    return (window);
}