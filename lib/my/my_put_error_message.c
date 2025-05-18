/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** my_put_error_message
*/

#include "my.h"
#include <unistd.h>

void my_put_error_message(char *str)
{
    for (int i = 0; i <= my_strlen(str); i++) {
        write(2, &str[i], 1);
    }
}
