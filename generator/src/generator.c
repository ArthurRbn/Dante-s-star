/*
** EPITECH PROJECT, 2020
** my_dante
** File description:
** my_dante
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/my.h"
#include "../include/struct.h"

void cut_walls(maze_t *maze)
{
    int x = 0;
    int y = 0;

    maze->map[y][x] = '0';
    maze->map[y][x] = '0';
    while (maze->map[0][0] != '.')
        while (move(maze, &x, &y) == 1 && maze->map[0][0] != '.')
            step_back(maze, &x, &y);
    if (maze->len % 2 == 0 && maze->line % 2 == 0 &&
    maze->map[maze->line - 1][maze->len - 1] == '*' &&
    maze->map[maze->line - 2][maze->len - 1] == 'X') {
        maze->map[maze->line - 1][maze->len - 2] = '.';
        maze->map[maze->line - 1][maze->len - 1] = '.';
    }
}

void add_loops(maze_t *maze)
{
    int random = 0;

    for (int i = 0; maze->map[i] != NULL; ++i) {
        random = rand() % maze->len;
        for (; maze->map[i][random + 1] != 0 && maze->map[i][random] != 'X';
        ++random);
        maze->map[i][random] = '.';
    }
}

int exception(maze_t *maze)
{
    if (maze->len == 1) {
        for (int i = 0; i < maze->line - 1; ++i)
            printf(".\n");
        printf(".");
        return (1);
    }
    if (maze->line == 1) {
        for (int i = 0; i < maze->len; ++i)
            printf(".");
        return (1);
    }
    return (0);
}

void generate_maze(maze_t *maze)
{
    if (exception(maze) == 1)
        return;
    srand(time(NULL));
    init_tab(maze);
    cut_walls(maze);
    if (maze->perfect == 0)
        add_loops(maze);
    print_map(maze);
}

int main(int ac, char **av)
{
    maze_t *maze = malloc(sizeof(maze_t));

    if (handle_input(ac, av, maze) == 84)
        return (84);
    generate_maze(maze);
    return (0);
}