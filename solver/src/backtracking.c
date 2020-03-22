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

int defaut_move2(solve_t *solver, int *x, int *y)
{
    if (*y > 0 && solver->map[*y - 1][*x] == '*') {
        *y -= 1;
        solver->map[*y][*x] = '1';
        return (0);
    } else if (*x > 0 && solver->map[*y][*x - 1] == '*') {
        *x -= 1;
        solver->map[*y][*x] = '1';
        return (0);
    }
    return (1);
}

int default_move(solve_t *solver, int *x, int *y)
{
    if (*x < solver->len - 1 && solver->map[*y][*x + 1] == '*') {
        *x += 1;
        solver->map[*y][*x] = '1';
        return (0);
    } else if (*y < solver->line - 1 && solver->map[*y + 1][*x] == '*') {
        *y += 1;
        solver->map[*y][*x] = '1';
        return (0);
    }
    return (defaut_move2(solver, x, y));
}

int step_back(solve_t *solver, int *x, int *y)
{
    pos_t *temp = solver->pos;

    solver->map[*y][*x] = '0';
    if (temp != NULL) {
        solver->pos = temp->next;
        free(temp);
        if (solver->pos) {
            *x = solver->pos->x;
            *y = solver->pos->y;
        }
    }
    if (!temp) {
        *x = 0;
        *y = 0;
    }
    return (0);
}