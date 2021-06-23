/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** keyboard
*/

#include "my.h"
#include <stdlib.h>

void text_set(control_t *ctl)
{
    sfText_setCharacterSize(ctl->settings->user, 40);
    sfText_setFont(ctl->settings->user, ctl->font);
    sfText_setString(ctl->settings->user, ctl->settings->username);
    sfText_setColor(ctl->settings->user, sfBlack);
    sfText_setPosition(ctl->settings->user, ctl->settings->place);
    sfText_setCharacterSize(ctl->settings->pass, 80);
    sfText_setFont(ctl->settings->pass, ctl->font);
    sfText_setString(ctl->settings->pass, ctl->settings->passcach);
    sfText_setColor(ctl->settings->pass, sfBlack);
    sfText_setPosition(ctl->settings->pass, ctl->settings->placepass);
}

char *str_cat(char *buff, char c)
{
    int i = 0;
    int f = 0;
    char *tmp = NULL;

    for (i = 0;buff[i] != '\0';i++);
    tmp = malloc(sizeof(char) * (i + 2));
    for (f = 0; buff[f] != '\0'; f++) {
        tmp[f] = buff[f];
    }
    tmp[f] = c;
    tmp[f + 1] = '\0';
    return tmp;
}

static int login_or_password(control_t *ctl)
{
    sfVector2i m = sfMouse_getPosition(NULL);

    if ((m.x >= 1835 && m.x <= 1920) && (m.y >= 0 && m.y <= 70))
        sfRenderWindow_close(ctl->window);
    if ((m.x >= 116 && m.x <= 388) && (m.y >= 313 && m.y <= 355)) {
        return 1;
    } else if ((m.x >= 116 && m.x <= 388) && (m.y >= 407 && m.y <= 447)) {
        return 2;
    } else {
        if ((m.x >= 200 && m.x <= 290) && (m.y >= 810 && m.y <= 915)) {
            check_field(ctl);
        } else if ((m.x >= 140 && m.x <= 255) && (m.y >= 985 && m.y <= 1015)) {
            ctl->possible = 1;
            ctl->settings->reg_box = 1;
        } else
            check_register_position(ctl, m);
        return 0;
    }
}

char *remove_char(char *buffer)
{
    int i = 0;

    if (buffer[0] != '\0') {
        while (buffer[i] != '\0') {
            ++i;
        }
        buffer[i - 1] = '\0';
    }
    return buffer;
}

void keyboard_manage(control_t *ctl, sfEvent event)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(ctl->window);
    } else {
        if (event.type == sfEvtKeyReleased && event.key.code == 58) {
            ctl->settings->pass_valid = 0;
            ctl->settings->usr_valid = 0;
            ctl->possible = 0;
        }
        if (event.type == sfEvtMouseButtonPressed)
            ctl->settings->bool = login_or_password(ctl);
        login_set(ctl, event);
        if (ctl->settings->register_game == 0)
            text_set(ctl);
        if (ctl->settings->register_game == 1 && event.type == sfEvtKeyPressed)
            register_set_and_disp(ctl, event);
    }
}