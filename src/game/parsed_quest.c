/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** parsed_quest
*/

#include "rpg.h"
#include <fcntl.h>

int parsed_quest(char *name)
{
    char *user = my_strcat("users/", name);
    int fd = open(user, O_RDONLY);
    char *stats = NULL;
    int i = 0;

    if (fd < 0)
        return (84);
    do {
        stats = get_next_line(fd);
        i++;
        if (i == 12) {
            return my_atoi(stats);
        }
    } while (stats);
    return (0);
}