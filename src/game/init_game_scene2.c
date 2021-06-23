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

int set_text_gutlet(gutlet_s *gutlet)
{
    sfFont *font = sfFont_createFromFile("assets/font/chocolat.ttf");
    sfVector2f p = {1140, 895};
    int idx = 0;

    if (!font)
        return 84;
    while (idx < 3) {
        gutlet->text[idx] = sfText_create();
        if (!gutlet->text[idx])
            return 84;
        sfText_setPosition(gutlet->text[idx], p);
        sfText_setFont(gutlet->text[idx], font);
        sfText_setCharacterSize(gutlet->text[idx], 30);
        sfText_setColor(gutlet->text[idx], (sfColor){255, 255, 255, 255});
        sfText_setString(gutlet->text[idx], int_to_str(gutlet->gutlets[idx]));
        p.y += 40;
        idx += 1;
    }
    return 0;
}

int create_gutlets(gutlet_s *gutlet)
{
    sfIntRect r = {0, 0, 40, 45};
    sfVector2f p = {1100, 895};

    gutlet->green = create_obj("assets/green_gutlet.png", p, r, 0);
    p.y = 935;
    gutlet->blue = create_obj("assets/blue_gutlet.png", p, r, 0);
    p.y = 975;
    gutlet->red = create_obj("assets/red_gutlet.png", p, r, 0);
    gutlet->text = malloc(sizeof(sfText*) * 3);
    if (!gutlet->text || !gutlet->green || !gutlet->blue || !gutlet->red)
        return (84);
    set_text_gutlet(gutlet);
    return (0);
}

int set_banner(scene_s *sc)
{
    sfIntRect r = {0, 0, 600, 900};
    sfVector2f pos = {0, 150};

    sc->banner = create_obj("assets/banner_show.png", pos, r, 0);
    if (!sc->banner)
        return 84;
    sfSprite_setScale(sc->banner->sprite, (sfVector2f){0.8, 0.8});
    sc->skills_text = get_skills_text();
    if (sc->skills_text == NULL)
        return 84;
    return 0;
}

int set_spell(scene_s *sc)
{
    char *path = "assets/spell.png";
    char *path2 = "assets/elec.png";
    sfIntRect r = {0, 0, 820, 820};
    sfIntRect r2 = {0, 0, 250, 262};
    sfVector2f p2 = {0, 0};

    sc->spell = malloc(sizeof(spell_s));
    if (sc->spell == NULL)
        return (84);
    sc->spell->spell_area = create_obj(path, (sfVector2f){0, 0}, r, 0);
    sc->spell->spell = create_obj(path2, p2, r2, 0);
    sfSprite_setOrigin(sc->spell->spell_area->sprite, (sfVector2f){410, 410});
    sfSprite_setOrigin(sc->spell->spell->sprite, (sfVector2f){125, 131});
    sfSprite_setScale(sc->spell->spell_area->sprite, (sfVector2f){0.5, 0.5});
    sfSprite_setScale(sc->spell->spell->sprite, (sfVector2f){2, 2});
    sc->spell->cast = 0;
    sc->spell->anim = 0;
    if (!sc->spell->spell_area || !sc->spell->spell
    || init_game_volume_display(sc) == 84)
        return (84);
    return (0);
}

int keep_on_init(scene_s *sc)
{
    sc->gutlet = malloc(sizeof(gutlet_s));
    if (sc->gutlet == NULL)
        return (84);
    sc->gutlet->gutlets = malloc(sizeof(int) * 3);
    if (sc->gutlet->gutlets == NULL)
        return (84);
    sc->gutlet->gutlets[0] = 0;
    sc->gutlet->gutlets[1] = 0;
    sc->gutlet->gutlets[2] = 0;
    if (create_gutlets(sc->gutlet) == 84)
        return (84);
    if (create_boss(sc) == 84)
        return (84);
    sc->totem = 0;
    sc->get_item = 0;
    sc->buttons = get_buttons_skill();
    if (set_banner(sc) == 84 || set_spell(sc) == 84 || !sc->buttons)
        return (84);
    return (0);
}