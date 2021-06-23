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

int get_nb_tuto(void)
{
    FILE *fd = fopen("config/tuto.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;

    while (getline(&buffer, &len, fd) > 0) {
        idx += 1;
    }
    fclose(fd);
    return (idx);
}

sfText **load_tuto(void)
{
    FILE *fd = fopen("config/tuto.txt", "r");
    int idx = 0;
    char *buffer = NULL;
    size_t len = 0;
    sfText **texts = malloc(sizeof(sfText*) * (get_nb_tuto() + 1));

    if (!texts || !fd)
        return (NULL);
    while (getline(&buffer, &len, fd) > 0) {
        texts[idx] = get_text(buffer);
        if (texts[idx] == NULL)
            return NULL;
        idx += 1;
    }
    fclose(fd);
    texts[idx] = NULL;
    return (texts);
}