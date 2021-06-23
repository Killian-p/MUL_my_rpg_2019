/*
** EPITECH PROJECT, 2020
** src
** File description:
** main
*/

#include "my.h"

static int display_h(void)
{
    my_putstr("Usage: ./my_rpg\n");
    my_putstr("If users directory doesn't exit please create its at root\n");
    return 0;
}

int main(int argc, char **argv, char **envp)
{
    if (*envp == NULL)
        return (84);
    if (argc != 1 && argc != 2)
        return (84);
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        return display_h();
    } else {
        return start_launcher();
    }
    return (0);
}