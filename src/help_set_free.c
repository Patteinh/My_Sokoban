/*
** EPITECH PROJECT, 2022
** help_set_free
** File description:
** help_set_free
*/

#include "my_sokoban.h"

int help(sk_t *sk)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     "
    "map file representing the warehouse map, containing '#' for walls,\n    "
    "     'P' for the player, 'X' for boxes and 'O' for storage locations.\n");
    free(sk);
    return (SUCCESS);
}

void free_all(sk_t *sk)
{
    my_free_array(sk->map);
    my_free_array(sk->save);
    free(sk->p_o);
    free(sk->buffer);
    free(sk);
}

void set_struct(sk_t *sk)
{
    sk->buffer = NULL;
    sk->map = NULL;
    sk->nb.o = 0;
    sk->nb.p = 0;
    sk->nb.x = 0;
    sk->p.x = 0;
    sk->p.y = 0;
}
