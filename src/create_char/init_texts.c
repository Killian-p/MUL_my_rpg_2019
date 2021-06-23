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
#include "math.h"

void error_text(scene_s *sc, int idx)
{
    sfColor fade = {255, 0, 0, sc->error_disp};

    sfText_setColor(sc->texts[idx], fade);
    if (sc->error_disp > 0)
        sc->error_disp -= 0.7;
    sfRenderWindow_drawText(sc->window, sc->texts[idx], NULL);
}

void draw_texts(scene_s *sc, skill_s *skillpoint)
{
    static float effect = 0;
    int idx = 0;

    set_skill_text(sc->texts, skillpoint);
    if (sfClock_getElapsedTime(sc->textclock).microseconds > 15000) {
        effect += 0.1;
        sc->textscale.x += sin(effect) / 50;
        sc->textscale.y += sin(effect) / 50;
        sfText_setScale(sc->texts[0], sc->textscale);
        sfClock_restart(sc->textclock);
    }
    while (sc->texts[idx + 1] != NULL) {
        sfRenderWindow_drawText(sc->window, sc->texts[idx], NULL);
        idx += 1;
    }
    error_text(sc, idx);
    if (effect == 360)
        effect = 0;
}

sfText* create_my_text(sfVector2f pos, sfVector2f origin,
        sfColor color, char *str)
{
    sfText* text = sfText_create();
    sfFont* font = sfFont_createFromFile("assets/font/chocolat.ttf");

    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setOrigin(text, origin);
    sfText_setColor(text, color);
    sfText_setString(text, str);
    return (text);
}

int init_texts(scene_s *scene)
{
    if ((scene->texts = get_texts()) == NULL)
        return (84);
    return (0);
}
