/*
** EPITECH PROJECT, 2021
** my_compute_square_root
** File description:
** no description or consequences
*/

float my_compute_square_root(int nb)
{
    int root = 1;
    int i = 1;

    while (1) {
        root = ((nb / root) + root) / 2;
        if (i == nb / 3200)
            break;
        i++;
    }
    return (root);
}
