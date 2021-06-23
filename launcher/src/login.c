/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** login
*/

#include "my.h"
#include <stdlib.h>

static int len(char *buffer)
{
    int i = 0;

    if (buffer == NULL)
        return 0;
    while (buffer[i] != '\0') {
        ++i;
    }
    return i + 1;
}

void username_set(control_t *ctl, sfEvent event)
{
    if (event.key.code + 97 >= 'a' && event.key.code + 97 <= 'z') {
            ctl->settings->username = str_cat(ctl->settings->username,
            (event.key.code + 97));
    }
}

void password_set(control_t *ctl, sfEvent event)
{
    int len_password = len(ctl->settings->password);
    int i = 0;

    if (event.key.code + 97 >= 'a' && event.key.code + 97 <= 'z') {
        ctl->settings->password = str_cat(ctl->settings->password,
        (event.key.code + 97));
        ctl->settings->passcach = malloc(sizeof(char) *(len_password + 1));
        for (i = 0; i < len_password; i++) {
            ctl->settings->passcach[i] = '*';
        }
        ctl->settings->passcach[len_password] = '\0';
    }
}

void delete(control_t *ctl, sfEvent event)
{
    if (event.key.code == 59 && event.type == sfEvtKeyPressed) {
        if (ctl->settings->bool == 1) {
            ctl->settings->username = remove_char(ctl->settings->username);
        } else if (ctl->settings->bool == 2) {
            ctl->settings->password = remove_char(ctl->settings->password);
            ctl->settings->passcach = remove_char(ctl->settings->passcach);
        }
    }
}

void login_set(control_t *ctl, sfEvent event)
{
    if (ctl->possible == 0) {
        if (event.type == sfEvtKeyPressed && ctl->settings->bool == 1) {
            username_set(ctl, event);
        } else if (event.type == sfEvtKeyPressed && ctl->settings->bool == 2 &&
        len(ctl->settings->password) < 24) {
            password_set(ctl, event);
        }
        delete(ctl, event);
    }
}