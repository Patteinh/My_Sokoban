/*
** EPITECH PROJECT, 2022
** check_map
** File description:
** check_map
*/

#include "my_sokoban.h"

int check_win(sk_t *sk)
{
    int nb_x = 0;

    for (int i = 0; i < sk->nb.o; i++)
        sk->map[sk->p_o[i].y][sk->p_o[i].x] == 'X' ? nb_x += 1 : 0;
    return (nb_x);
}

int check_lose(sk_t *sk, int i, int j)
{
    int k = 0;

    sk->map[i - 1][j] == '#' && sk->map[i][j - 1] == '#' ? k = 1 : 0;
    sk->map[i][j - 1] == 'X' && sk->map[i + 1][j] == '#' ? k = 1 : 0;
    sk->map[i][j + 1] == 'X' && sk->map[i + 1][j] == '#' ? k = 1 : 0;
    sk->map[i][j - 1] == '#' && sk->map[i + 1][j] == 'X' ? k = 1 : 0;
    sk->map[i][j - 1] == '#' && sk->map[i - 1][j] == 'X' ? k = 1 : 0;
    sk->map[i - 1][j] == '#' && sk->map[i][j + 1] == 'X' ? k = 1 : 0;
    sk->map[i - 1][j] == '#' && sk->map[i][j - 1] == 'X' ? k = 1 : 0;
    sk->map[i][j + 1] == '#' && sk->map[i + 1][j] == 'X' ? k = 1 : 0;
    sk->map[i][j + 1] == '#' && sk->map[i - 1][j] == 'X' ? k = 1 : 0;
    sk->map[i - 1][j] == '#' && sk->map[i][j + 1] == '#' ? k = 1 : 0;
    sk->map[i + 1][j] == '#' && sk->map[i][j + 1] == '#' ? k = 1 : 0;
    sk->map[i + 1][j] == '#' && sk->map[i][j - 1] == '#' ? k = 1 : 0;

    return (k);
}

int check_char(char c)
{
    char *tmp = my_strdup("# \nXOP");

    for (int i = 0; tmp[i]; i++)
        if (c == tmp[i]) {
            free(tmp);
            return (SUCCESS);
        }
    free(tmp);
    return (ERROR);
}

void check_letter(sk_t *sk)
{
    for (int i = 0; sk->buffer[i]; i++) {
        sk->buffer[i] == 'P' ? sk->nb.p++ : 0;
        sk->buffer[i] == 'X' ? sk->nb.x++ : 0;
        sk->buffer[i] == 'O' ? sk->nb.o++ : 0;
        if (check_char(sk->buffer[i])) {
            free_all(sk);
            exit(ERROR);
        }
    }
}

void check_map(sk_t *sk)
{
    sk->nb.p != 1 ? exit(ERROR) : 0;
    sk->nb.x < sk->nb.o ? exit(ERROR) : 0;
    sk->p.x == 0 || sk->p.y == 0 ? exit(ERROR) : 0;
}
