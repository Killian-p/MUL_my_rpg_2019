/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** create_user
*/

#include "my.h"
#include <sys/stat.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

char *create_path(char *buffer)
{
    char *copy = "users/";
    int i;

    buffer = malloc(sizeof(char) * 7);
    for (i = 0; copy[i] != '\0'; i++)
        buffer[i] = copy[i];
    buffer[i] = '\0';
    return buffer;
}

static void create_file_in_path(char *buffer, control_t *ctl)
{
    int fd = 0;
    int len = 0;

    buffer = my_strcat(buffer, ctl->settings->username);
    fd = open(buffer, O_CREAT | O_RDWR, 0777);
    len = my_strlen(ctl->settings->password) + 1;
    ctl->settings->password = my_strcat(ctl->settings->password, "\n");
    if (fd > 0) {
        write(fd, ctl->settings->password, len);
        close(fd);
    }
    sfRenderWindow_close(ctl->window);
    if (create_game(ctl->settings->username, 0) == NULL)
        ctl->settings->error = 84;
    else
        ctl->settings->error = 0;
}

void create_user_and_launch(control_t *ctl)
{
    char *buffer = NULL;

    buffer = create_path(buffer);
    create_file_in_path(buffer, ctl);
}