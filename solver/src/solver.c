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

pos_t *add_node(int *x, int *y, pos_t *list)
{
    pos_t *temp = malloc(sizeof(pos_t));

    if (!temp)
        return (list);
    temp->x = *x;
    temp->y = *y;
    temp->next = list;
    return (temp);
}

int backtracking(solve_t *solver)
{
    int x = 0;
    int y = 0;
    int state = 0;

    solver->map[0][0] = '1';
    while (y != solver->line - 1 || x != solver->len - 1) {
        state = default_move(solver, &x, &y);
        if (state == 1 && x == 0 && y == 0)
            return (1);
        if (state == 1)
            step_back(solver, &x, &y);
        else if (state == 0)
            solver->pos = add_node(&x, &y, solver->pos);
    }
    return (state);
}

int resolve_maze(solve_t *solver)
{
    if (backtracking(solver) == 1)
        write(1, "no solution found", 17);
    else
        print_map(solver);
}

int main(int ac, char **av)
{
    solve_t *solver = malloc(sizeof(solve_t));
    int state = 0;

    if (handle_input(ac, av, solver) == 84)
        return (84);
    state = resolve_maze(solver);
    return (state);
}