/*
** EPITECH PROJECT, 2022
** defender
** File description:
** my_game_gestion
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

void my_game(def_t *def)
{
    sfMusic_pause(GLOBAL->current_music);
    GLOBAL->current_music = MAIN->music;
    if (GLOBAL->is_muted) {
        sfMusic_play(MAIN->music);
        sfMusic_setLoop(GLOBAL->current_music, sfTrue);
    }
    display_main(def);
    while (GLOBAL->is_in_game && sfRenderWindow_isOpen(GLOBAL->window)) {
        main_events_gestion(def);
        money_gestion(def);
        mob_gestion(def);
        tower_shot_gestion(def);
        lifes_gestion(def);
    }
    return;
}
