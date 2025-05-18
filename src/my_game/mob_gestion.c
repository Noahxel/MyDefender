/*
** EPITECH PROJECT, 2022
** defender
** File description:
** mob_deplacement
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

mob_t mob_rect_gestion(mob_t mob)
{
    if (mob.rect.left >= 896)
        mob.rect.left = 0;
    else
        mob.rect.left += 128;
    sfSprite_setTextureRect(mob.sprite, mob.rect);
    return (mob);
}

void mob_deplacement(def_t *def)
{
    for (int i = 0; i < MAIN->nb_mobs; i++) {
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(MAIN->mobs[i].clock))
            % 10 == 0)
            MAIN->mobs[i] = mob_movement(MAIN->mobs[i]);
        if (sfTime_asMilliseconds(sfClock_getElapsedTime(MAIN->mobs[i].clock))
            % 100 == 0)
            MAIN->mobs[i] = mob_rect_gestion(MAIN->mobs[i]);
    }
}

void mob_gestion(def_t *def)
{
    if ((sfTime_asMilliseconds(sfClock_getElapsedTime(MAIN->mob_spawn_clock))
        >= 5000) && (MAIN->is_a_tow)) {
        add_mobs(def, MAIN->mobs_counter);
        sfClock_restart(MAIN->mob_spawn_clock);
    }
    if ((sfTime_asMilliseconds(sfClock_getElapsedTime(MAIN->more_mobs_clock))
        >= 25000) && (MAIN->is_a_tow)) {
        MAIN->mobs_counter++;
        sfClock_restart(MAIN->more_mobs_clock);
    }
    if (MAIN->nb_mobs > 0)
        mob_deplacement(def);
}
