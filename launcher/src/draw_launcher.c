/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** draw_launcher
*/

#include "my.h"
#include <stdlib.h>

void password(control_t *ctl)
{
    sfVector2f place;
    place.x = 0.0;
    place.y = 0.0;
    sfSprite_setPosition(ctl->sprite->pass, place);
    sfSprite_setPosition(ctl->sprite->usr, place);
    if (ctl->settings->pass_valid == -1)
        sfRenderWindow_drawSprite(ctl->window, ctl->sprite->pass, NULL);
    if (ctl->settings->usr_valid == -1)
        sfRenderWindow_drawSprite(ctl->window, ctl->sprite->usr, NULL);
    if (ctl->settings->reg_box == 1)
        sfRenderWindow_drawSprite(ctl->window, ctl->sprite->boxreg, NULL);
}

void draw_launcher(control_t *ctl)
{
    sfEvent event;

    sfRenderWindow_setFramerateLimit(ctl->window, 60);
    while (sfRenderWindow_isOpen(ctl->window)) {
        while (sfRenderWindow_pollEvent(ctl->window, &event)) {
            keyboard_manage(ctl, event);
        }
        sfRenderWindow_clear(ctl->window, sfBlack);
        sfRenderWindow_drawSprite(ctl->window, ctl->sprite->launcher, NULL);
        password(ctl);
        sfRenderWindow_drawText(ctl->window, ctl->settings->user, NULL);
        sfRenderWindow_drawText(ctl->window, ctl->settings->pass, NULL);
        sfRenderWindow_display(ctl->window);
    }
    sfRenderWindow_destroy(ctl->window);
}