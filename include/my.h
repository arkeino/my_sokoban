/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** my
*/

#ifndef MY_H
#define MY_H

typedef struct P
{
    int x;
    int y;

}find_p;

void explication_game(void);
void my_putchar(char c);
int my_putstr(char const *str);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_getnbr(char const *str);
char *my_strdup(char const *src);
char **create_tab(char **tab, char **av);
int count_col(char *buffer);
int count_line(char *buffer);
char **fill_map(char *buffer, int size, char **tab);
int open_files(char *av);
int read_files(int fd, int size, char *buffer);
int init_game(char **tab);
char **map_switch(char **tab, struct P find_p, int key);
char **move_up(char **tab, struct P find_p);
char **move_down(char **tab, struct P find_p);
char **move_left(char **tab, struct P find_p);
char **move_right(char **tab, struct P find_p);
int check_fail(char **tab);
int *malloc_o(char **tab);
int *find_o(char **tab);
char **refresh_o(char **tab, int *k);


#endif /* !my */
