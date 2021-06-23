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

void draw_gsprites(scene_s *sc, pnj_quest_t *pq)
{
    int t = sfClock_getElapsedTime(sc->player->clock).microseconds;

    draw_map(&sc->map, sc);
    draw_items(sc, &sc->items);
    sfRenderWindow_drawSprite(sc->window, sc->player->sprite, NULL);
    draw_ennemies(sc, &sc->enn);
    display_bat(sc, sc->bat);
    display_pnj(sc, pq->pnj);
    draw_spell(sc);
    sfRenderWindow_drawSprite(sc->window, sc->interface->sprite, NULL);
    draw_player_items(sc, &sc->player_items);
    draw_stats(sc);
    draw_head(sc);
    draw_text(sc);
    draw_attack(sc, t);
    if (pq->in_speak == 1) {
        sfRenderWindow_drawText(sc->window, pq->quest[pq->quest_nb], NULL);
    }
}

int analyse_events_game(scene_s *scene, sfEvent event,
                    pnj_quest_t *pq, int *restart)
{
    if (scene->pause->in_pause == 0) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(scene->window);
        if (event.type == sfEvtKeyPressed)
            gkey_managing(scene, event, pq);
        if (event.type == sfEvtMouseButtonPressed && pq->in_speak == 0)
            manage_game_click(event.mouseButton, scene);
    } else {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(scene->window);
        else
            event_pause_menu(scene, event, restart);
    }
    return (0);
}

void pause_loop(scene_s *scene)
{
    if (scene->sound_music->play != 0) {
        sfMusic_stop(scene->sound_music->music[1]->music);
        sfMusic_play(scene->sound_music->music[0]->music);
        scene->sound_music->play = 0;
    }
    display_pause(scene);
    draw_volume_pause(scene);
    set_volume_game(scene);
}

void loop_game(scene_s *scene, pnj_quest_t *pq)
{
    if (scene->sound_music->play != 1) {
        sfMusic_stop(scene->sound_music->music[0]->music);
        sfMusic_play(scene->sound_music->music[1]->music);
        scene->sound_music->play = 1;
    }
    draw_gsprites(scene, pq);
    if (scene->death == 0)
        move_player(scene);
    regen(scene);
    spawning(scene);
}

void game_loop(scene_s *scene, pnj_quest_t *pq, int *restart)
{
    sfRenderWindow_clear(scene->window, sfBlack);
    if (scene->pause->in_pause == 1) {
        pause_loop(scene);
    } else {
        loop_game(scene, pq);
    }
    sfRenderWindow_display(scene->window);
    while (sfRenderWindow_pollEvent(scene->window, &scene->event)) {
        analyse_events_game(scene, scene->event, pq, restart);
    }
}