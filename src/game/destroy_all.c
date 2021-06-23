/*
** EPITECH PROJECT, 2020
** destroy all
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

void destroy_items(items_s *all)
{
    items_s *item = all;

    while (item) {
        all = all->next;
        sfSprite_destroy(item->obj->sprite);
        sfTexture_destroy(item->obj->texture);
        sfClock_destroy(item->obj->clock);
        free(item->obj);
        free(item);
        item = all;
    }
}

void destroy_gutlet(gutlet_s *gutlet)
{
    free(gutlet->gutlets);
    destroy_game_obj(gutlet->red);
    destroy_game_obj(gutlet->green);
    destroy_game_obj(gutlet->blue);
    free(gutlet);
}

void second_part_destroy(scene_s *sc)
{
    destroy_spawn(sc->spawner);
    destroy_enemy(sc->enn);
    destroy_items(sc->items);
    destroy_game_obj(sc->bg);
    destroy_game_obj(sc->interface);
    destroy_game_obj(sc->player);
    destroy_game_obj(sc->head);
    destroy_gutlet(sc->gutlet);
}

void destroy_scene(scene_s *sc)
{
    free(sc->skills);
    free(sc->stats);
    sfRenderWindow_destroy(sc->window);
    destroy_music_sound(sc->sound_music);
    destroy_pause(sc->pause);
    destroy_bat(sc->bat);
    destroy_stat(sc->disp);
    destroy_texts(sc->tuto);
    destroy_map(sc->map);
    sfRectangleShape_destroy(sc->cam);
    sfView_destroy(sc->view);
    free(sc->mv_kit);
    sfClock_destroy(sc->clock2);
    sfClock_destroy(sc->spawn_rate);
    sfClock_destroy(sc->atk_rate);
    sfClock_destroy(sc->regen);
    second_part_destroy(sc);
}

void destroy_all(ret_s *values, pnj_quest_t *pq, scene_s *sc)
{
    free(values);
    destroy_pnj(pq->pnj);
    destroy_texts(pq->quest);
    destroy_scene(sc);
}