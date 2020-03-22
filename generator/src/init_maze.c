/*
** EPITECH PROJECT, 2020
** init maze
** File description:
** init maze
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/struct.h"

void print_map(maze_t *maze)
{
    for (int i = 0; maze->map[i]; ++i) {
        for (int j = 0; maze->map[i][j] != 0; ++j) {
            if (maze->map[i][j] != 'X')
                write(1, "*", 1);
            else
                write(1, "X", 1);
        }
        if (i < maze->line - 1)
            write(1, "\n", 1);
    }
}

int defaut_move2(maze_t *maze, int *x, int *y)
{
    if (*x > 1 && maze->map[*y][*x - 2] == '*') {
        maze->map[*y][*x - 1] = '1';
        maze->map[*y][*x - 2] = '1';
        *x -= 2;
        return (0);
    } else if (*x < maze->len - 2 && maze->map[*y][*x + 2] == '*') {
        maze->map[*y][*x + 1] = '1';
        maze->map[*y][*x + 2] = '1';
        *x += 2;
        return (0);
    }
    return (1);
}

int handle_input(int ac, char **av, maze_t *maze)
{
    if (ac < 3)
        return (84);
    maze->len = atoi(av[1]);
    maze->line = atoi(av[2]);
    if (maze->line < 1 || maze->len < 1)
        return (84);
    if (ac > 3 && strcmp(av[3], "perfect") != 0)
        return (84);
    if (ac > 3 && strcmp(av[3], "perfect") == 0)
        maze->perfect = 1;
    else
        maze->perfect = 0;
}

void init_tab(maze_t *maze)
{
    maze->map = malloc(sizeof(char *) * (maze->line + 1));
    maze->map[maze->line] = NULL;
    for (int i = 0; i < maze->line; ++i) {
        maze->map[i] = malloc(sizeof(char) * (maze->len + 1));
        if (!maze->map[i])
            --i;
        if (i % 2 == 1)
            memset(maze->map[i], 'X', maze->len);
        maze->map[i][maze->len] = 0;
    }
    for (int i = 0; maze->map[i]; ++i)
        for (int j = 0; i % 2 == 0 && j < maze->len != 0; ++j)
            maze->map[i][j] = (j % 2 == 1)? 'X' : '*';
    maze->map[0][0] = '*';
    maze->map[maze->line - 1][maze->len - 1] = '*';
}