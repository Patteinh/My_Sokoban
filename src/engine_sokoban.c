/*
** EPITECH PROJECT, 2022
** run_sokoban
** File description:
** run_sokoban
*/

#include "my_sokoban.h"

void print_check_window(sk_t *sk) {
    if (COLS < sk->cols || LINES < sk->rows) {
        while (COLS < sk->cols || LINES < sk->rows) {
            clear();
            mvprintw(LINES / 2, (COLS - 7) / 2, "RESIZE");
            refresh();
        }
        clear();
    } else {
        for (int i = 0; sk->map[i]; i++) {
            mvprintw(i, 0, "%s\n", sk->map[i]);
        }
    }
}

void moove_player(sk_t *sk)
{
    if (sk->key == UP && MAP_U != '#')
        go_up(sk);
    if (sk->key == DOWN && MAP_D != '#')
        go_down(sk);
    if (sk->key == RIGHT && MAP_R != '#')
        go_right(sk);
    if (sk->key == LEFT && MAP_L != '#')
        go_left(sk);
}

void reset_map(sk_t *sk)
{
    if (sk->key == SPACE) {
        my_free_array(sk->map);
        sk->map = my_str_to_array(sk->buffer, "\n");
        sk->p.x = sk->save_p.x;
        sk->p.y = sk->save_p.y;
    }
}

int check_win_lose(sk_t *sk)
{
    int stuck = 0;

    if (check_win(sk) == sk->nb.x)
        return (WIN);
    for (int i = 0; sk->map[i]; i++)
        for (int j = 0; sk->map[i][j]; j++)
            sk->map[i][j] == 'X' ? stuck += check_lose(sk, i, j) : 0;
    if (stuck == sk->nb.x)
        return (LOSE);
    return (RESUME);
}

int engine_sokoban(sk_t *sk)
{
    int check = 0;

    print_check_window(sk);
    sk->key = getch();
    reset_map(sk);
    moove_player(sk);
    print_check_window(sk);
    check = check_win_lose(sk);
    if (check == WIN) {
        print_check_window(sk);
        return (WIN);
    }
    if (check == LOSE) {
        print_check_window(sk);
        return (LOSE);
    }
    refresh();
    return (RESUME);
}
