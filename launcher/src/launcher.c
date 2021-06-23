/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** launcher
*/

#include "my.h"
#include <stdlib.h>

static void init_ctl(control_t *ctl)
{
    ctl->settings->pass_valid = 0;
    ctl->settings->usr_valid = 0;
    ctl->settings->username = malloc(sizeof(char) * 1);
    ctl->settings->username[0] = '\0';
    ctl->settings->password = malloc(sizeof(char) * 1);
    ctl->settings->password[0] = '\0';
    ctl->settings->passcach = malloc(sizeof(char) * 1);
    ctl->settings->passcach[0] = '\0';
    ctl->settings->bool = 0;
    ctl->settings->place.x = 115;
    ctl->settings->place.y = 310;
    ctl->settings->placepass.x = 115;
    ctl->settings->placepass.y = 400;
    ctl->settings->reg_box = 0;
    ctl->settings->register_game = 0;
    ctl->possible = 0;
    ctl->settings->error = 0;
}

static void create_next(control_t *ctl)
{
    sfSprite_setTexture(ctl->sprite->boxreg, ctl->texture->boxreg, sfTrue);
    sfSprite_setTexture(ctl->sprite->launcher, ctl->texture->launcher, sfTrue);
    sfSprite_setTexture(ctl->sprite->pass, ctl->texture->pass, sfTrue);
    sfSprite_setTexture(ctl->sprite->usr, ctl->texture->usr, sfTrue);
    ctl->window = window_create();
    ctl->font = sfFont_createFromFile("assets/font/chocolat.ttf");
    ctl->settings->user = sfText_create();
    ctl->settings->pass = sfText_create();
}

static int create_launcher(control_t *ctl)
{
    ctl->texture->launcher = sfTexture_createFromFile
    ("assets/launcher/launch.png", NULL);
    ctl->texture->pass = sfTexture_createFromFile
    ("assets/popup/bad_pass.png", NULL);
    ctl->texture->usr = sfTexture_createFromFile
    ("assets/popup/bad_usr.png", NULL);
    ctl->texture->boxreg = sfTexture_createFromFile
    ("assets/launcher/box.png", NULL);
    ctl->sprite->launcher = sfSprite_create();
    ctl->sprite->usr = sfSprite_create();
    ctl->sprite->pass = sfSprite_create();
    ctl->sprite->boxreg = sfSprite_create();
    if (!ctl->texture->launcher || !ctl->texture->pass || !ctl->texture->usr ||
    !ctl->texture->boxreg || !ctl->sprite->launcher || !ctl->sprite->usr ||
    !ctl->sprite->pass || !ctl->sprite->boxreg)
        return 84;
    create_next(ctl);
    draw_launcher(ctl);
    return 0;
}

int start_launcher(void)
{
    int error = 0;
    control_t *ctl = malloc(sizeof(control_t));
    texture_t *texture = malloc(sizeof(texture_t));
    sprite_t *sprite = malloc(sizeof(sprite_t));
    settings_t *settings = malloc(sizeof(settings_t));

    if (ctl == NULL || texture == NULL || sprite == NULL || settings == NULL)
        return 84;
    ctl->settings = settings;
    ctl->sprite = sprite;
    ctl->texture = texture;
    init_ctl(ctl);
    error = create_launcher(ctl);
    if (ctl->settings->error == 84 || error == 84)
        return 84;
    return 0;
}