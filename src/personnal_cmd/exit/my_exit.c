/*
** EPITECH PROJECT, 2022
** Minishell1
** File description:
** my_exit.c
*/

#include "mysh.h"
#include "my.h"

int my_exit(mysh_t *data)
{
    my_printf("exit\n");
    data->error_msg = 1;
    data->recup = 84;
    data->exit_code = 0;
    return 22;
}
