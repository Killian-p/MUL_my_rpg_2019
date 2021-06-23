/*
** EPITECH PROJECT, 2020
** create pnj
** File description:
** rpg
*/

#include <stdlib.h>
#include "rpg.h"

text_t *create_text(char *texts, int size_text, sfVector2f pos, sfColor color)
{
    text_t *text = malloc(sizeof(*text));

    if (!text)
        return NULL;
    sfText *textss = sfText_create();
    sfFont *font = sfFont_createFromFile("assets/font/chocolat.ttf");
    if (!font || !textss)
        return NULL;
    text->font = font;
    text->text = textss;
    sfText_setString(textss, texts);
    sfText_setFont(textss, font);
    sfText_setCharacterSize(textss, size_text);
    sfText_setPosition(textss, pos);
    sfText_setColor(textss, color);
    return (text);
}

pnj_t *load_pnj(sfVector2f pos, char *path, char *name, int nb)
{
    sfIntRect rect = {0, 0, 55, 60};
    pnj_t *new = malloc(sizeof(pnj_t));
    text_t *rname = create_text(name, 50, pos, sfWhite);
    sfSprite *spt = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile(path, NULL);

    if (!new || !name || !text || !rname || !spt)
        return (NULL);
    new->nb = nb;
    new->rect = rect;
    new->scale = (sfVector2f){2.7, 2.7};
    new->pnj_s = spt;
    new->pnj_t = text;
    new->next = NULL;
    new->name = rname;
    new->clock = sfClock_create();
    sfSprite_setPosition(spt, pos);
    sfSprite_setTexture(spt, text, sfTrue);
    sfSprite_setTextureRect(spt, new->rect);
    sfSprite_setScale(spt, (sfVector2f){2.7, 2.7});
    return (new);
}

void create_pnj(int idx_y, int idx_x, pnj_t **pnj, int pnj_created)
{
    char *name[2] = {"Deckard\0", "Backrith\0"};
    sfVector2f pos = {1200 + 2 * (2 * (idx_x * 150)),
    300 + 2 * (2 * (idx_y * 150))};
    char *path = "assets/pnj/pnj.png";
    pnj_t *new = NULL;

    new = load_pnj(pos, path, name[pnj_created], pnj_created);
    if (new != NULL) {
        new->next = *pnj;
        *pnj = new;
    }
}

pnj_t *init_pnj(char **map)
{
    int y = 0;
    int x = 0;
    int pnj_created = 0;
    pnj_t *pnj = NULL;

    while (map[y] != NULL) {
        if (map[y][x] == '\0') {
            x = 0;
            y += 1;
        }
        if (map[y] != NULL && map[y][x] == '4') {
            create_pnj(y, x, &pnj, pnj_created);
            pnj_created += 1;
        }
        x += 1;
    }
    return (pnj);
}