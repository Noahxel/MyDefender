/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_menus_structs
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

menu_t set_game_menu_struct(void)
{
    menu_t game;
    button_t *buttons = malloc(sizeof(button_t) * 3);

    buttons[0] = set_this_button("play", (sfVector2f){200, 240});
    buttons[1] = set_this_button("quit", (sfVector2f){1220, 680});
    buttons[2] = set_this_button("settings", (sfVector2f){125, 800});
    game.buttons = buttons;
    game.name = "game";
    game.is_active = sfTrue;
    game.name_pos = (sfVector2f){1270, 5};
    game.name_resize = (sfVector2f){1, 1};
    game.name_rect = (sfIntRect){0, 0, 640, 330};
    game.name_sprite = sfSprite_create();
    game.menu_sprite = sfSprite_create();
    game.menu_text_path = game_menu_path;
    game.menu_text = sfTexture_createFromFile(game_menu_path, NULL);
    game.name_text = sfTexture_createFromFile(game_name_path, NULL);
    game.music = sfMusic_createFromFile("music_sounds/game_menu_music.ogg");
    game.nb_buttons = 3;
    return (game);
}

menu_t set_settings_menu_struct()
{
    menu_t settings;

    settings.nb_buttons = 3;
    settings.buttons = set_settings_buttons(settings);
    settings.name = "settings";
    settings.is_active = sfFalse;
    settings.name_pos = (sfVector2f){730, 150};
    settings.menu_pos = (sfVector2f){330, 5};
    settings.name_resize = (sfVector2f){1, 1};
    settings.name_rect = (sfIntRect){0, 0, 0, 0};
    settings.name_sprite = sfSprite_create();
    settings.menu_sprite = sfSprite_create();
    settings.menu_text = sfTexture_createFromFile(settings_menu_path, NULL);
    settings.name_text = sfTexture_createFromFile(settings_name_path, NULL);
    sfSprite_setPosition(settings.menu_sprite, settings.menu_pos);
    return (settings);
}

menu_t set_pause_menu_struct(void)
{
    menu_t pause;
    button_t *buttons = malloc(sizeof(button_t) * 3);

    buttons[0] = set_this_button("resume", (sfVector2f){1050, 700});
    buttons[1] = set_this_button("quit", (sfVector2f){550, 690});
    buttons[2] = set_this_button("restart", (sfVector2f){800, 500});
    pause.buttons = buttons;
    pause.name = "pause";
    pause.is_active = sfFalse;
    pause.name_pos = (sfVector2f){770, 150};
    pause.menu_pos = (sfVector2f){330, 5};
    pause.name_resize = (sfVector2f){1, 1};
    pause.name_rect = (sfIntRect){0, 0, 0, 0};
    pause.name_sprite = sfSprite_create();
    pause.menu_sprite = sfSprite_create();
    pause.menu_text = sfTexture_createFromFile(pause_menu_path, NULL);
    pause.name_text = sfTexture_createFromFile(pause_name_path, NULL);
    sfSprite_setPosition(pause.menu_sprite, pause.menu_pos);
    pause.nb_buttons = 3;
    return (pause);
}

menu_t set_endgame_menu_struct(void)
{
    menu_t endgame;
    button_t *buttons = malloc(sizeof(button_t) * 3);

    buttons[0] = set_this_button("scoreboard", (sfVector2f){1050, 700});
    buttons[1] = set_this_button("quit", (sfVector2f){550, 690});
    buttons[2] = set_this_button("play_again", (sfVector2f){800, 500});
    endgame.buttons = buttons;
    endgame.name = "endgame";
    endgame.is_active = sfFalse;
    endgame.name_pos = (sfVector2f){730, 150};
    endgame.menu_pos = (sfVector2f){330, 5};
    endgame.name_resize = (sfVector2f){1, 1};
    endgame.name_rect = (sfIntRect){0, 0, 0, 0};
    endgame.name_sprite = sfSprite_create();
    endgame.menu_sprite = sfSprite_create();
    endgame.menu_text = sfTexture_createFromFile(endgame_menu_path, NULL);
    endgame.name_text = sfTexture_createFromFile(endgame_name_path, NULL);
    sfSprite_setPosition(endgame.menu_sprite, endgame.menu_pos);
    endgame.nb_buttons = 3;
    return (endgame);
}

menu_t *set_menus_structs(def_t *def)
{
    menu_t *menus = malloc(sizeof(menu_t) * def->global->nb_menus);

    for (int i = 0; i < def->global->nb_menus; i++) {
        menus[i].back_sprite = NULL;
        menus[i].back_text = NULL;
        menus[i].music = NULL;
    }
    menus[0] = set_game_menu_struct();
    menus[1] = set_settings_menu_struct(def);
    menus[2] = set_pause_menu_struct();
    menus[3] = set_endgame_menu_struct();
    return (menus);
}
