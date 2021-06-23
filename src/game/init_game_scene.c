/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include "rpg.h"

char *get_asset_player(ret_s *values)
{
    char *wc = "assets/woodcutter/idle.png";
    char *gr = "assets/graverobber/idle.png";
    char *sm = "assets/steamman/idle.png";

    if (values->skillpoint->type_char == 0) {
        return (wc);
    } else if (values->skillpoint->type_char == 1) {
        return (gr);
    } else {
        return (sm);
    }
}

int more_init(scene_s *sc)
{
    sc->clock2 = sfClock_create();
    if (set_stats(sc) == 84)
        return 84;
    sc->atk = 0;
    sc->regen = sfClock_create();
    sc->atk_rate = sfClock_create();
    sc->items = NULL;
    sc->player_items = NULL;
    if (sc->stats == NULL)
        return (84);
    if (set_disp_stats(sc) == 84 || create_an_ennemy(sc) == 84)
        return (84);
    sc->tuto = load_tuto();
    sc->focus = 0;
    if (init_spawner(sc) == 84 || keep_on_init(sc) == 84 || !sc->tuto)
        return (84);
    return (0);
}

int get_obj(scene_s * sc, ret_s *values)
{
    sfVector2f pi = {0, 0};
    sfVector2f pp = {900, 400};
    sfIntRect r = {0, 0, 1920, 1080};
    sfIntRect rg = {0, 0, 512, 417};
    sfIntRect rh = {0, 0, 20, 20};
    sfIntRect rp = {0, 0, 48, 48};
    sfVector2f scale = {3.75, 2.59};
    char *player = get_asset_player(values);

    sc->interface = create_obj("assets/interface.png", pi, r, 0);
    sc->bg = create_obj("assets/Grass.png", pi, rg, 0);
    sc->player = create_obj(player, pp, rp, 15);
    sc->head = create_obj(player, (sfVector2f){50, 830}, rh, 0);
    if (more_init(sc) == 84 || !sc->interface
        || !sc->bg || !sc->player || !sc->head)
        return (84);
    sfSprite_setScale(sc->bg->sprite, scale);
    sfSprite_setOrigin(sc->player->sprite, (sfVector2f){24, 24});
    sfSprite_setScale(sc->player->sprite, (sfVector2f){4, 4});
    sfSprite_setScale(sc->head->sprite, (sfVector2f){10, 10});
    return (0);
}

int set_cam(scene_s *sc)
{
    move_s *mv = malloc(sizeof(move_s));

    sc->view = sfView_create();
    sc->cam = sfRectangleShape_create();
    if (!sc->view || !sc->cam || !mv)
        return 84;
    sfView_setCenter(sc->view, (sfVector2f){960, 540});
    sfView_setSize(sc->view, (sfVector2f){1920, 1080});
    sfRectangleShape_setSize(sc->cam, (sfVector2f){2420, 1480});
    sfRectangleShape_setOrigin(sc->cam, (sfVector2f){1210, 740});
    sfRectangleShape_setPosition(sc->cam, sc->player->p);
    sc->mv_kit = mv;
    sc->mv_kit->has_reach = 1;
    sc->mv_kit->target = sc->player->p;
    sc->run = 0;
    sc->death = 0;
    sc->switch_volume = 0;
    sc->volume = 15;
    return 0;
}

scene_s *init_game_scene(ret_s *values)
{
    scene_s *scene = malloc(sizeof(scene_s));

    if (!scene || !values)
        return (NULL);
    scene->window = values->window;
    scene->skills = values->skillpoint;
    scene->nb_char = values->skillpoint->type_char;
    if (get_obj(scene, values) == 84)
        return (NULL);
    scene->pause = init_pause();
    scene->bat = init_bat(scene);
    scene->sound_music = init_sound_music();
    if (!scene->stats || !scene->bat || !scene->pause || !scene->sound_music)
        return (NULL);
    scene->map = create_map(scene);
    if (set_cam(scene) == 84 || scene->map == NULL)
        return NULL;
    sfRenderWindow_setFramerateLimit(scene->window, 60);
    return (scene);
}