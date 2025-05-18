/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_menus
*/

#include "../../include/defender_include.h"

void display_menu(def_t *def, menu_t menu)
{
    sfRenderWindow_clear(def->global->window, sfBlack);
    if (my_strcmp(menu.name, "settings") == 0 ||
        my_strcmp(menu.name, "pause") == 0 ||
        my_strcmp(menu.name, "endgame") == 0)
        sfRenderWindow_drawSprite(def->global->window, menu.back_sprite, NULL);
    sfRenderWindow_drawSprite(def->global->window, menu.menu_sprite, NULL);
    sfRenderWindow_drawSprite(def->global->window, menu.name_sprite, NULL);
    for (int i = 0; i < menu.nb_buttons; i++) {
        set_button_text_pos(menu.buttons[i]);
        sfRenderWindow_drawSprite(def->global->window,
        menu.buttons[i].actual_sprite, NULL);
    }
    sfRenderWindow_display(def->global->window);
}
