/*
** EPITECH PROJECT, 2022
** defender
** File description:
** main_buttons_event
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

int is_an_emplacement(def_t *def, sfVector2i coo)
{
    for (int i = 0; i < MAIN->nb_tow && GLOBAL->is_in_game; i++) {
        if (!TOW[i].is_existing && coo.x >= MAIN->buttons[i].pos.x &&
            coo.x <= MAIN->buttons[i].pos.x + MAIN->buttons[i].rect.width &&
            coo.y >= MAIN->buttons[i].pos.y &&
            coo.y <= MAIN->buttons[i].pos.y + MAIN->buttons[i].rect.height) {
            return (0);
        }
    }
    return (1);
}

int is_a_tower_here(def_t *def, sfVector2f pos)
{
    for (int i = 0; i < MAIN->nb_tow; i++) {
        if (TOW[i].is_existing &&
            (pos.x >= TOW[i].pos.x &&
            pos.x <= TOW[i].pos.x + 128 &&
            pos.y >= TOW[i].pos.y &&
            pos.y <= TOW[i].pos.y + 128))
            return (i);
    }
    return (-1);
}

void main_events(def_t *def, sfVector2i coo)
{
    if (MAIN->events.type == sfEvtClosed)
        sfRenderWindow_close(GLOBAL->window);
    if (!MAIN->show_market && sfKeyboard_isKeyPressed(sfKeyEscape))
        my_specific_menus(def, def->menus[1]);
    if ((MAIN->events.type == sfEvtMouseButtonPressed) &&
        (((coo.x > 190 || coo.y < 490) &&
        (is_an_emplacement(def, coo) == 1)) && MAIN->show_market))
        MAIN->show_market = sfFalse;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) && MAIN->show_market)
        MAIN->show_market = sfFalse;
    if (sfKeyboard_isKeyPressed(sfKeySpace))
        my_specific_menus(def, def->menus[2]);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        sell_tower_gestion(def);
}
