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

int get_nb_text_stat(void)
{
    FILE *fd = fopen("config/stat.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;

    if (!fd)
        return 84;
    while (getline(&buffer, &len, fd) > 0) {
        idx += 1;
    }
    fclose(fd);
    return (idx);
}

sfText* *get_skills_text(void)
{
    FILE *fd = fopen("config/stat.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;
    sfText **texts = malloc(sizeof(sfText * ) * (get_nb_text_stat() + 1));

    if (!fd || !texts)
        return NULL;
    while (getline(&buffer, &len, fd) > 0) {
        texts[idx] = get_text(buffer);
        if (!texts[idx])
            return NULL;
        idx += 1;
    }
    fclose(fd);
    texts[idx] = NULL;
    return (texts);
}
