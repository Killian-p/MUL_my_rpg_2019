/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** launcher_stats
*/

#include "rpg.h"
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

static char *strcat_stats(char *s1, char *s2)
{
    char *result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 2));
    int i = 0;

    for (int f = 0; s1[f]; f++, i++)
        result[i] = s1[f];
    result[i] = '\n';
    i++;
    for (int f = 0; s2[f]; f++, i++)
        result[i] = s2[f];
    result[i] = '\0';
    return (result);
}

static char *strcat_path(char *s1, char *s2)
{
    char *result = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));
    int i = 0;

    for (int f = 0; s1[f]; f++, i++)
        result[i] = s1[f];
    for (int f = 0; s2[f]; f++, i++)
        result[i] = s2[f];
    result[i] = '\0';
    return (result);
}

static char *stats_save(scene_s *value, pnj_quest_t *pq)
{
    char *to_write = int_to_str(value->skills->accuracy);
    int posx = value->player->p.x;
    int posy = value->player->p.y;

    to_write = strcat_stats(to_write, int_to_str(value->skills->chance));
    to_write = strcat_stats(to_write, int_to_str(value->skills->intelligence));
    to_write = strcat_stats(to_write, int_to_str(value->skills->skillpoints));
    to_write = strcat_stats(to_write, int_to_str(value->skills->stamina));
    to_write = strcat_stats(to_write, int_to_str(value->skills->strength));
    to_write = strcat_stats(to_write, int_to_str(value->skills->type_char));
    to_write = strcat_stats(to_write, int_to_str(value->skills->vitality));
    to_write = strcat_stats(to_write, int_to_str(posx));
    to_write = strcat_stats(to_write, int_to_str(posy));
    to_write = strcat_stats(to_write, int_to_str(pq->quest_nb));
    to_write = strcat_path(to_write, "\n");
    return to_write;
}

static void empty_file(char *file)
{
    int fd = open(file, O_RDWR);
    if (fd < 0)
        return;
    char *buffer = get_next_line(fd);
    int total_len = 0;
    char *empty = NULL;

    while (buffer) {
        total_len += my_strlen(buffer);
        buffer = get_next_line(fd);
    }
    empty = malloc(sizeof(char) * total_len);
    for (int i = 0; i < total_len; i++) {
        empty[i] = '\0';
    }
    write(fd, empty, total_len);
    close(fd);
}

void save_player_stats(scene_s *value, pnj_quest_t *pq, ret_s *save)
{
    char *name = strcat_path("users/", save->name);
    int fd = open(name, O_RDWR);
    char *to_write = stats_save(value, pq);
    char *pass = NULL;

    if (fd < 0)
        return;
    pass = get_next_line(fd);
    pass = strcat_stats(pass, to_write);
    close(fd);
    empty_file(name);
    fd = open(name, O_RDWR);
    write(fd, pass, my_strlen(pass));
}