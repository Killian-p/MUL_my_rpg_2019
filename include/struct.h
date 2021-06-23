/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#ifndef STRUCT_H_LAUNCH
#define STRUCT_H_LAUNCH

typedef struct texture
{
    sfTexture *launcher;
    sfTexture *usr;
    sfTexture *pass;
    sfTexture *boxreg;
}texture_t;

typedef struct sprite
{
    sfSprite *pass;
    sfSprite *usr;
    sfSprite *launcher;
    sfSprite *boxreg;
}sprite_t;

typedef struct settings
{
    int register_game;
    int error;
    char *username;
    char *password;
    char *passcach;
    int bool;
    int pass_valid;
    int usr_valid;
    int reg_box;
    sfText *user;
    sfText *pass;
    sfVector2f place;
    sfVector2f placepass;
}settings_t;

typedef struct control
{
    texture_t *texture;
    sprite_t *sprite;
    settings_t *settings;
    sfRenderWindow *window;
    sfFont *font;
    int connect;
    int passwordreg;
    int possible;
}control_t;


#endif /* !STRUCT_H_LAUNCH */
