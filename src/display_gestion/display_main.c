/*
** EPITECH PROJECT, 2022
** defender
** File description:
** display_main
*/

#include "../../include/defender_include.h"

void tower_emplacement_display(def_t *def)
{
    int tower_check = 0;

    for (int i = 0; i < 11; i++) {
        tower_check = is_a_tower_here(def, MAIN->buttons[i].pos);
        if (tower_check >= 0) {
            sfRenderWindow_drawSprite(GLOBAL->window,
            TOW[tower_check].sprite, NULL);
            continue;
        }
        set_button_text_pos(MAIN->buttons[i]);
        sfRenderWindow_drawSprite(GLOBAL->window,
        MAIN->buttons[i].actual_sprite, NULL);
    }
}

void display_main2(def_t *def)
{
    sfVector2i coo = sfMouse_getPositionRenderWindow(GLOBAL->window);
    int tow_check = 0;

    if (MAIN->nb_mobs > 0)
        for (int i = 0; i < MAIN->nb_mobs; i++) {
            sfRenderWindow_drawSprite(GLOBAL->window,
            MAIN->mobs[i].sprite, sfFalse);
        }
    tow_check = is_a_tower_here(def, (sfVector2f){coo.x, coo.y});
    if (tow_check >= 0) {
        sfRenderWindow_drawCircleShape(GLOBAL->window,
        TOW[tow_check].range_circle, NULL);
    }
}

void display_main(def_t *def)
{
    sfRenderWindow_clear(GLOBAL->window, sfBlack);
    sfRenderWindow_drawSprite(GLOBAL->window, MAIN->back_sprite, NULL);
    tower_emplacement_display(def);
    if (MAIN->show_market) {
        sfRenderWindow_drawSprite(GLOBAL->window,
        MAIN->market_sprite, sfFalse);
        sfRenderWindow_drawSprite(GLOBAL->window,
        MAIN->buttons[11].actual_sprite, NULL);
        sfRenderWindow_drawSprite(GLOBAL->window,
        MAIN->buttons[12].actual_sprite, NULL);
        sfRenderWindow_drawSprite(GLOBAL->window,
        MAIN->buttons[13].actual_sprite, NULL);
        sfRenderWindow_drawSprite(GLOBAL->window,
        MAIN->buttons[14].actual_sprite, NULL);
    }
    money_lifes_display(def);
    display_main2(def);
    sfRenderWindow_display(GLOBAL->window);
}
