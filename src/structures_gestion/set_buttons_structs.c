/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_buttons_structs
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

button_t button_redirection3(button_t button)
{
    if (my_strcmp(button.button_name, "back") == 0) {
        button.text = sfTexture_createFromFile("png/back.png", NULL);
        button.tr_text = sfTexture_createFromFile("png/tr_back.png", NULL);
    }
    if (my_strcmp(button.button_name, "volume") == 0) {
        button.text = sfTexture_createFromFile("png/volume.png", NULL);
        button.tr_text = sfTexture_createFromFile("png/tr_volume.png", NULL);
        button.rect = (sfIntRect){0, 0, 200, 155};
    }
    if (my_strcmp(button.button_name, "restart") == 0) {
        button.text = sfTexture_createFromFile("png/restart.png", NULL);
        button.tr_text = sfTexture_createFromFile("png/tr_restart.png", NULL);
    }
    return (button);
}

button_t button_redirection2(button_t button)
{
    if (my_strcmp(button.button_name, "scoreboard") == 0) {
        button.text = sfTexture_createFromFile("png/scoreboard.png", NULL);
        button.tr_text = sfTexture_createFromFile
            ("png/tr_scoreboard.png", NULL);
    }
    if (my_strcmp(button.button_name, "play_again") == 0) {
        button.text = sfTexture_createFromFile("png/play_again.png", NULL);
        button.tr_text = sfTexture_createFromFile
            ("png/tr_play_again.png", NULL);
    }
    if (my_strcmp(button.button_name, "settings") == 0) {
        button.text = sfTexture_createFromFile("png/settings.png", NULL);
        button.tr_text = sfTexture_createFromFile("png/tr_settings.png", NULL);
        button.rect = (sfIntRect){0, 0, 225, 155};
    }
    return (button_redirection3(button));
}

button_t button_redirection(button_t button)
{
    if (my_strcmp(button.button_name, "play") == 0) {
        button.text = sfTexture_createFromFile("png/play.png", NULL);
        button.tr_text = sfTexture_createFromFile("png/tr_play.png", NULL);
    }
    if (my_strcmp(button.button_name, "resume") == 0) {
        button.text = sfTexture_createFromFile("png/resume.png", NULL);
        button.tr_text = sfTexture_createFromFile("png/tr_resume.png", NULL);
    }
    if (my_strcmp(button.button_name, "quit") == 0) {
        button.text = sfTexture_createFromFile("png/quit.png", NULL);
        button.tr_text = sfTexture_createFromFile("png/tr_quit.png", NULL);
    }
    return (button_redirection2(button));
}

button_t general_buttons_setup(button_t button)
{
    button.sound = sfSound_create();
    button.sound_buffer = sfSoundBuffer_createFromFile(pressed_sound_path);
    sfSound_setBuffer(button.sound, button.sound_buffer);
    button.rect = (sfIntRect){0, 0, 350, 170};
    button = button_redirection(button);
    button.resize = (sfVector2f){1, 1};
    button.sprite = sfSprite_create();
    button.tr_sprite = sfSprite_create();
    button.actual_sprite = button.sprite;
    button.actual_text = button.text;
    set_button_text_pos(button);
    return (button);
}

button_t set_this_button(char *button_type, sfVector2f pos)
{
    button_t button;

    button.pos = pos;
    button.button_name = button_type;
    button = general_buttons_setup(button);
    return (button);
}
