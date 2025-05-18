/*
** EPITECH PROJECT, 2022
** defender
** File description:
** sell_tower
*/

#include "../../include/defender_include.h"

void sell_tower_gestion(def_t *def)
{
    sfVector2i coo = sfMouse_getPositionRenderWindow(GLOBAL->window);
    int check = 0;

    for (int i = 0; i < MAIN->nb_tow; i++) {
        if (!TOW[i].is_existing)
            continue;
        check = is_a_tower_here(def, (sfVector2f){coo.x, coo.y});
        if (check >= 0) {
            MAIN->bank += TOW[i].price / 2;
            TOW[check] = set_tower_struct();
        }
        return;
    }
}
