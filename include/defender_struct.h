/*
** EPITECH PROJECT, 2022
** defender
** File description:
** defender_struct
*/

#include <SFML/Graphics.h>
#include <SFML/Config.h>
#include <SFML/System/Export.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/System/Types.h>
#include <SFML/Audio.h>

#ifndef DEFENDER_STRUCT_H_
    #define DEFENDER_STRUCT_H_

typedef struct mob_s {
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f resize;
    sfIntRect rect;
    char *type;
    int speed;
    int HP;
    int drops;
    int move_gap;
    int move_stade;
} mob_t;

typedef struct tower_s {
    sfTexture *text;
    sfSprite *sprite;
    sfClock *clock;
    sfVector2f pos;
    sfVector2f resize;
    sfBool is_existing;
    sfCircleShape *range_circle;
    mob_t *mob_focused;
    char *type;
    int level;
    int price;
    int DPS;
    int range;
} tower_t;

typedef struct button_s {
    char *button_name;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
    sfTexture *text;
    sfSprite *sprite;
    sfTexture *tr_text;
    sfSprite *tr_sprite;
    sfVector2f pos;
    sfVector2f resize;
    sfSprite *actual_sprite;
    sfTexture *actual_text;
    sfIntRect rect;
} button_t;

typedef struct menu_s {
    int nb_buttons;
    char *name;
    char *name_text_path;
    char *menu_text_path;
    sfTexture *name_text;
    sfTexture *back_text;
    sfTexture *menu_text;
    sfSprite *back_sprite;
    sfSprite *name_sprite;
    sfSprite *menu_sprite;
    sfVector2f name_pos;
    sfVector2f menu_pos;
    sfVector2f name_resize;
    sfIntRect name_rect;
    sfBool is_active;
    button_t *buttons;
    sfEvent events;
    sfMusic *music;
} menu_t;

typedef struct main_s {
    int nb_buttons;
    int bank;
    char *str_money;
    char *lifes_str;
    int nb_tow;
    int nb_mobs;
    int mobs_counter;
    int lifes;
    int remind_i;
    sfBool is_a_tow;
    sfSprite *heart_sprite;
    sfTexture *heart_text;
    sfVector2f heart_pos;
    sfText *lifes_text;
    button_t *buttons;
    tower_t *towers;
    mob_t *mobs;
    sfFont *money_font;
    sfVector2f money_pos;
    sfText *money_text;
    sfSprite *coin_sprite;
    sfTexture *coin_texture;
    sfTexture *back_text;
    sfSprite *back_sprite;
    sfEvent events;
    sfMusic *music;
    sfClock *mob_spawn_clock;
    sfClock *more_mobs_clock;
    sfBool show_market;
    sfSprite *market_sprite;
    sfTexture *market_text;
    sfVector2f remind_coo;
    sfBool should_reset;
} main_t;

typedef struct global_s {
    int nb_menus;
    sfEvent global_events;
    sfRenderWindow *window;
    sfBool is_in_game;
    sfMusic *current_music;
    menu_t *current_menu;
    sfBool is_muted;
} global_t;

typedef struct def_s {
    global_t *global;
    menu_t *menus;
    main_t *main;
} def_t;

#endif
