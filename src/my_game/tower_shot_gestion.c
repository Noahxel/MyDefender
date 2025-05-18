/*
** EPITECH PROJECT, 2022
** defender
** File description:
** tower_shot_gestion
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

int distance_beetween(sfVector2i pos1, sfVector2i pos2)
{
    int x = my_compute_power_rec((pos1.x - pos2.x), 2);
    int y = my_compute_power_rec((pos1.y - pos2.y), 2);

    return (x + y);
}

mob_t *nearest_mob(def_t *def, tower_t tower)
{
    mob_t *nearest = NULL;
    int distance = 0;
    int shortest_found = 1000000;

    for (int i = 0; i < MAIN->nb_mobs; i++) {
        distance = distance_beetween((sfVector2i){tower.pos.x, tower.pos.y},
        (sfVector2i){MAIN->mobs[i].pos.x, MAIN->mobs[i].pos.y});
        if (distance <= 102400 && distance < shortest_found) {
            shortest_found = distance;
            nearest = &MAIN->mobs[i];
        }
    }
    return (nearest);
}

void mob_HP_gestion(def_t *def, int i)
{
    if (TOW[i].mob_focused) {
        TOW[i].mob_focused->HP -= TOW[i].DPS;
        if (TOW[i].mob_focused->HP <= 0) {
            MAIN->bank += TOW[i].mob_focused->drops;
            add_mobs(def, 0);
        }
    }
}

void tower_shot_gestion(def_t *def)
{
    for (int i = 0; i < MAIN->nb_tow; i++) {
        if (!TOW->is_existing)
            continue;
        TOW[i].mob_focused = nearest_mob(def, TOW[i]);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(TOW[i].clock))
        >= 1000) {
            mob_HP_gestion(def, i);
            sfClock_restart(TOW[i].clock);
        }
    }
}
