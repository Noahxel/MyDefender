/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_textures_pos
*/

#include "../../include/defender_include.h"

void set_text_pos2(def_t *def)
{
    sfText_setPosition(MAIN->lifes_text, (sfVector2f){MAIN->heart_pos.x - 80,
            MAIN->heart_pos.y});
    sfText_setFont(MAIN->lifes_text, MAIN->money_font);
    sfText_setCharacterSize(MAIN->lifes_text, 70);
    sfSprite_setTexture(MAIN->heart_sprite, MAIN->heart_text, sfFalse);
    sfSprite_setPosition(MAIN->heart_sprite, MAIN->heart_pos);
}

void set_text_pos(def_t *def)
{
    for (int i = 0; i < def->global->nb_menus; i++) {
        sfSprite_setTexture(def->menus[i].menu_sprite,
        def->menus[i].menu_text, sfFalse);
        sfSprite_setTexture(def->menus[i].name_sprite,
        def->menus[i].name_text, sfFalse);
        sfSprite_setPosition(def->menus[i].name_sprite,
        def->menus[i].name_pos);
    }
    sfSprite_setTexture(MAIN->back_sprite, MAIN->back_text, sfFalse);
    sfSprite_setTexture(MAIN->coin_sprite, MAIN->coin_texture, sfFalse);
    sfSprite_setPosition(MAIN->coin_sprite, (sfVector2f){1800, 10});
    sfSprite_setTexture(MAIN->market_sprite, MAIN->market_text, sfFalse);
    sfSprite_setPosition(MAIN->market_sprite, (sfVector2f){10, 450});
    sfText_setPosition(MAIN->money_text, MAIN->money_pos);
    sfText_setFont(MAIN->money_text, MAIN->money_font);
    sfText_setCharacterSize(MAIN->money_text, 70);
    set_text_pos2(def);
}

void set_button_text_pos(button_t button)
{
    sfSprite_setTexture(button.actual_sprite, button.actual_text, sfFalse);
    sfSprite_setPosition(button.actual_sprite, button.pos);
    sfSprite_setScale(button.actual_sprite, button.resize);
}
