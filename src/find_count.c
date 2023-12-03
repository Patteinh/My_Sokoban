/*
** EPITECH PROJECT, 2022
** find_count
** File description:
** find_count
*/

#include "my_sokoban.h"

void find_o_pos(sk_t *sk)
{
    sk->p_o = malloc(sizeof(pos_t) * (sk->nb.o));
    int k = 0;

    for (int i = 0; sk->map[i]; i++)
        for (int j = 0; sk->map[i][j]; j++)
            sk->map[i][j] == 'O' ? sk->p_o[k].x = j, sk->p_o[k].y = i, k++ : 0;
}

void find_p_pos(sk_t *sk)
{
    int x = 0;

    for (int y = 0; sk->map[y]; y++) {
        for (x = 0 ; sk->map[y][x] && sk->map[y][x] != 'P' ; x++);
        if (sk->map[y][x] == 'P') {
            sk->p.x = x;
            sk->save_p.x = x;
            sk->p.y = y;
            sk->save_p.y = y;
            break;
        }
    }
}

void count_rows_cols(sk_t *sk)
{
    sk->rows = my_lenarray(sk->map);
    sk->cols = my_strlen(sk->map[0]);

    for (int i = 0; sk->map[i]; i++)
        if (my_strlen(sk->map[i]) > sk->cols)
            sk->cols = my_strlen(sk->map[i]);
}
