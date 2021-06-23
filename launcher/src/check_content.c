/*
** EPITECH PROJECT, 2020
** launcher
** File description:
** check_content
*/

#include "my.h"
#include <string.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int check_mdp(char *file, control_t *ctl)
{
    int len = my_strlen(ctl->settings->password) + 1;
    char *buffer = NULL;
    buffer = create_path(buffer);
    buffer = my_strcat(buffer, file);
    int fd = open(buffer, O_RDONLY);
    char *password_use = malloc(sizeof(char) * len);
    read(fd, password_use, len);

    if (password_use[len - 1] != '\n' || password_use == NULL) {
        close(fd);
        return 0;
    }
    return my_strncmp(password_use,
    ctl->settings->password, len - 1) == 0 ? 1 : 0;
}

static void check_existence(control_t *ctl)
{
    struct dirent *file = NULL;
    DIR *dir = opendir("users");
    int bool = 0;
    int user = 0;
    int mdp = 0;

    if (dir == NULL)
        return;
    file = readdir(dir);
    while (file != NULL) {
        user = check_equals(file->d_name, ctl->settings->username);
        mdp = check_mdp(file->d_name, ctl);
        if (mdp == 1 && user == 1) {
            sfRenderWindow_close(ctl->window);
            if (create_game(ctl->settings->username, 1) == NULL)
                ctl->settings->error = 84;
        }
        file = readdir(dir);
    }
    ctl->settings->reg_box = bool;
}

static int check_empty(char *buffer)
{
    int i = 0;
    for (i = 0; buffer[i] != '\0'; i++);
    return i;
}

void check_field(control_t *ctl)
{
    int len_first = check_empty(ctl->settings->username);
    int len_second = check_empty(ctl->settings->password);

    if (len_first == 0) {
        ctl->settings->usr_valid = -1;
        ctl->possible = 1;
    } else if (len_second == 0) {
        ctl->possible = 1;
        ctl->settings->pass_valid = -1;
    } else {
        check_existence(ctl);
    }
}