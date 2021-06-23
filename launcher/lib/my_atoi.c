/*
** EPITECH PROJECT, 2020
** MUL_my_rpg_2019
** File description:
** my_atoi
*/

static int check_str(char *str)
{
    for (int i = 0; str[i]; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
    }
    return 0;
}

int my_atoi(char *str)
{
    int i = 0;
    int v = 0;
    int minus = 0;

    if (check_str(str) == -1)
        return 0;
    while (str[i] != '\0') {
        if (str[i] == '-') {
            minus = 1;
            i += 1;
        }
        v = v * 10 + (str[i] - 48);
        i += 1;
    }
    if (minus == 1)
        v = v * (-1);
    return (v);
}