/*
** EPITECH PROJECT, 2022
** defender
** File description:
** my_defender
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

void my_defender(def_t *def)
{
    set_text_pos(def);
    music_gestion(def);
    sfMusic_setLoop(GLOBAL->current_music, sfTrue);
    while (sfRenderWindow_isOpen(def->global->window)) {
        if (def->menus[0].is_active && !def->global->is_in_game)
            menu_gestion(def, def->menus[0]);
        if (def->global->is_in_game)
            my_game(def);
    }
}
