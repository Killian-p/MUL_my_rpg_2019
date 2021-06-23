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

int get_nb_text(void)
{
    FILE *fd = fopen("config/texts.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;

    if (fd == NULL)
        return (0);
    while (getline(&buffer, &len, fd) > 0) {
        idx += 1;
    }
    fclose(fd);
    return (idx);
}

sfText* get_text(char *buffer)
{
    sfVector2f pos = get_pos(buffer);
    sfVector2f origin = get_origin(buffer);
    sfColor color = get_color(buffer);
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(get_font(buffer));

    if (!text || !font)
        return (NULL);
    sfText_setFont(text, font);
    sfText_setPosition(text, pos);
    sfText_setOrigin(text, origin);
    sfText_setCharacterSize(text, get_size(buffer));
    sfText_setColor(text, color);
    sfText_setString(text, get_str(buffer));
    return (text);
}

sfText* *get_texts(void)
{
    FILE *fd = fopen("config/texts.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;
    sfText* *texts = malloc(sizeof(sfText*) * (get_nb_text() + 1));

    if (fd == NULL)
        return (NULL);
    while (getline(&buffer, &len, fd) > 0) {
        if ((texts[idx] = get_text(buffer)) == NULL)
            return (NULL);
        idx += 1;
    }
    fclose(fd);
    texts[idx] = NULL;
    return (texts);
}