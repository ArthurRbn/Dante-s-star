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

//solver.c
int backtracking(solve_t *solver);
int resolve_maze(solve_t *maze);

//backtracking.c
int default_move2(solve_t *maze, int *x, int *y);
int default_move(solve_t *maze, int *x, int *y);
int step_back(solve_t *maze, int *x, int *y);

//init_maze.C
void print_map(solve_t *maze);
int count_lines(char *file);
int handle_input2(solve_t *maze, int fd);
int handle_input(int ac, char **av, solve_t *maze);
char *get_next_line(int fd);

#endif //MY_H