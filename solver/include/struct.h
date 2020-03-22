/*
** EPITECH PROJECT, 2020
** maze structures
** File description:
** maze structures
*/

#ifndef SOLVE_STRUCT
#define SOLVE_STRUCT

typedef struct pos_s
{
    int x;
    int y;
    struct pos_s *next;
} pos_t;

typedef struct solve_s
{
    char **map;
    int len;
    int line;
    pos_t *pos;
} solve_t;

#endif /* !SOLVE_STRUCT */