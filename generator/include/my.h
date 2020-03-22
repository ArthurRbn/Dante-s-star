/*
** EPITECH PROJECT, 2019
** my
** File description:
** my
*/

#ifndef MY_H
#define MY_H

#include <stdarg.h>
#include <unistd.h>
#include "struct.h"

//generator.c
void cut_walls(maze_t *maze);
void add_loops(maze_t *maze);
int exception(maze_t *maze);
void generate_maze(maze_t *maze);

//maze_move.c
int default_move(maze_t *maze, int *x, int *y);
int move2(maze_t *maze, int *x, int *y, int i);
int move(maze_t *maze, int *x, int *y);
void step_back2(maze_t *maze, int *x, int *y);
void step_back(maze_t *maze, int *x, int *y);

//init_maze.C
void print_map(maze_t *maze);
int defaut_move2(maze_t *maze, int *x, int *y);
int handle_input(int ac, char **av, maze_t *maze);
void init_tab(maze_t *maze);

#endif //MY_H