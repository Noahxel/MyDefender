/*
** EPITECH PROJECT, 2022
** defender
** File description:
** game_menu
*/

#include "../../include/defender_include.h"

menu_t buttons_gestion(def_t *def, button_t button, menu_t menu)
{
    if (my_strcmp(button.button_name, "play_again") == 0 ||
        my_strcmp(button.button_name, "restart") == 0) {
        menu.is_active = sfFalse;
        MAIN->should_reset = sfTrue;
        }
    if (my_strcmp(button.button_name, "settings") == 0)
        my_specific_menus(def, def->menus[1]);
    return (menu);
}

menu_t button_effect_gestion2(def_t *def, menu_t menu, button_t button)
{
    if (my_strcmp(button.button_name, "volume") == 0) {
        if (def->global->is_muted == sfTrue) {
            sfMusic_pause(def->global->current_music);
            def->menus[1].buttons[2].text =
            sfTexture_createFromFile("png/mute.png", NULL);
            def->menus[1].buttons[2].tr_text =
            sfTexture_createFromFile("png/tr_mute.png", NULL);
            def->global->is_muted = sfFalse;
        } else {
            sfMusic_play(def->global->current_music);
            def->menus[1].buttons[2].text =
            sfTexture_createFromFile("png/volume.png", NULL);
            def->menus[1].buttons[2].tr_text =
            sfTexture_createFromFile("png/tr_volume.png", NULL);
            def->global->is_muted = sfTrue;
        }
    }
    return (buttons_gestion(def, button, menu));
}

menu_t button_effect_gestion(def_t *def, menu_t menu, button_t button)
{
    if (menu.events.type == sfEvtMouseButtonPressed) {
        if (GLOBAL->is_muted)
            sfSound_play(button.sound);
        if (my_strcmp(button.button_name, "play") == 0 ||
            my_strcmp(button.button_name, "resume") == 0 ||
            my_strcmp(button.button_name, "back") == 0)
            menu.is_active = sfFalse;
        if (my_strcmp(button.button_name, "quit") == 0)
            sfRenderWindow_close(def->global->window);
        if (my_strcmp(button.button_name, "play") == 0)
            def->global->is_in_game = sfTrue;
        menu = button_effect_gestion2(def, menu, button);
    }
    return (menu);
}

menu_t menu_events(def_t *def, menu_t menu, sfVector2i coo)
{
    for (int i = 0; i < menu.nb_buttons && menu.is_active; i++) {
        if (coo.x >= menu.buttons[i].pos.x &&
            coo.x <= menu.buttons[i].pos.x + menu.buttons[i].rect.width &&
            coo.y >= menu.buttons[i].pos.y &&
            coo.y <= menu.buttons[i].pos.y + menu.buttons[i].rect.height) {
            coo = sfMouse_getPositionRenderWindow(def->global->window);
            menu.buttons[i].actual_sprite = menu.buttons[i].tr_sprite;
            menu.buttons[i].actual_text = menu.buttons[i].tr_text;
            display_menu(def, menu);
            menu = button_effect_gestion(def, menu, menu.buttons[i]);
        } else {
            menu.buttons[i].actual_sprite = menu.buttons[i].sprite;
            menu.buttons[i].actual_text = menu.buttons[i].text;
        }
    }
    if (menu.events.type == sfEvtClosed)
        sfRenderWindow_close(def->global->window);
    return (menu);
}

void menu_gestion(def_t *def, menu_t menu)
{
    sfVector2i coo;

    menu.is_active = sfTrue;
    while (menu.is_active && sfRenderWindow_isOpen(def->global->window)) {
        display_menu(def, menu);
        while (sfRenderWindow_pollEvent(def->global->window, &menu.events)) {
            coo = sfMouse_getPositionRenderWindow(def->global->window);
            menu = menu_events(def, menu, coo);
        }
    }
    if (MAIN->should_reset) {
        my_reset(def);
    }
}
