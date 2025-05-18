/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_main_struct
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

button_t *set_main_buttons(main_t *main)
{
    button_t *buttons = malloc(sizeof(button_t) * main->nb_buttons);

    buttons[0] = set_emplacement_struct((sfVector2f){128, 256});
    buttons[1] = set_emplacement_struct((sfVector2f){512, 128});
    buttons[2] = set_emplacement_struct((sfVector2f){770, 128});
    buttons[3] = set_emplacement_struct((sfVector2f){1208, 256});
    buttons[4] = set_emplacement_struct((sfVector2f){1664, 256});
    buttons[5] = set_emplacement_struct((sfVector2f){1536, 640});
    buttons[6] = set_emplacement_struct((sfVector2f){1250, 640});
    buttons[7] = set_emplacement_struct((sfVector2f){512, 512});;
    buttons[8] = set_emplacement_struct((sfVector2f){815, 512});
    buttons[9] = set_emplacement_struct((sfVector2f){730, 880});
    buttons[10] = set_emplacement_struct((sfVector2f){325, 880});
    buttons[11] = general_selection_setup("tier1", (sfVector2f){20, 510});
    buttons[12] = general_selection_setup("tier2", (sfVector2f){20, 635});
    buttons[13] = general_selection_setup("tier3", (sfVector2f){20, 750});
    buttons[14] = general_selection_setup("tier4", (sfVector2f){20, 880});
    return (buttons);
}

main_t *set_main_struct3(main_t *main)
{
    main->remind_i = 0;
    return (main);
}

main_t *set_main_struct2(main_t *main)
{
    tower_t *tow = malloc(sizeof(tower_t) * 11);

    main->nb_tow = 11;
    for (int i = 0; i < main->nb_tow; i++)
        tow[i] = set_tower_struct();
    main->towers = tow;
    main->remind_coo = (sfVector2f){0, 0};
    main->mobs = NULL;
    main->nb_mobs = 0;
    main->mobs_counter = 1;
    main->heart_pos = (sfVector2f){main->money_pos.x + 180,
    main->money_pos.y + 120};
    main->heart_sprite = sfSprite_create();
    main->heart_text = sfTexture_createFromFile("png/heart.png", sfFalse);
    main->lifes_text = sfText_create();
    main->lifes_str = malloc(sizeof(char) * 2);
    main->lifes = 3;
    main->should_reset = sfFalse;
    main->is_a_tow = sfFalse;
    return (set_main_struct3(main));
}

main_t *set_main_struct()
{
    main_t *main = malloc(sizeof(main_t));

    main->nb_buttons = 15;
    main->buttons = set_main_buttons(main);
    main->back_sprite = sfSprite_create();
    main->back_text = sfTexture_createFromFile("png/map.png", NULL);
    main->music = sfMusic_createFromFile("music_sounds/main_music.ogg");
    main->bank = 200;
    main->str_money = malloc(sizeof(char) * (my_nbr_len(main->bank)));
    main->money_pos = (sfVector2f){1620, 20};
    main->money_text = sfText_create();
    main->money_font = sfFont_createFromFile("font/bs_font.ttf");
    main->coin_sprite = sfSprite_create();
    main->coin_texture = sfTexture_createFromFile("png/coin.png", NULL);
    main->mob_spawn_clock = sfClock_create();
    main->more_mobs_clock = sfClock_create();
    main->show_market = sfFalse;
    main->market_sprite = sfSprite_create();
    main->market_text = sfTexture_createFromFile(market_path, sfFalse);
    return (set_main_struct2(main));
}
