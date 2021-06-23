/*
** EPITECH PROJECT, 2019
** lemin
** File description:
** read_anthill
*/

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include "rpg.h"

char *getstr(char *buffer)
{
    int idx = 0;
    char *str = malloc(sizeof(char) * (my_strlen(buffer) + 1));

    while (buffer[idx] != '\0') {
        str[idx] = buffer[idx];
        idx += 1;
    }
    str[idx] = '\0';
    return (str);
}

int len_array(char **map)
{
    int idx = 0;

    if (!map)
        return (0);
    while (map[idx] != NULL) {
        idx += 1;
    }
    return (idx);
}

char **my_realloc_array(char **map, char *buffer)
{
    char **ret = malloc(sizeof(char *) * (len_array(map) + 2));
    int idx = 0;

    if (!map) {
        ret[0] = buffer;
        ret[1] = NULL;
        return (ret);
    }
    while (map[idx] != NULL) {
        ret[idx] = getstr(map[idx]);
        idx += 1;
    }
    ret[idx] = getstr(buffer);
    ret[idx + 1] = NULL;
    return (ret);
}