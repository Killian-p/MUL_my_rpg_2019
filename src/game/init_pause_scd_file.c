/*
** EPITECH PROJECT, 2020
** init pause second file
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

button_t *create_button(char *path, sfVector2f pos)
{
    button_t *button = malloc(sizeof(*button));
    sfTexture *texture = sfTexture_createFromFile(path, NULL);
    sfSprite *sprite = sfSprite_create();
    sfVector2f scale = {1.5, 1.5};

    if (!button || !texture || !sprite)
        return (NULL);
    button->texture = texture;
    button->sprite = sprite;
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setScale(sprite, scale);
    return (button);
}

text_t *create_texts(char *texts, int size_text,
            sfVector2f pos, sfColor color)
{
    text_t *text = malloc(sizeof(*text));
    sfFont *font = sfFont_createFromFile("assets/serif.ttf");
    sfText *textss = sfText_create();

    if (!text || !font || !textss)
        return (NULL);
    text->font = font;
    text->text = textss;
    sfText_setString(textss, texts);
    sfText_setFont(textss, font);
    sfText_setCharacterSize(textss, size_text);
    sfText_setPosition(textss, pos);
    sfText_setColor(textss, color);
    return (text);
}