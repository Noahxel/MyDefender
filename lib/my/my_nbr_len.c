/*
** EPITECH PROJECT, 2021
** my
** File description:
** my_nbr_len
*/

#include "my.h"

int my_nbr_len(int nbr)
{
    int nbrlen = 0;

    if (nbr == 0)
        return (1);
    for (; nbr >= 1; nbrlen++)
        nbr /= 10;
    return (nbrlen);
}
