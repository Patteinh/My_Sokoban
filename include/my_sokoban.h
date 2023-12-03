/*
** EPITECH PROJECT, 2022
** my_sokoban.h
** File description:
** my_sokoban.h
*/

#include "my.h"
#include "ncurses.h"
#include "curses.h"

#ifndef _MY_SOKOBAN_
    #define _MY_SOKOBAN_
    #define SUCCESS 0
    #define ERROR 84
    #define FAIL 1
    #define UP 65
    #define DOWN 66
    #define RIGHT 67
    #define LEFT 68
    #define SPACE 32
    #define MAP sk->map[sk->p.y][sk->p.x]
    #define SAVE sk->save[sk->p.y][sk->p.x]
    #define MAP_U sk->map[sk->p.y - 1][sk->p.x]
    #define MAP_D sk->map[sk->p.y + 1][sk->p.x]
    #define MAP_R sk->map[sk->p.y][sk->p.x + 1]
    #define MAP_L sk->map[sk->p.y][sk->p.x - 1]


enum game_state {
    RESUME,
    WIN,
    LOSE,
};

typedef struct st_pos {
    int x;
    int y;
} pos_t;

typedef struct st_obj {
    int o;
    int p;
    int x;
} obj_t;

typedef struct st_sokoban {
    char **map;
    char **save;
    char *buffer;
    int key;
    pos_t *p_o;
    pos_t p;
    pos_t save_p;
    obj_t nb;
    int rows;
    int cols;
} sk_t;

int  check_start(char **av);
int  help(sk_t *sk);
int  set_sokoban(char **av, sk_t *sk);
void set_struct(sk_t *sk);
int  open_file(char *filepath, sk_t *sk);
void fill_maps(sk_t *sk);
void remove_char(sk_t *sk, int i, int j);
void count_rows_cols(sk_t *sk);
void check_letter(sk_t *sk);
int  check_char(char c);
void find_o_pos(sk_t *sk);
void find_p_pos(sk_t *sk);
void check_map(sk_t *sk);
int  start_sokoban(sk_t *sk);
void set_curse(void);
void print_check_window(sk_t *sk);
int  engine_sokoban(sk_t *sk);
void reset_map(sk_t *sk);
void moove_player(sk_t *sk);
void go_up(sk_t *sk);
void go_down(sk_t *sk);
void go_right(sk_t *sk);
void go_left(sk_t *sk);
int  check_win_lose(sk_t *sk);
int  check_win(sk_t *sk);
int  check_lose(sk_t *sk, int i, int j);
void free_all(sk_t *sk);

#endif
