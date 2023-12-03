/*
** EPITECH PROJECT, 2022
** start_sokoban
** File description:
** start_sokoban
*/

#include "my_sokoban.h"

void set_curse(void)
{
    initscr();
    noecho();
    curs_set(0);
}

int start_sokoban(sk_t *sk)
{
    set_curse();
    while ((engine_sokoban(sk)) == RESUME);
    endwin();
    return (SUCCESS);
}
