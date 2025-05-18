/*
** EPITECH PROJECT, 2022
** defender
** File description:
** my_reset
*/

#include "../../include/defender_include.h"

def_t *my_reset(def_t *def)
{
    sfMusic_destroy(MAIN->music);
    sfMusic_destroy(def->menus[0].music);
    free(def->main->buttons);
    free(def->main->mobs);
    free(def->main->towers);
    free(def->main);
    free(def->menus->buttons);
    free(def->menus);
    def = set_def_struct(def);
    def->global->is_in_game = sfFalse;
    if (GLOBAL->is_muted) {
        sfMusic_play(def->menus[0].music);
        sfMusic_setLoop(GLOBAL->current_music, sfTrue);
    }
    music_gestion(def);
    return (def);
}
