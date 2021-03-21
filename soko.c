/*
** EPITECH PROJECT, 2021
** edfgb
** File description:
** dfg
*/

#include <ncurses.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "include/my.h"

void explication_game(void)
{
    my_putstr("USAGE\n");
    my_putstr("     ./my_sokoban map\n");
    my_putstr("DESCRIPTION\n");
    my_putstr("     map file representing the warehouse map");
    my_putstr(", containing '#' for walls,\n");
    my_putstr("         'P' for the player, 'X' for boxes and");
    my_putstr("'O' for storage locations.\n");
}

int count_col(char *buffer)
{
    int x = 0;
    int count = 0;

    while (buffer[x] != '\n')
        x++;
    x++;
    while (buffer[x] != '\n') {
        x++;
        count++;
    }
    return (count);
}

int count_line(char *buffer)
{
    int x = 0;
    int count = 0;

    while (buffer[x] != '\n')
        x++;
    x++;
    while (buffer[x] != '\0') {
        x++;
        if (buffer[x] == '\n')
            count++;
    }
    return (count);
}

char **fill_map(char *buffer, int size, char **tab)
{
    int i = 0;
    int o = 0;
    int row = count_line(buffer);
    int col = count_col(buffer);
    tab = malloc(sizeof(char *) * (row + 1));

    for (int j = 0; i <= row; i++) {
        tab[i] = malloc(sizeof(char) * (col + 1));
        for (j = 0; j <= col && buffer[o] != '\0'; j++, o++) {
            tab[i][j] = buffer[o];
        }
        tab[i][j] = '\0';
    }
    tab[i] = NULL;
    return (tab);
}

int main(int ac, char **av)
{
    char **tab;
    char get = '\0';

    if (ac < 2)
        return 84;
    if (av[1][0] == '-' && av[1][1] == 'h') {
        explication_game();
        return 0;
    }
    tab = create_tab(tab, av);
    if (check_fail(tab) == 84)
        return 84;
    init_game(tab);
    return 0;
}