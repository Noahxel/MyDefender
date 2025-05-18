/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_tower_struct
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

button_t set_emplacement_struct(sfVector2f pos)
{
    button_t emplacement;

    emplacement.button_name = "emplacement";
    emplacement.pos = pos;
    emplacement.rect = (sfIntRect){0, 0, 128, 128};
    emplacement.resize = (sfVector2f){1, 1};
    emplacement.sprite = sfSprite_create();
    emplacement.text = sfTexture_createFromFile
        ("png/tower_emplacement.png", NULL);
    emplacement.tr_sprite = sfSprite_create();
    emplacement.tr_text = sfTexture_createFromFile
        ("png/tr_tower_emplacement.png", NULL);
    emplacement.actual_sprite = sfSprite_create();
    emplacement.actual_text = sfTexture_createFromFile
        ("png/tower_emplacement.png", NULL);
    emplacement.sound = sfSound_create();
    emplacement.sound_buffer =
    sfSoundBuffer_createFromFile(pressed_sound_path);
    sfSound_setBuffer(emplacement.sound, emplacement.sound_buffer);
    return (emplacement);
}

tower_t set_tower_struct()
{
    tower_t tower;

    tower.clock = sfClock_create();
    tower.DPS = 0;
    tower.level = 1;
    tower.pos = (sfVector2f){0, 0};
    tower.price = 0;
    tower.resize = (sfVector2f){1, 1};
    tower.sprite = sfSprite_create();
    tower.text = NULL;
    tower.type = NULL;
    tower.is_existing = sfFalse;
    tower.range = 350;
    tower.range_circle = sfCircleShape_create();
    tower.mob_focused = NULL;
    return (tower);
}
