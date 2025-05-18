/*
** EPITECH PROJECT, 2022
** defender
** File description:
** free_all
*/

#include "../../include/my.h"
#include "../../include/defender_struct.h"
#include "../../include/defender_fonction.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

void free_all(def_t *def)
{
    sfMusic_destroy(def->menus[0].music);
    sfMusic_destroy(MAIN->music);
    free(def->global);
    free(MAIN->lifes_str);
    free(MAIN->str_money);
    free(def->main->buttons);
    free(def->main->mobs);
    free(def->main->towers);
    free(def->main);
    free(def->menus->buttons);
    free(def->menus);
    free(def);
}
