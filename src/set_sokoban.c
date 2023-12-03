/*
** EPITECH PROJECT, 2022
** set_sokoban
** File description:
** set_sokoban
*/

#include "my_sokoban.h"

int open_file(char *filepath, sk_t *sk)
{
    FILE *fd = fopen(filepath, "r");
    ssize_t read;
    size_t size;
    char *line = NULL;
    char *tmp = NULL;

    if (fd == NULL)
        return (ERROR);
    while ((read = getline(&line, &size, fd)) != -1) {
        tmp = sk->buffer;
        if (!sk->buffer)
            sk->buffer = my_strdup(line);
        else
            sk->buffer = my_strcat(sk->buffer, line);
        if (tmp)
            free(tmp);
    }
    free(line);
    return (SUCCESS);
}

void remove_char(sk_t *sk, int i, int j)
{
    if (sk->save[i][j] == 'P' || sk->save[i][j] == 'X')
        sk->save[i][j] = ' ';
}

void fill_maps(sk_t *sk)
{
    sk->map = my_str_to_array(sk->buffer, "\n");
    sk->save = my_str_to_array(sk->buffer, "\n");

    for (int i = 0; sk->save[i]; i++)
        for (int j = 0; sk->save[i][j]; j++)
            remove_char(sk, i, j);
}

int set_sokoban(char **av, sk_t *sk)
{
    if (open_file(av[1], sk))
        return (ERROR);
    fill_maps(sk);
    count_rows_cols(sk);
    check_letter(sk);
    find_o_pos(sk);
    find_p_pos(sk);
    check_map(sk);
    return (start_sokoban(sk));
}
