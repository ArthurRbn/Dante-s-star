/*
** EPITECH PROJECT, 2020
** maze move
** File description:
** maze move
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/my.h"
#include "../include/struct.h"

int default_move(maze_t *maze, int *x, int *y)
{
    if (*y > 1 && maze->map[*y - 2][*x] == '*') {
        maze->map[*y - 1][*x] = '1';
        maze->map[*y - 2][*x] = '1';
        *y -= 2;
        return (0);
    } else if (*y < maze->line - 2 && maze->map[*y + 2][*x] == '*') {
        maze->map[*y + 1][*x] = '1';
        maze->map[*y + 2][*x] = '1';
        *y += 2;
        return (0);
    }
    return (defaut_move2(maze, x, y));
}

int move2(maze_t *maze, int *x, int *y, int i)
{
    if (i == 2 && *x > 1 && maze->map[*y][*x - 2] == '*') {
        maze->map[*y][*x - 1] = '1';
        maze->map[*y][*x - 2] = '1';
        *x -= 2;
        return (0);
    } else if (i == 3 && *x < maze->len - 2 && maze->map[*y][*x + 2] == '*') {
        maze->map[*y][*x + 1] = '1';
        maze->map[*y][*x + 2] = '1';
        *x += 2;
        return (0);
    }
    return (default_move(maze, x, y));
}

int move(maze_t *maze, int *x, int *y)
{
    int i = rand() % 4;

    if (i == 0 && *y > 1 && maze->map[*y - 2][*x] == '*') {
        maze->map[*y - 1][*x] = '1';
        maze->map[*y - 2][*x] = '1';
        *y -= 2;
        return (0);
    } else if (i == 1 && *y < maze->line - 2 && maze->map[*y + 2][*x] == '*') {
        maze->map[*y + 1][*x] = '1';
        maze->map[*y + 2][*x] = '1';
        *y += 2;
        return (0);
    }
    return (move2(maze, x, y, i));
}

void step_back2(maze_t *maze, int *x, int *y)
{
    if (*x > 1 && maze->map[*y][*x - 1] == '1') {
        maze->map[*y][*x - 1] = '.';
        maze->map[*y][*x - 2] = '.';
        *x -= 2;
    } else if (*x < maze->len - 2 && maze->map[*y][*x + 1] == '1') {
        maze->map[*y][*x + 1] = '.';
        maze->map[*y][*x + 2] = '.';
        *x += 2;
    }
}

void step_back(maze_t *maze, int *x, int *y)
{
    maze->map[*y][*x] = '.';
    if (*y > 1 && maze->map[*y - 1][*x] == '1') {
        maze->map[*y - 1][*x] = '.';
        maze->map[*y - 2][*x] = '.';
        *y -= 2;
    } else if (*y < maze->line - 2 && maze->map[*y + 1][*x] == '1') {
        maze->map[*y + 1][*x] = '.';
        maze->map[*y + 2][*x] = '.';
        *y += 2;
    } else
        step_back2(maze, x, y);
}