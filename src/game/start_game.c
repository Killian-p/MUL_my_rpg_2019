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

int start_game(ret_s *values)
{
    int restart = 0;
    scene_s *scene = init_game_scene(values);
    pnj_quest_t *pq = init_pnj_quest(scene, values);

    if (!scene || !pq)
        return (84);
    while (sfRenderWindow_isOpen(scene->window)) {
        game_loop(scene, pq, &restart);
    }
    save_player_stats(scene, pq, values);
    destroy_all(values, pq, scene);
    if (restart == 1)
        start_launcher();
    return (0);
}