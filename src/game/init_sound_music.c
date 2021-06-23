/*
** EPITECH PROJECT, 2020
** init sound and music
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

music_t *create_music(char *path)
{
    sfMusic *mus = sfMusic_createFromFile(path);
    music_t *music = malloc(sizeof(music_t));

    if (!music || !mus)
        return (NULL);
    sfMusic_setLoop(mus, sfTrue);
    sfMusic_setVolume(mus, 10);
    music->music = mus;
    return (music);
}

sound_t *create_sound(char *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);
    sound_t *all = malloc(sizeof(sound_t));

    if (!all || !buffer || !sound)
        return (NULL);
    all->buffer = buffer;
    all->sound = sound;
    sfSound_setBuffer(sound, buffer);
    return (all);
}

sound_t **init_sound(void)
{
    sound_t **all = malloc(sizeof(sound_t) * 8);

    if (all == NULL)
        return (NULL);
    all[0] = create_sound("assets/sounds/levelup.ogg");
    all[1] = create_sound("assets/sounds/pnj.ogg");
    all[2] = create_sound("assets/sounds/mino.ogg");
    all[3] = create_sound("assets/sounds/damage.ogg");
    all[4] = create_sound("assets/sounds/quest_finished.ogg");
    all[5] = create_sound("assets/sounds/slime.ogg");
    all[6] = create_sound("assets/sounds/button.ogg");
    all[7] = NULL;
    if (!all[0] || !all[1] || !all[2] || !all[3] || !all[4]
    || !all[5] || !all[6])
        return NULL;
    return (all);
}

music_t **init_music(void)
{
    music_t **all = malloc(sizeof(music_t) * 3);

    if (!all)
        return (NULL);
    all[0] = create_music("assets/sounds/pause.ogg");
    all[1] = create_music("assets/sounds/world_music.ogg");
    all[2] = NULL;
    if (!all[0] || !all[1])
        return NULL;
    return (all);
}

sound_music_t *init_sound_music(void)
{
    sound_music_t *all = malloc(sizeof(sound_music_t));
    sfIntRect r = {0, 0, 50, 50};

    if (!all)
        return (NULL);
    all->music = init_music();
    all->sound = init_sound();
    all->play = -1;
    if (!all->music || !all->sound)
        return (NULL);
    all->icon = create_obj("assets/sound.png", (sfVector2f){1750, 1030}, r, 0);
    if (all->icon == NULL)
        return (NULL);
    return (all);
}