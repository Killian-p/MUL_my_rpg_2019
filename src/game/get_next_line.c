/*
** EPITECH PROJECT, 2019
** get_next_line
** File description:
** get_next_line
*/

#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

#include "get_next_line.h"

char *my_realloc(int *read_tot, char *res_str)
{
    char *save = res_str;
    int i = 0;

    *read_tot += READ_SIZE;
    res_str = malloc(sizeof(char) * *read_tot + 1);
    if (res_str == NULL)
        return (NULL);
    while (i != (*read_tot - READ_SIZE)) {
        res_str[i] = save[i];
        i += 1;
    }
    free(save);
    return (res_str);
}

char find_char(int fd)
{
    static int i = READ_SIZE;
    static char str_read[READ_SIZE];
    char letter = 'a';
    int error = 0;
    int index = 0;

    if (i == READ_SIZE) {
        while (index != READ_SIZE) {
            str_read[index] = '\0';
            index += 1;
        }
        str_read[READ_SIZE];
        error = read(fd, str_read, READ_SIZE);
        str_read[error] = '\0';
        if (error <= 0)
            return (-1);
        i = 0;
    }
    letter = str_read[i];
    i += 1;
    return (letter);
}

char *end_str(char *res_str, int i, char letter)
{
    res_str[i] = '\0';
    if (letter == '\0' && res_str[0] == '\0')
        return (NULL);
    return (res_str);
}

char *get_next_line(int fd)
{
    int i = 0;
    char letter = 'a';
    int read_tot = READ_SIZE;
    char *res_str = malloc(sizeof(char) * READ_SIZE + 1);

    if (res_str == NULL || fd < 0)
        return (NULL);
    while (letter != '\n' && letter != '\0') {
        letter = find_char(fd);
        if (letter == '\n' || letter == '\0')
            break;
        if (letter == -1)
            return (NULL);
        res_str[i] = letter;
        i += 1;
        if (i == read_tot)
            res_str = my_realloc(&read_tot, res_str);
        if (res_str == NULL)
            return (NULL);
    }
    return (end_str(res_str, i, letter));
}