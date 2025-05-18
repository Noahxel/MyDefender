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

void money_pos(int nbr_len, def_t *def)
{
    if (nbr_len % 1 == 0)
        MAIN->money_pos.x = 1740;
    if (nbr_len % 2 == 0)
        MAIN->money_pos.x = 1700;
    if (nbr_len % 3 == 0)
        MAIN->money_pos.x = 1660;
    if (nbr_len % 4 == 0)
        MAIN->money_pos.x = 1620;
    if (nbr_len % 5 == 0)
        MAIN->money_pos.x = 1580;
    if (nbr_len % 6 == 0)
        MAIN->money_pos.x = 1560;
    sfText_setPosition(MAIN->money_text, MAIN->money_pos);
}

void money_lifes_display(def_t *def)
{
    sfRenderWindow_drawText(GLOBAL->window, MAIN->money_text, NULL);
    sfRenderWindow_drawSprite(GLOBAL->window, MAIN->coin_sprite, NULL);
    sfRenderWindow_drawText(GLOBAL->window, MAIN->lifes_text, NULL);
    sfRenderWindow_drawSprite(GLOBAL->window, MAIN->heart_sprite, NULL);
}

void money_gestion(def_t *def)
{
    int copy_count = MAIN->bank;
    int nbr_len = my_nbr_len(copy_count);
    int i = 0;

    free(MAIN->str_money);
    MAIN->str_money = malloc(sizeof(char) * nbr_len);
    for (; i < nbr_len; i++) {
        MAIN->str_money[i] = ((copy_count % 10) + '0');
        copy_count /= 10;
    }
    MAIN->str_money[i] = '\0';
    MAIN->str_money = my_revstr(MAIN->str_money);
    money_pos(nbr_len, def);
    sfText_setString(MAIN->money_text, MAIN->str_money);
    money_lifes_display(def);
}

void lifes_gestion(def_t *def)
{
    MAIN->lifes_str[0] = (MAIN->lifes + '0');
    MAIN->lifes_str[1] = '\0';
    sfText_setString(MAIN->lifes_text, MAIN->lifes_str);
    if (MAIN->lifes <= 0) {
        my_specific_menus(def, def->menus[3]);
    }
}
