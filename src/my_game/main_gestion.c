/*
** EPITECH PROJECT, 2022
** *
** File description:
** my_main_menu
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

void main_events_gestion(def_t *def)
{
    sfVector2i coo;

    display_main(def);
    while (sfRenderWindow_pollEvent(GLOBAL->window, &MAIN->events)) {
        coo = sfMouse_getPositionRenderWindow(GLOBAL->window);
        main_buttons_events(def, coo);
        main_events(def, coo);
    }
}
