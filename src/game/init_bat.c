/*
** EPITECH PROJECT, 2020
** init and create all batiment
** File description:
** rpg
*/

#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include "rpg.h"

char **read_map(void)
{
    char **map = NULL;
    char *line = NULL;
    int fd = open("map.txt", O_RDONLY);

    if (fd <= 0)
        return (NULL);
    while ((line = get_next_line(fd)) != NULL) {
        map = my_realloc_array(map, line);
        if (map == NULL)
            return (NULL);
    }
    close(fd);
    return (map);
}

bat_t *load_bat(sfIntRect rect, sfVector2f pos, char *path)
{
    sfVector2f scale = {2, 2};
    sfSprite *spt = sfSprite_create();
    sfTexture *text = sfTexture_createFromFile(path, NULL);
    bat_t *bat = malloc(sizeof(bat_t));

    if (!bat || !spt || !text)
        return (NULL);
    bat->next = NULL;
    bat->bat_s = spt;
    bat->bat_t = text;
    sfSprite_setPosition(spt, pos);
    sfSprite_setTexture(spt, text, sfTrue);
    sfSprite_setTextureRect(spt, rect);
    sfSprite_setScale(spt, scale);
    return (bat);
}

void create_bat(char rep, int idx_y, int idx_x, bat_t **bat)
{
    sfVector2f pos = {1500 + 2 * (idx_x * 150), 100 + 2 * (idx_y * 150)};
    char *path = "assets/bat/bat.png";
    bat_t *new = NULL;

    if (rep == '1')
        new = load_bat((sfIntRect){562, 28, 387, 332}, pos, path);
    if (rep == '2')
        new = load_bat((sfIntRect){186, 659, 282, 285}, pos, path);
    if (rep == '3')
        new = load_bat((sfIntRect){166, 331, 303, 329}, pos, path);
    if (new != NULL) {
        new->next = *bat;
        *bat = new;
    }
}

bat_t *init_bat(scene_s *scene)
{
    int idx_y = 0;
    int idx_x = 0;
    char **map = read_map();
    bat_t *bat = NULL;

    if (!map)
        return (NULL);
    while (map[idx_y] != NULL) {
        if (map[idx_y][idx_x] == '\0') {
            idx_x = 0;
            idx_y += 1;
        }
        if (map[idx_y] != NULL && map[idx_y][idx_x] != '0')
            create_bat(map[idx_y][idx_x], idx_y, idx_x, &bat);
        idx_x += 1;
    }
    scene->save = map;
    return (bat);
}