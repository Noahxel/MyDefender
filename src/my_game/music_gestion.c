/*
** EPITECH PROJECT, 2022
** defender
** File description:
** music_gestion
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

void music_gestion(def_t *def)
{
    if (!def->global->is_muted) {
        sfMusic_pause(def->global->current_music);
        def->menus[1].buttons[2].text =
            sfTexture_createFromFile("png/mute.png", NULL);
        def->menus[1].buttons[2].tr_text =
            sfTexture_createFromFile("png/tr_mute.png", NULL);
    }
    if (def->global->is_muted) {
        sfMusic_play(def->global->current_music);
        def->menus[1].buttons[2].text =
            sfTexture_createFromFile("png/volume.png", NULL);
        def->menus[1].buttons[2].tr_text =
            sfTexture_createFromFile("png/tr_volume.png", NULL);
    }
}
