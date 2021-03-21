/*
** EPITECH PROJECT, 2021
** sdfg
** File description:
** dfgh
*/

#include <curses.h>
#include <stdlib.h>
#include "include/my.h"

find_p find_letter(char **tab, find_p P)
{
    int i = 0;
    int j = 0;

    while (tab[i] != NULL) {
        while (tab[i][j] != '\0') {
            if (tab[i][j] == 'P' || tab[i][j] == 'A') {
                P.x = i;
                P.y = j;
            }
            j++;
        }
        i++;
        j = 0;
    }
    return P;
}

int *malloc_o(char **tab)
{
    int a = 0;
    int *k;
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] == 'O')
                a++;
        k = malloc(sizeof(int) * (a * 2 + 1));
        }
    }
    return k;
}

int *find_o(char **tab)
{
    int a = 0;
    int *k = malloc_o(tab);
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\0'; j++) {
            if (tab[i][j] == 'O') {
                k[a] = i;
                k[a + 1] = j;
                a += 2;
            }
        }
    }
    k[a] = (- 1);
    for (int i = 0; k[i] != -1; i++)
    return k;
}

int check_fail(char **tab)
{
    for (int i = 0; tab[i] != NULL; i++) {
        for (int j = 0; tab[i][j] != '\n'; j++) {
            if (tab[i][j] != '#' && tab[i][j] != ' ' && tab[i][j] != 'O'
            && tab[i][j] != 'X' && tab[i][j] != 'P'
            && tab[i][j] != "'\n'")
                return 84;
                else
                {
                    return 1;
                }
        }
    }
}

int init_game(char **tab)
{

    char get = '\0';
    struct P find_p;
    int *k = find_o(tab);

    initscr();
    noecho();
    curs_set(0);
    while (get != 'q') {
        tab = refresh_o(tab, k);
        for (int i = 0; tab[i] != NULL; i++) {
            mvprintw(i, 50, tab[i]);
        }
        find_p = find_letter(tab, find_p);
        get = getch();
        tab = map_switch(tab, find_p, get);
        refresh();
    }
    endwin();
}
