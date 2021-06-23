/*
** EPITECH PROJECT, 2020
** int to str
** File description:
** runner
*/

#include <stdlib.h>

char *int_to_str(int score)
{
    char *str;
    int tmp = score;
    int i = 0;

    if (score == 0)
        return ("0");
    for (;tmp != 0; i++)
        tmp = tmp / 10;
    str = malloc(sizeof(char) * (i + 1));
    str[i] = '\0';
    i -= 1;
    while (score > 0) {
        str[i] = score % 10 + 48;
        score /= 10;
        i -= 1;
    }
    return (str);
}