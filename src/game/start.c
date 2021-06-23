/*
** EPITECH PROJECT, 2020
** start game with login or register
** File description:
** rpg
*/

#include "rpg.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void complete_stats(skill_s *skill, char **array)
{
    skill->accuracy = my_atoi(array[1]);
    skill->chance = my_atoi(array[2]);
    skill->intelligence = my_atoi(array[3]);
    skill->skillpoints = my_atoi(array[4]);
    skill->stamina = my_atoi(array[5]);
    skill->strength = my_atoi(array[6]);
    skill->type_char = my_atoi(array[7]);
    skill->vitality = my_atoi(array[8]);
    skill->reset = 1;
}

static void default_stats(skill_s *skill)
{
    skill->accuracy = 0;
    skill->chance = 0;
    skill->intelligence = 0;
    skill->skillpoints = 10;
    skill->stamina = 0;
    skill->strength = 0;
    skill->type_char = 0;
    skill->vitality = 0;
    skill->reset = 0;
}

static void load_stats(char **array, char *user, skill_s *skill)
{
    int fd = open(user, O_RDONLY);
    char *stats = NULL;
    int i = 0;

    if (fd < 0)
        return;
    do {
        stats = get_next_line(fd);
        array[i] = stats;
        i++;
    } while (stats);
    array[i] = NULL;
    free(stats);
    close(fd);
    if (i >= 12)
        complete_stats(skill, array);
    else
        default_stats(skill);
}

void parsed_stats(char *name, skill_s *skill)
{
    char **array = NULL;
    char *user = my_strcat("users/", name);
    int fd = open(user, O_RDONLY);
    char *stats = NULL;
    int len = 1;

    if (fd < 0)
        return;
    stats = get_next_line(fd);
    while (stats) {
        ++len;
        stats = get_next_line(fd);
    }
    array = malloc(sizeof(char *) * (len + 1));
    if (array == NULL)
        return;
    close(fd);
    load_stats(array, user, skill);
}