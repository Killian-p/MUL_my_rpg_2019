/*
** EPITECH PROJECT, 2020
** init_pause
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

int create_pause_texture(pause_t *pause)
{
    sfTexture *htop_t = sfTexture_createFromFile("assets/howtoplay.png", NULL);
    sfSprite *htop_s = sfSprite_create();
    sfTexture *back_t = sfTexture_createFromFile("assets/back.jpg", NULL);
    sfSprite *back_s = sfSprite_create();

    if (!htop_t || !htop_s || !back_t || !back_s)
        return 84;
    pause->htop_t = htop_t;
    pause->htop_s = htop_s;
    pause->back_t = back_t;
    pause->back_s = back_s;
    pause->htop = 0;
    sfSprite_setTexture(back_s, back_t, sfTrue);
    sfSprite_setTexture(htop_s, htop_t, sfTrue);
    return 0;
}

button_t **create_button_texture(void)
{
    button_t **button = malloc(sizeof(*button) * 4);

    if (!button)
        return NULL;
    button[0] = create_button("assets/button.png", (sfVector2f){800, 410});
    button[1] = create_button("assets/button.png", (sfVector2f){800, 560});
    button[2] = create_button("assets/button.png", (sfVector2f){800, 710});
    button[3] = create_button("assets/button.png", (sfVector2f){800, 860});
    if (!button[0] || !button[1] || !button[2] || !button[3])
        return NULL;
    return button;
}

text_t **create_text_button(void)
{
    text_t **text = malloc(sizeof(*text) * 5);

    if (!text)
        return NULL;
    text[0] = create_texts("Resume", 50, (sfVector2f){855, 410}, sfWhite);
    text[1] = create_texts("Menu", 50, (sfVector2f){880, 560}, sfWhite);
    text[2] = create_texts("How2Play", 50, (sfVector2f){830, 710}, sfWhite);
    text[3] = create_texts("Quit", 50, (sfVector2f){890, 860}, sfWhite);
    text[4] = create_texts("PAUSE", 100, (sfVector2f){795, 210}, sfWhite);
    if (!text[0] || !text[1] || !text[2] || !text[3] || !text[4])
        return NULL;
    return text;
}

pause_t *init_pause(void)
{
    pause_t *pause = malloc(sizeof(*pause));

    if (!pause)
        return (NULL);
    pause->in_pause = 0;
    pause->button = create_button_texture();
    pause->text = create_text_button();
    if (!pause->button || !pause->text)
        return NULL;
    if (create_pause_texture(pause) == 84)
        return NULL;
    return (pause);
}