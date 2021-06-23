/*
** EPITECH PROJECT, 2020
** destroy
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

void destroy_game_obj(game_object *all)
{
    sfClock_destroy(all->clock);
    sfTexture_destroy(all->texture);
    sfSprite_destroy(all->sprite);
    free(all);
}

void destroy_music_sound(sound_music_t *sm)
{
    int idx = 0;

    sfMusic_destroy(sm->music[0]->music);
    sfMusic_destroy(sm->music[1]->music);
    free(sm->music);
    while (idx < 7) {
        sfSound_destroy(sm->sound[idx]->sound);
        sfSoundBuffer_destroy(sm->sound[idx]->buffer);
        idx += 1;
    }
    free(sm->sound);
}

void destroy_button(button_t **button)
{
    int idx = 0;

    while (idx < 4) {
        sfTexture_destroy(button[idx]->texture);
        sfSprite_destroy(button[idx]->sprite);
        free(button[idx]);
        idx += 1;
    }
}

void destroy_text(text_t **text)
{
    int idx = 0;

    while (idx < 5) {
        sfText_destroy(text[idx]->text);
        sfFont_destroy(text[idx]->font);
        free(text[idx]);
        idx += 1;
    }
}

void destroy_pause(pause_t *pause)
{
    destroy_button(pause->button);
    destroy_text(pause->text);
    free(pause->button);
    free(pause->text);
    sfSprite_destroy(pause->back_s);
    sfSprite_destroy(pause->htop_s);
    sfTexture_destroy(pause->back_t);
    sfTexture_destroy(pause->htop_t);
    free(pause);
}