/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "create_char.h"

int anim_offset(game_object *obj, int max, int offset)
{
    if (obj->rect.left >= max) {
        obj->rect.left -= offset;
        obj->disp = -1;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        return (1);
    }
    if (obj->rect.left <= 0) {
        obj->rect.left += offset;
        obj->disp = 1;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        return (0);
    }
    obj->rect.left += offset * obj->disp;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return (0);
}

void draw_sprites(scene_s *sc, skill_s *skillpoint)
{
    int t = sfClock_getElapsedTime(sc->character[sc->nb]->clock).microseconds;

    move_parallax(sc);
    sfRenderWindow_drawSprite(sc->window, sc->banner->sprite, NULL);
    if (t >= 150000) {
        anim_offset(sc->character[sc->nb], 144, 48);
        sfClock_restart(sc->character[sc->nb]->clock);
    }
    draw_buttons(sc, sc->buttons);
    draw_texts(sc, skillpoint);
    draw_icons(sc, skillpoint);
    draw_ping(sc);
    draw_volume(sc);
    if (skillpoint->skillpoints == 0)
        sc->leave = 1;
    else
        sc->leave = 0;
}

int next_scene_init2(scene_s *sc)
{
    sfIntRect rect = {0, 0, 192, 192};

    sc->ping = create_object("assets/ping.png", (sfVector2f){0, 0}, rect, 0);
    sc->up_sound = sfMusic_createFromFile("assets/up.ogg");
    sc->error_sound = sfMusic_createFromFile("assets/error.ogg");
    sc->character[0]->sound = sfMusic_createFromFile("assets/wcsound.wav");
    sc->character[1]->sound = sfMusic_createFromFile("assets/grsound.wav");
    sc->character[2]->sound = sfMusic_createFromFile("assets/smsound.wav");
    if (!sc->ping || !sc->up_sound || !sc->error_sound ||
    !sc->character[0]->sound ||
        !sc->character[1]->sound || !sc->character[2]->sound)
        return (84);
    sfSprite_setOrigin(sc->ping->sprite, (sfVector2f){96, 96});
    sc->ping->drawable = 0;
    sc->volume = 0;
    sc->switch_volume = 0;
    sc->error_disp = 0;
    sc->leave = 0;
    if (init_volume_display(sc) == 84)
        return (84);
    return (0);
}

int next_scene_init(scene_s *scene)
{
    sfVector2f pr = {1315, 1050};
    sfVector2f pl = {1215, 1050};
    sfVector2f pe = {960, 540};
    sfIntRect r = {0, 0, 128, 128};
    sfIntRect r_enter = {0, 0, 448, 448};

    scene->keys[0] = create_object("assets/right_key.png", pr, r, 0);
    scene->keys[1] = create_object("assets/left_key.png", pl, r, 0);
    scene->keys[2] = create_object("assets/enter_key.png", pe, r_enter, 0);
    if (!scene->keys[0] || !scene->keys[1] || !scene->keys[2])
        return (84);
    sfSprite_setOrigin(scene->keys[0]->sprite, (sfVector2f){64, 64});
    sfSprite_setOrigin(scene->keys[1]->sprite, (sfVector2f){64, 64});
    sfSprite_setOrigin(scene->keys[2]->sprite, (sfVector2f){224, 224});
    scene->keys[0]->scale = (sfVector2f){0.05, 0.05};
    scene->keys[1]->scale = (sfVector2f){0.05, 0.05};
    scene->keys[2]->scale = (sfVector2f){0.05, 0.05};
    if (next_scene_init2(scene) == 84)
        return (84);
    return (0);
}

int init_character(scene_s *scene)
{
    sfVector2f p = {1100, 542};
    sfVector2f p_b = {0, 150};
    sfIntRect r = {0, 0, 48, 48};
    sfIntRect r_banner = {0, 0, 600, 900};

    game_object *wc = create_object("assets/woodcutter/walk.png", p, r, 0);
    game_object *gr = create_object("assets/graverobber/walk.png", p, r, 0);
    game_object *sm = create_object("assets/steamman/walk.png", p, r, 0);
    scene->banner = create_object("assets/bannieregris.png", p_b, r_banner, 0);
    if (!wc || !gr || !sm || !scene->banner)
        return (84);
    sfSprite_setScale(wc->sprite, (sfVector2f){10, 10});
    sfSprite_setScale(gr->sprite, (sfVector2f){10, 10});
    sfSprite_setScale(sm->sprite, (sfVector2f){10, 10});
    scene->character[0] = wc;
    scene->character[1] = gr;
    scene->character[2] = sm;
    if (next_scene_init(scene) == 84)
        return (84);
    return (0);
}