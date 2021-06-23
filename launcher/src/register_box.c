/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** register_box
*/

#include "my.h"

void create_user_and_launch(control_t *ctl);

void check_register_position(control_t *ctl, sfVector2i mouse)
{
    if ((mouse.x >= 604 && mouse.x <= 1370) && (mouse.y >= 372 &&
    mouse.y <= 460)) {
        ctl->settings->register_game = 1;
        ctl->passwordreg = 0;
    }
    if ((mouse.x >= 604 && mouse.x <= 1370) && (mouse.y >= 563 &&
    mouse.y <= 655)) {
        ctl->settings->register_game = 1;
        ctl->passwordreg = 1;
    }
    if ((mouse.x >= 500 && mouse.x <= 1420) && (mouse.y >= 690 &&
    mouse.y <= 820)) {
        if (ctl->settings->username[0] != '\0' &&
        ctl->settings->password[0] != '\0') {
            create_user_and_launch(ctl);
        }
    }
}

static void display_register(control_t *ctl)
{
    sfText_setCharacterSize(ctl->settings->user, 60);
    sfText_setFont(ctl->settings->user, ctl->font);
    sfText_setString(ctl->settings->user, ctl->settings->username);
    sfText_setColor(ctl->settings->user, sfBlack);
    sfText_setPosition(ctl->settings->user, (sfVector2f){604, 372});
    sfText_setCharacterSize(ctl->settings->user, 60);
    sfText_setFont(ctl->settings->pass, ctl->font);
    sfText_setString(ctl->settings->pass, ctl->settings->passcach);
    sfText_setColor(ctl->settings->pass, sfBlack);
    sfText_setPosition(ctl->settings->pass, (sfVector2f){604, 563});
}

void register_set_and_disp(control_t *ctl, sfEvent event)
{
    if (event.key.code == 59) {
        if (ctl->passwordreg != 1)
            ctl->settings->username = remove_char(ctl->settings->username);
        else
            ctl->settings->passcach = remove_char(ctl->settings->passcach);
    }
    if (ctl->passwordreg != 1)
        username_set(ctl, event);
    else
        password_set(ctl, event);
    display_register(ctl);
}