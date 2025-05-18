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

void launch_sound(def_t *def, button_t button)
{
    if (GLOBAL->is_muted)
        sfSound_play(button.sound);
}

void main_button_redirection(def_t *def, button_t button)
{
    if (MAIN->events.type == sfEvtMouseButtonPressed) {
        if (((my_strcmp(button.button_name, "tier1") == 0 &&
            def->main->bank >= 100) ||
            (my_strcmp(button.button_name, "tier2") == 0 &&
            def->main->bank >= 250) ||
            (my_strcmp(button.button_name, "tier3") == 0 &&
            def->main->bank >= 500) ||
            (my_strcmp(button.button_name, "tier4") == 0 &&
            def->main->bank >= 700)) && MAIN->show_market) {
            set_this_tower(def, button);
            launch_sound(def, button);
            }
    }
}

void main_button_effect_gestion(def_t *def, button_t button, int i)
{
    if (MAIN->events.type == sfEvtMouseButtonPressed) {
        if (my_strcmp(button.button_name, "emplacement") == 0 &&
            is_an_emplacement(def, (sfVector2i)
            {button.pos.x, button.pos.y}) == 0) {
            MAIN->show_market = sfTrue;
            MAIN->remind_coo = button.pos;
            MAIN->remind_i = i;
            launch_sound(def, button);
        }
    }
}

void main_buttons_events(def_t *def, sfVector2i coo)
{
    for (int i = 0; i < MAIN->nb_buttons && GLOBAL->is_in_game; i++) {
        if (coo.x >= MAIN->buttons[i].pos.x &&
            coo.x <= MAIN->buttons[i].pos.x + MAIN->buttons[i].rect.width &&
            coo.y >= MAIN->buttons[i].pos.y &&
            coo.y <= MAIN->buttons[i].pos.y + MAIN->buttons[i].rect.height) {
            coo = sfMouse_getPositionRenderWindow(GLOBAL->window);
            MAIN->buttons[i].actual_sprite = MAIN->buttons[i].tr_sprite;
            MAIN->buttons[i].actual_text = MAIN->buttons[i].tr_text;
            set_button_text_pos(MAIN->buttons[i]);
            display_main(def);
            main_button_effect_gestion(def, MAIN->buttons[i], i);
            main_button_redirection(def, MAIN->buttons[i]);
        } else {
            MAIN->buttons[i].actual_sprite = MAIN->buttons[i].sprite;
            MAIN->buttons[i].actual_text = MAIN->buttons[i].text;
        }
    }
}
