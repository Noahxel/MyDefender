/*
** EPITECH PROJECT, 2022
** defender
** File description:
** tower_gestion
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

void tower_orientation(def_t *def, int i)
{
    sfColor semi_red = sfColor_fromRGBA(255, 0, 0, 100);

    sfCircleShape_setRadius(TOW[i].range_circle, (float)TOW[i].range);
    sfCircleShape_setOrigin(TOW[i].range_circle, (sfVector2f)
    {TOW[i].range / 1.25, TOW[i].range / 1.25});
    sfCircleShape_setPosition(TOW[i].range_circle, (sfVector2f)
    {TOW[i].pos.x, TOW[i].pos.y});
    sfCircleShape_setOutlineThickness(TOW[i].range_circle, 1);
    sfCircleShape_setFillColor(TOW[i].range_circle, semi_red);
    if ((TOW[i].pos.x == 512 && TOW[i].pos.y == 128) ||
        (TOW[i].pos.x == 770 && TOW[i].pos.y == 128) ||
        (TOW[i].pos.x == 1250 && TOW[i].pos.y == 640))
        sfSprite_setRotation(TOW[i].sprite, 180);
    if (TOW[i].pos.x == 1664 && TOW[i].pos.y == 256)
        sfSprite_setRotation(TOW[i].sprite, -90);
    if (TOW[i].pos.x == 1536 && TOW[i].pos.y == 640)
        sfSprite_setRotation(TOW[i].sprite, 90);
}

void specific_tower_setup2(def_t *def, int i)
{
    if (my_strcmp(TOW[i].type, "tier3") == 0) {
        TOW[i].DPS = 300;
        TOW[i].text =
        sfTexture_createFromFile("png/tier3.png", sfFalse);
        TOW[i].price = 500;
    }
    if (my_strcmp(TOW[i].type, "tier4") == 0) {
        TOW[i].DPS = 500;
        TOW[i].text =
        sfTexture_createFromFile("png/tier4.png", sfFalse);
        TOW[i].price = 700;
    }
}

void specific_tower_setup(def_t *def, int i)
{
    if (my_strcmp(TOW[i].type, "tier1") == 0) {
        TOW[i].DPS = 100;
        TOW[i].text =
        sfTexture_createFromFile("png/tier1_loaded.png", sfFalse);
        TOW[i].price = 100;
    }
    if (my_strcmp(TOW[i].type, "tier2") == 0) {
        TOW[i].DPS = 250;
        TOW[i].text =
        sfTexture_createFromFile("png/tier2_loaded.png", sfFalse);
        TOW[i].price = 250;
    }
    specific_tower_setup2(def, i);
}

void set_this_tower(def_t *def, button_t button)
{
    int i = MAIN->remind_i;

    MAIN->is_a_tow = sfTrue;
    TOW[i].type = button.button_name;
    specific_tower_setup(def, i);
    TOW[i].is_existing = sfTrue;
    TOW[i].pos = button.pos;
    TOW[i].pos = MAIN->remind_coo;
    sfSprite_setTexture(TOW[i].sprite,
                        TOW[i].text, sfFalse);
    sfSprite_setOrigin(TOW[i].sprite, (sfVector2f){64, 64});
    sfSprite_setPosition(TOW[i].sprite, (sfVector2f)
                        {TOW[i].pos.x + 64,
                        TOW[i].pos.y + 64});
    tower_orientation(def, i);
    MAIN->show_market = sfFalse;
    MAIN->bank -= TOW[i].price;
}
