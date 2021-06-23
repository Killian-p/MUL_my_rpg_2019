/*
** EPITECH PROJECT, 2019
** main
** File description:
** my_hunter
*/

#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <math.h>
#include "rpg.h"

sfTexture *get_texture(scene_s *sc)
{
    sfTexture *t = NULL;

    if (sc->nb_char == 0) {
        t = sfTexture_createFromFile("assets/woodcutter/run.png", NULL);
    } else if (sc->nb_char == 1) {
        t = sfTexture_createFromFile("assets/graverobber/run.png", NULL);
    } else {
        t = sfTexture_createFromFile("assets/steamman/run.png", NULL);
    }
    return (t);
}

sfTexture *get_idle(scene_s *sc)
{
    sfTexture *t = NULL;

    if (sc->nb_char == 0) {
        t = sfTexture_createFromFile("assets/woodcutter/idle.png", NULL);
    } else if (sc->nb_char == 1) {
        t = sfTexture_createFromFile("assets/graverobber/idle.png", NULL);
    } else {
        t = sfTexture_createFromFile("assets/steamman/idle.png", NULL);
    }
    return (t);
}

sfTexture *get_slash(scene_s *sc)
{
    sfTexture *t = NULL;

    if (sc->nb_char == 0) {
        t = sfTexture_createFromFile("assets/woodcutter/slash.png", NULL);
    } else if (sc->nb_char == 1) {
        t = sfTexture_createFromFile("assets/graverobber/slash.png", NULL);
    } else {
        t = sfTexture_createFromFile("assets/steamman/slash.png", NULL);
    }
    return (t);
}

sfTexture *get_attack(scene_s *sc)
{
    sfTexture *t = NULL;

    if (sc->nb_char == 0) {
        t = sfTexture_createFromFile("assets/woodcutter/attack.png", NULL);
    } else if (sc->nb_char == 1) {
        t = sfTexture_createFromFile("assets/graverobber/attack.png", NULL);
    } else {
        t = sfTexture_createFromFile("assets/steamman/attack.png", NULL);
    }
    return (t);
}