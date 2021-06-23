/*
** EPITECH PROJECT, 2020
** undefined
** File description:
** my_putstr
*/

#include <unistd.h>
#include <stdlib.h>

int my_putstr(char *str)
{
    register int i = 0;
    int error = 0;

    if (str != NULL) {
        for (i = 0; str[i] != '\0'; i++);
        error = write(1, str, i);
        if (error != i) {
            return 84;
        }
        return 0;
    } else {
        return 84;
    }
}

int my_puterror(char *str)
{
    register int i = 0;
    int error = 0;

    if (str != NULL) {
        for (i = 0; str[i] != '\0'; i++);
        error = write(2, str, i);
        if (error != i) {
            return 84;
        }
        return 0;
    } else {
        return 84;
    }
}