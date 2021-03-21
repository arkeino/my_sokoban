/*
** EPITECH PROJECT, 2021
** dfgh
** File description:
** dfgh
*/

#include <curses.h>
#include "include/my.h"

char **refresh_o(char **tab, int *k)
{

    for (int i = 0; k[i] != - 1; i += 2) {
        if (tab[k[i]][k[i + 1]] == ' ') {
            tab[k[i]][k[i + 1]] = 'O';
        }
    }
    return tab;
}