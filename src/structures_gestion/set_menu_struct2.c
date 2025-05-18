/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_menu_struct2
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

button_t set_tower_selection_button2(button_t button)
{
    if (my_strcmp(button.button_name, "tier3") == 0) {
        button.text = sfTexture_createFromFile("png/tier3_btn.png", NULL);
        button.tr_text =
            sfTexture_createFromFile("png/tr_tier3_btn.png", NULL);
    }
    if (my_strcmp(button.button_name, "tier4") == 0) {
        button.text = sfTexture_createFromFile("png/tier4_btn.png", NULL);
        button.tr_text =
            sfTexture_createFromFile("png/tr_tier4_btn.png", NULL);
    }
    return (button);
}

button_t set_tower_selection_button(button_t button)
{
    if (my_strcmp(button.button_name, "tier1") == 0) {
        button.text = sfTexture_createFromFile("png/tier1_btn.png", NULL);
        button.tr_text =
            sfTexture_createFromFile("png/tr_tier1_btn.png", NULL);
        button.rect = (sfIntRect){0, 0, 128, 120};
    }
    if (my_strcmp(button.button_name, "tier2") == 0) {
        button.text = sfTexture_createFromFile("png/tier2_btn.png", NULL);
        button.tr_text =
            sfTexture_createFromFile("png/tr_tier2_btn.png", NULL);
        button.rect = (sfIntRect){0, 0, 128, 100};
    }
    return (set_tower_selection_button2(button));
}

button_t general_selection_setup(char *type, sfVector2f pos)
{
    button_t button;

    button.button_name = type;
    button.rect = (sfIntRect){0, 0, 128, 128};
    button.pos = pos;
    button.resize = (sfVector2f){0.80, 0.80};
    button.sprite = sfSprite_create();
    button.tr_sprite = sfSprite_create();
    button = set_tower_selection_button(button);
    button.actual_sprite = button.sprite;
    button.actual_text = button.text;
    button.sound = sfSound_create();
    button.sound_buffer = sfSoundBuffer_createFromFile(tower_sound_path);
    sfSound_setBuffer(button.sound, button.sound_buffer);
    set_button_text_pos(button);
    return (button);
}
