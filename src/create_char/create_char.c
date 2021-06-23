/*
** EPITECH PROJECT, 2019
** main
** File description:
** create_char
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "create_char.h"

game_object *create_object(const char *path_to_spritesheet,
                        sfVector2f pos, sfIntRect rect, float speed)
{
    struct game_object *object = malloc(sizeof(game_object));

    if (!object)
        return (NULL);
    object->position = pos;
    if ((object->sprite = sfSprite_create()) == NULL)
        return (NULL);
    object->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    if (object->texture == NULL)
        return (NULL);
    sfSprite_setTexture(object->sprite, object->texture, sfTrue);
    sfSprite_setTextureRect(object->sprite, rect);
    sfSprite_setPosition(object->sprite, pos);
    object->rect = rect;
    if ((object->clock = sfClock_create()) == NULL)
        return (NULL);
    object->speed = speed;
    object->disp = 1;
    return (object);
}

int analyse_events_cc(sfRenderWindow *window, sfEvent event,
        scene_s *scene, skill_s *skillpt)
{
    if (event.type == sfEvtClosed)
        sfRenderWindow_close(window);
    if (event.type == sfEvtKeyPressed)
        key_managing(window, event, scene, skillpt);
    if (event.type == sfEvtMouseButtonPressed)
        manage_mouse_click(event.mouseButton, scene, skillpt);
    if (event.type == sfEvtMouseButtonReleased)
        scene->switch_volume = 0;
    return (0);
}

ret_s *create_char(skill_s *skillpoint, sfMusic *music, char *name)
{
    scene_s *scene = malloc(sizeof(scene_s));
    sfEvent event;

    if (!scene)
        return (NULL);
    if (init_scene(scene, name) == 84)
        return (NULL);
    while (sfRenderWindow_isOpen(scene->window)) {
        draw_sprites(scene, skillpoint);
        while (sfRenderWindow_pollEvent(scene->window, &event)) {
            analyse_events_cc(scene->window, event, scene, skillpoint);
        }
        set_volume(music, scene);
        sfRenderWindow_display(scene->window);
        if (scene->leave == 2)
            break;
    }
    destroy_music(scene);
    sfRenderWindow_setFramerateLimit(scene->window, 0);
    return (return_create_char(scene, skillpoint));
}

ret_s *create_game(char *name, int bool)
{
    skill_s *skill_point = malloc(sizeof(skill_s));
    ret_s *return_values;

    if (!skill_point)
        return (NULL);
    init_skill_point(skill_point, bool, name);
    sfMusic* music = sfMusic_createFromFile("assets/music.ogg");
    if (music == NULL)
        return (NULL);
    sfMusic_setVolume(music, 50);
    sfMusic_play(music);
    sfMusic_setLoop(music, 1);
    if ((return_values = create_char(skill_point, music, name)) == NULL)
        return (NULL);
    sfMusic_destroy(music);
    if (start_game(return_values) == 84)
        return (NULL);
    return (return_values);
}