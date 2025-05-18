/*
** EPITECH PROJECT, 2021
** DevPack
** File description:
** project
*/

#include "defender_include.h"

#ifndef PROJECT_H_
    #define PROJECT_H_
    #define settings_menu_path "png/big_sign.png"
    #define settings_name_path "png/settings_text.png"
    #define game_menu_path "png/game_menu.png"
    #define game_name_path "png/game_menu_text.png"
    #define pause_menu_path "png/big_sign.png"
    #define pause_name_path "png/pause.png"
    #define endgame_menu_path "png/big_sign.png"
    #define endgame_name_path "png/you_lost.png"
    #define market_path "png/select_a_tower.png"
    #define pressed_sound_path "music_sounds/button_pressed.ogg"
    #define tower_sound_path "music_sounds/tower_setup.ogg"
    #define MAIN def->main
    #define GLOBAL def->global
    #define TOW def->main->towers

menu_t *set_menus_structs(def_t *def);

def_t *set_def_struct(def_t *def);

button_t set_this_button(char *button_type, sfVector2f pos);

void game_menu_gestion(def_t *def, menu_t menu);

void display_menu(def_t *def, menu_t menu);

void my_defender(def_t *def);

void set_text_pos(def_t *def);

void menu_gestion(def_t *def, menu_t menu);

def_t *my_reset(def_t *def);

void set_button_text_pos(button_t button);

void my_game(def_t *def);

button_t *set_settings_buttons(menu_t settings);

void music_gestion(def_t *def);

void main_gestion(def_t *def);

main_t *set_main_struct(void);

button_t set_emplacement_struct(sfVector2f pos);

void main_events_gestion(def_t *def);

void money_gestion(def_t *def);

void display_main(def_t *def);

void money_lifes_display(def_t *def);

menu_t set_tower_selection_menu_struct(def_t *def);

void mob_deplacement(def_t *def);

void display_it(def_t *def, menu_t menu);

button_t general_selection_setup(char *type, sfVector2f pos);

void main_buttons_events(def_t *def, sfVector2i coo);

void main_events(def_t *def, sfVector2i coo);

void set_this_tower(def_t *def, button_t button);

tower_t set_tower_struct(void);

int is_an_emplacement(def_t *def, sfVector2i coo);

int is_a_tower_here(def_t *def, sfVector2f pos);

mob_t *set_mob_struct(def_t *def);

void mob_gestion(def_t *def);

void add_mobs(def_t *def, int mobs_to_add);

void mob_display(def_t *def);

mob_t mob_movement(mob_t mob);

void tower_shot_gestion(def_t *def);

int distance_beetween(sfVector2i pos1, sfVector2i pos2);

void lifes_gestion(def_t *def);

void my_specific_menus(def_t *def, menu_t menu);

void free_all(def_t *def);

global_t *set_global_struct(void);

void sell_tower_gestion(def_t *def);

#endif
