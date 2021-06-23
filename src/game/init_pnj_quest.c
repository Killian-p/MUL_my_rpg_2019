/*
** EPITECH PROJECT, 2020
** init pnj quest
** File description:
** rpg
*/

#include <stdlib.h>
#include <stdio.h>
#include "rpg.h"

int get_nb_quest(void)
{
    FILE *fd = fopen("config/quests.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;

    if (fd == NULL)
        return 84;
    while (getline(&buffer, &len, fd) > 0) {
        idx += 1;
    }
    fclose(fd);
    return (idx);
}

sfText **init_quest(void)
{
    FILE *fd = fopen("config/quests.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;
    sfText **texts = malloc(sizeof(sfText*) * (get_nb_quest() + 1));

    if (!texts || fd == NULL)
        return (NULL);
    while (getline(&buffer, &len, fd) > 0) {
        texts[idx] = get_text(buffer);
        idx += 1;
    }
    fclose(fd);
    texts[idx] = NULL;
    return (texts);
}

pnj_quest_t *init_pnj_quest(scene_s *stats, ret_s *value)
{
    char **map = NULL;
    pnj_quest_t *pnj = malloc(sizeof(pnj_quest_t));

    if (!pnj || !stats || !value)
        return (NULL);
    map = stats->save;
    if (map == NULL)
        return (NULL);
    if (stats->skills->reset == 0)
        pnj->quest_nb = 0;
    else
        pnj->quest_nb = parsed_quest(value->name);
    pnj->in_speak = 0;
    pnj->pnj = init_pnj(map);
    pnj->quest = init_quest();
    if (!pnj->pnj || !pnj->quest)
        return (NULL);
    return (pnj);
}