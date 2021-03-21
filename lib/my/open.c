/*
** EPITECH PROJECT, 2021
** sdfg
** File description:
** dfgh
*/

#include <stddef.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../../include/my.h"

int open_files(char *av)
{
    int fd;

    fd = open(av, O_RDONLY);

    if (fd == -1)
        exit(84);

    return fd;
}

int read_files(int fd, int size, char *buffer)
{
    int res;

    res = read(fd, buffer, size);
    if (res == -1)
        exit(84);
    if (res != size)
        exit(84);

    return res;
}

char **create_tab(char **tab, char **av)
{
    struct stat s;
    int size;
    int fd = open_files(av[1]);
    char *buffer;
    int res;
    int row;
    int col;

    stat(av[1], &s);
    size = s.st_size;
    buffer = malloc(sizeof(char) * (size + 1));
    res = read_files(fd, size, buffer);
    buffer[res] = '\0';
    row = my_getnbr(buffer);
    col = count_col(buffer);
    tab = fill_map(buffer, size, tab);
    close(fd);
    return (tab);
}
