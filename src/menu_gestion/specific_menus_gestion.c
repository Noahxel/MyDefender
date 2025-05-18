/*
** EPITECH PROJECT, 2022
** defender
** File description:
** my_settings
*/

#include "../../include/defender_include.h"

void my_specific_menus(def_t *def, menu_t menu)
{
    menu.is_active = sfTrue;
    if (my_strcmp(menu.name, "settings") == 0 && !GLOBAL->is_in_game)
        menu.back_text = sfTexture_createFromFile
            (GLOBAL->current_menu->menu_text_path, sfFalse);
    else
        menu.back_text = MAIN->back_text;
    menu.back_sprite = sfSprite_create();
    sfSprite_setTexture(menu.back_sprite,
                        menu.back_text, sfFalse);
    menu_gestion(def, menu);
}

button_t *set_settings_buttons(menu_t settings)
{
    button_t *buttons = malloc(sizeof(button_t) * settings.nb_buttons);

    buttons[0] = set_this_button("back", (sfVector2f){1050, 700});
    buttons[1] = set_this_button("quit", (sfVector2f){550, 690});
    buttons[2] = set_this_button("volume", (sfVector2f){600, 425});
    return (buttons);
}
