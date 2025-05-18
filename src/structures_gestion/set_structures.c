/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_structures
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

global_t *set_global_struct()
{
    global_t *global = malloc(sizeof(global_t));
    sfVideoMode videomode = {1920, 1080, 30};

    global->window = sfRenderWindow_create(videomode,
    "Brawl Defender", sfClose | sfResize, NULL);
    sfRenderWindow_setFramerateLimit(global->window, 400);
    global->is_in_game = sfFalse;
    global->nb_menus = 4;
    global->is_muted = sfTrue;
    return (global);
}

def_t *set_def_struct(def_t *def)
{
    def->menus = set_menus_structs(def);
    def->main = set_main_struct();
    def->global->current_menu = &def->menus[0];
    def->global->current_music = def->menus[0].music;
    set_text_pos(def);
    return (def);
}
