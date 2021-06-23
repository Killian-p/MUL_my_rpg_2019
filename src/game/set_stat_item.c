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

char *change_path2(char *str, int type, int nb)
{
    char *item = malloc(sizeof(char) * (my_strlen(str) + 1));
    int idx = 0;

    if (item == NULL)
        return (NULL);
    while (idx != 13) {
        item[idx] = str[idx];
        idx += 1;
    }
    item[idx] = type + 48;
    idx += 1;
    item[idx] = 47;
    idx += 1;
    item[idx] = nb + 48;
    idx += 1;
    while (str[idx] != '\0') {
        item[idx] = str[idx];
        idx += 1;
    }
    item[idx] = '\0';
    return (item);
}

void set_id_path(items_s *item, char *path)
{
    int idx = 0;

    while (path[idx] < 0 + 48 || path[idx] > 9 + 48) {
        idx += 1;
    }
    item->id[0] = path[idx] - 48;
    idx += 2;
    item->id[1] = path[idx] - 48;
}

int set_stats_item(items_s *item, char *path)
{
    set_id_path(item, path);
    FILE *fd = fopen(get_file_id(item), "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;

    if (fd == NULL)
        return (84);
    while (getline(&buffer, &len, fd) > 0) {
        item->bonus[idx] = atoi_for_items(buffer);
        idx += 1;
    }
    if (idx != 10)
        return (84);
    fclose(fd);
    return (0);
}

void drop_it(scene_s *sc, enn_s *tmp, char *path)
{
    items_s *item = malloc(sizeof(items_s));

    if (item == NULL)
        return;
    if (set_stats_item(item, path) == 84)
        return;
    item->disp_effect = 0;
    item->next = NULL;
    item->path = path;
    if (set_graphics_item(item, tmp, path) == 84)
        return;
    add_item(item, &sc->items);
}

void drop_random(scene_s *sc, enn_s *tmp)
{
    int chance = rand() % 100;
    int type = rand() % 4;
    int item = rand () % 7;
    char *path = "assets/items/n/n.png";

    if (chance > tmp->drop_chance + sc->skills->chance)
        return;
    path = change_path2(path, type, item);
    drop_it(sc, tmp, path);
}