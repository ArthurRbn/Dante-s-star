/*
** EPITECH PROJECT, 2020
** init solver
** File description:
** init solver
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"
#include "../include/struct.h"

void print_map(solve_t *solve)
{
    for (int i = 0; solve->map[i]; ++i) {
        for (int j = 0; solve->map[i][j] != 0; ++j) {
            if (solve->map[i][j] == '1')
                write(1, "o", 1);
            else if (solve->map[i][j] == '0')
                write(1, "*", 1);
            else
                write(1, &solve->map[i][j], 1);
        }
        if (solve->map[i + 1])
            write(1, "\n", 1);
    }
}

int count_lines(char *file)
{
    int fd = open(file, O_RDONLY);
    int lines = 0;

    if (fd == -1)
        return (0);
    while (get_next_line(fd) != NULL) {
        ++lines;
    }
    close(fd);
    return (lines);
}

int handle_input2(solve_t *solve, int fd)
{
    solve->map = malloc(sizeof(char *) * (solve->line + 1));
    for (int i = 0; i < solve->line; ++i)
        solve->map[i] = get_next_line(fd);
    if (!solve->map[0])
        return (84);
    solve->map[solve->line] = NULL;
    for (solve->len = 0; solve->map[0][solve->len] != 0; ++solve->len);
    if (solve->len == 0 || solve->map[0][0] != '*' ||
    solve->map[solve->line - 1][solve->len - 1] != '*')
        return (84);
    solve->pos = NULL;
    close(fd);
    return (0);
}

int handle_input(int ac, char **av, solve_t *solve)
{
    int fd = 0;

    if (ac < 2)
        return (84);
    fd = open(av[1], O_RDONLY);
    if (fd == -1)
        return (84);
    solve->line = count_lines(av[1]);
    if (solve->line < 1) {
        close(fd);
        return (84);
    }
    return (handle_input2(solve, fd));
}