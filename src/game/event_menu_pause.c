/*
** EPITECH PROJECT, 2020
** event in menu pause
** File description:
** rpg
*/

#include "rpg.h"

sfVector2f get_new_pos(sfFloatRect *rect, sfVector2f *pos, button_t *button)
{
    sfVector2f pos_two = {0, 0};

    *pos = sfSprite_getPosition(button->sprite);
    *rect = sfSprite_getLocalBounds(button->sprite);
    pos_two.x = pos->x - 50;
    pos_two.y = pos->y - 15;
    return (pos_two);
}

void callback_pause_menu(int idx, int *on_button, scene_s *sc, int *restart)
{
    sfSound_play(sc->sound_music->sound[6]->sound);
    if (idx == 0) {
        sc->pause->in_pause = 0;
        sc->switch_volume = 0;
    }
    if (idx == 1) {
        sfMusic_stop(sc->sound_music->music[0]->music);
        sfRenderWindow_close(sc->window);
        *restart = 1;
    }
    if (idx == 2) {
        sc->pause->htop = 1;
    }
    if (idx == 3) {
        sfMusic_stop(sc->sound_music->music[0]->music);
        sfRenderWindow_close(sc->window);
    }
    *on_button = 0;
}

void size_button(scene_s *sc, int idx, sfVector2f pos_bu)
{
    sfSound_play(sc->sound_music->sound[6]->sound);
    sfSprite_setScale(sc->pause->button[idx]->sprite, (sfVector2f){1.5, 1.5});
    sfSprite_setPosition(sc->pause->button[idx]->sprite, pos_bu);
}

void pause_menu(scene_s *sc, sfEvent event, sfVector2i mse, int *restart)
{
    int idx = 0;
    int on_button = 0;
    sfFloatRect rect_bu = {0, 0, 0, 0};
    sfVector2f pos_bu = {0, 0};
    sfVector2f scale_two = {2, 2};
    sfVector2f pos_two = {0, 0};

    while (idx < 4) {
        pos_two = get_new_pos(&rect_bu, &pos_bu, sc->pause->button[idx]);
        if (mse.x < (pos_bu.x + (rect_bu.width * 1.5)) && mse.x > pos_bu.x &&
        mse.y < (pos_bu.y + (rect_bu.height * 1.5)) && mse.y > pos_bu.y) {
            sfSprite_setScale(sc->pause->button[idx]->sprite, scale_two);
            sfSprite_setPosition(sc->pause->button[idx]->sprite, pos_two);
            on_button = 1;
        }
        if (on_button == 1 && event.type == sfEvtMouseButtonPressed)
            size_button(sc, idx, pos_bu);
        if (on_button == 1 && event.type == sfEvtMouseButtonReleased)
            callback_pause_menu(idx, &on_button, sc, restart);
        idx += 1;
    }
}

void event_pause_menu(scene_s *sc, sfEvent event, int *restart)
{
    sfVector2i mouse = sfMouse_getPositionRenderWindow(sc->window);
    float x = sc->interface->p.x;
    float y = sc->interface->p.y;

    mouse.x += x;
    mouse.y += y;
    if (event.type == sfEvtMouseButtonPressed)
        check_volume_click(sc, mouse.x, mouse.y);
    if (event.type == sfEvtMouseButtonReleased)
        sc->switch_volume = 0;
    reinit_pause_button(sc, sc->pause);
    reinit_pause_text(sc, sc->pause);
    if (sc->pause->htop == 0)
        pause_menu(sc, event, mouse, restart);
    else {
        if (event.key.code == sfKeyEscape)
            sc->pause->htop = 0;
    }
}