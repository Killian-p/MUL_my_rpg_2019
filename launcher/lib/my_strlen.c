/*
** EPITECH PROJECT, 2019
** my_strlen.c
** File description:
** my_strlen.c formula
*/

int my_strlen(char const *str)
{
    int nb = 0;

    while (str[nb] != '\0') {
        nb = (nb + 1);
    }
    return (nb);
}
