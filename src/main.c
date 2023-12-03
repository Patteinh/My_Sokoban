/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "my_sokoban.h"

int check_start(char **av)
{
    sk_t *sk = malloc(sizeof(sk_t));

    if (!my_strcmp(av[1], "-h"))
        return (help(sk));
    set_struct(sk);
    if (set_sokoban(av, sk))
        return (ERROR);
    free_all(sk);
    return (SUCCESS);
}

int main(int ac, char **av)
{
    if (ac == 2)
        return (check_start(av));
    return (ERROR);
}
