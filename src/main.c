/*
** EPITECH PROJECT, 2021
** DevPack
** File description:
** main
*/

#include "../include/my.h"
#include "../include/defender_struct.h"
#include "../include/defender_fonction.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int handle_errors(int argc, char **argv)
{
    if (my_strcmp("-h", argv[argc - 1]) == 0) {
        my_putstr(extract_str("src/h_gestion.txt"));
        my_putchar('\n');
        return (1);
    }
    return (0);
}

int main(int argc, char **argv)
{
    int check = handle_errors(argc, argv);
    def_t *def = malloc(sizeof(def_t));

    if (check == 84)
        return (84);
    if (check == 1)
        return (0);
    def->global = set_global_struct();
    def = set_def_struct(def);
    my_defender(def);
    free_all(def);
    return (0);
}
