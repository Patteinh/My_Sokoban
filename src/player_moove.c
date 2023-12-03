/*
** EPITECH PROJECT, 2022
** moove
** File description:
** moove
*/

#include "my_sokoban.h"

void go_up(sk_t *sk)
{
    MAP_U == 'O' || MAP_U == ' ' ? MAP = SAVE, sk->p.y -= 1, MAP = 'P' : 0;
    if ((MAP_U == 'X' && sk->map[sk->p.y - 2][sk->p.x] == 'O') ||
    (MAP_U == 'X' && sk->map[sk->p.y - 2][sk->p.x] == ' ')) {
        MAP = SAVE;
        sk->p.y -= 1;
        MAP = 'P';
        MAP_U = 'X';
    }
}

void go_down(sk_t *sk)
{
    MAP_D == 'O' || MAP_D == ' ' ? MAP = SAVE, sk->p.y += 1, MAP = 'P' : 0;
    if ((MAP_D == 'X' && sk->map[sk->p.y + 2][sk->p.x] == 'O') ||
    (MAP_D == 'X' && sk->map[sk->p.y + 2][sk->p.x] == ' ')) {
        MAP = SAVE;
        sk->p.y += 1;
        MAP = 'P';
        MAP_D = 'X';
    }
}

void go_right(sk_t *sk)
{
    MAP_R == 'O' || MAP_R == ' ' ? MAP = SAVE, sk->p.x += 1, MAP = 'P' : 0;
    if ((MAP_R == 'X' && sk->map[sk->p.y][sk->p.x + 2] == 'O') ||
    (MAP_R == 'X' && sk->map[sk->p.y][sk->p.x + 2] == ' ')) {
        MAP = SAVE;
        sk->p.x += 1;
        MAP = 'P';
        MAP_R = 'X';
    }
}

void go_left(sk_t *sk)
{
    MAP_L == 'O' || MAP_L == ' ' ? MAP = SAVE, sk->p.x -= 1, MAP = 'P' : 0;
    if ((MAP_L == 'X' && sk->map[sk->p.y][sk->p.x - 2] == 'O') ||
    (MAP_L == 'X' && sk->map[sk->p.y][sk->p.x - 2] == ' ')) {
        MAP = SAVE;
        sk->p.x -= 1;
        MAP = 'P';
        MAP_L = 'X';
    }
}
