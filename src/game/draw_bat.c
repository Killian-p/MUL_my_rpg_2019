/*
** EPITECH PROJECT, 2020
** drawing buildings
** File description:
** rpg
*/

#include <unistd.h>
#include "rpg.h"

void display_bat(scene_s *sc, bat_t *bat)
{
    while (bat) {
        sfRenderWindow_drawSprite(sc->window, bat->bat_s, NULL);
        bat = bat->next;
    }
}