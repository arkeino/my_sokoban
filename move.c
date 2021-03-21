/*
** EPITECH PROJECT, 2021
** dfg
** File description:
** dfg
*/

#include <curses.h>
#include "include/my.h"

char **move_up(char **tab, find_p P)
{
    if (tab[P.x - 1][P.y] == ' ') {
        tab[P.x][P.y] = ' ';
        tab[P.x - 1][P.y] = 'P';
    }
    else if (tab[P.x - 1][P.y] == 'X' && tab[P.x - 2][P.y]
    != '#' && tab[P.x - 2][P.y] != 'X') {
        tab[P.x][P.y] = ' ';
        tab[P.x - 1][P.y] = 'P';
        tab[P.x - 2][P.y] = 'X';
    }
    if (tab[P.x - 1][P.y] == 'O') {
        tab[P.x - 1][P.y] = 'P';
        tab[P.x][P.y] = ' ';
    }
    if (tab[P.x - 1][P.y - 1] == 'P') {
        tab[P.x - 1][P.y - 1] = 'O';
        tab[P.x][P.y] = 'P';
        }
    return tab;
}

char **move_down(char **tab, struct P find_p)
{
    if (tab[find_p.x + 1][find_p.y] == ' ') {
        tab[find_p.x][find_p.y] = ' ';
        tab[find_p.x + 1][find_p.y] = 'P';
    }
    else if (tab[find_p.x + 1][find_p.y] == 'X' && tab[find_p.x + 2][find_p.y]
    != '#' && tab[find_p.x + 2][find_p.y] != 'X') {
        tab[find_p.x][find_p.y] = ' ';
        tab[find_p.x + 1][find_p.y] = 'P';
        tab[find_p.x + 2][find_p.y] = 'X';
    }
    if (tab[find_p.x + 1][find_p.y] == 'O') {
        tab[find_p.x + 1][find_p.y] = 'P';
        tab[find_p.x][find_p.y] = ' ';
    }
    if (tab[find_p.x + 1][find_p.y - 1] == 'P') {
        tab[find_p.x + 1][find_p.y - 1] = 'O';
        tab[find_p.x][find_p.y] = 'P';
        }
    return tab;
}

char **move_right(char **tab, struct P find_p)
{
    if (tab[find_p.x][find_p.y + 1] == ' ') {
        tab[find_p.x][find_p.y] = ' ';
        tab[find_p.x][find_p.y + 1] = 'P';
    }
    else if (tab[find_p.x][find_p.y + 1] == 'X' && tab[find_p.x][find_p.y + 2]
    != '#' && tab[find_p.x][find_p.y + 2] != 'X') {
        tab[find_p.x][find_p.y] = ' ';
        tab[find_p.x][find_p.y + 1] = 'P';
        tab[find_p.x][find_p.y + 2] = 'X';
    }
    if (tab[find_p.x][find_p.y + 1] == 'O') {
        tab[find_p.x][find_p.y + 1] = 'P';
        tab[find_p.x][find_p.y] = ' ';
    }
    if (tab[find_p.x][find_p.y - 1] == 'P') {
        tab[find_p.x][find_p.y - 1] = 'O';
        tab[find_p.x][find_p.y] = 'P';
        }
    return tab;
}

char **move_left(char **tab, struct P find_p)
{
    if (tab[find_p.x][find_p.y - 1] == ' ') {
        tab[find_p.x][find_p.y] = ' ';
        tab[find_p.x][find_p.y - 1] = 'P';
    }
    else if (tab[find_p.x][find_p.y - 1] == 'X' && tab[find_p.x][find_p.y - 2]
    != '#' && tab[find_p.x][find_p.y - 2] != 'X') {
        tab[find_p.x][find_p.y] = ' ';
        tab[find_p.x][find_p.y - 1] = 'P';
        tab[find_p.x][find_p.y - 2] = 'X';
    }
    if (tab[find_p.x][find_p.y - 1] == 'O') {
        tab[find_p.x][find_p.y - 1] = 'P';
        tab[find_p.x][find_p.y] = ' ';
    }
    if (tab[find_p.x][find_p.y + 1] == 'P') {
        tab[find_p.x][find_p.y + 1] = 'O';
        tab[find_p.x][find_p.y] = 'P';
        }
    return tab;
}

char **map_switch(char **tab, struct P find_p, int key)
{
    switch (key) {
    case 65:
        tab = move_up(tab, find_p);
        return tab;
    case 67:
        tab = move_right(tab, find_p);
        return tab;
    case 66:
        tab = move_down(tab, find_p);
        return tab;
        case 68:
        tab = move_left(tab, find_p);
        return tab;
    default:
        break;
    }
}
