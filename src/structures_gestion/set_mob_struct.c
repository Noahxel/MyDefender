/*
** EPITECH PROJECT, 2022
** defender
** File description:
** set_mob_struct
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

char *random_mobs_type()
{
    char *mob_type = "none";
    int random_mob = 0;

    random_mob = rand() % 11;
    if (random_mob == 10)
        mob_type = "tier4";
    if (random_mob >= 8 && my_strcmp(mob_type, "none") == 0)
        mob_type = "tier3";
    if (random_mob > 4 && my_strcmp(mob_type, "none") == 0)
        mob_type = "tier2";
    if (random_mob >= 0 && my_strcmp(mob_type, "none") == 0)
        mob_type = "tier1";
    return (mob_type);
}

mob_t set_specific_mob2(mob_t actual_mob)
{
    if (my_strcmp(actual_mob.type, "tier3") == 0) {
        actual_mob.drops = 40;
        actual_mob.HP = 1300;
        actual_mob.speed = 1.8;
        actual_mob.text =
            sfTexture_createFromFile("png/mob_tier3.png", sfFalse);
    }
    if (my_strcmp(actual_mob.type, "tier4") == 0) {
        actual_mob.drops = 60;
        actual_mob.HP = 1700;
        actual_mob.speed = 1.5;
        actual_mob.text =
            sfTexture_createFromFile("png/mob_tier4.png", sfFalse);
    }
    sfSprite_setTextureRect(actual_mob.sprite, actual_mob.rect);
    sfSprite_setTexture(actual_mob.sprite, actual_mob.text, sfFalse);
    sfSprite_setOrigin(actual_mob.sprite, (sfVector2f){64, 64});
    sfSprite_setPosition(actual_mob.sprite, actual_mob.pos);
    return (actual_mob);
}

mob_t set_specific_mob(mob_t actual_mob)
{
    if (my_strcmp(actual_mob.type, "tier1") == 0) {
        actual_mob.drops = 25;
        actual_mob.HP = 400;
        actual_mob.speed = 2.5;
        actual_mob.text =
            sfTexture_createFromFile("png/mob_tier1.png", sfFalse);
    }
    if (my_strcmp(actual_mob.type, "tier2") == 0) {
        actual_mob.drops = 30;
        actual_mob.HP = 650;
        actual_mob.speed = 2.2;
        actual_mob.text =
            sfTexture_createFromFile("png/mob_tier2.png", sfFalse);
    }
    return (set_specific_mob2(actual_mob));
}

void set_mobs_struct(def_t *def, int mobs_to_add, mob_t *new_mobs)
{
    int mobs_count = MAIN->nb_mobs + mobs_to_add;
    srand(time(NULL));

    for (; MAIN->nb_mobs < mobs_count; MAIN->nb_mobs++) {
        new_mobs[MAIN->nb_mobs].move_gap = rand() % 130;
        new_mobs[MAIN->nb_mobs].move_stade = 0;
        new_mobs[MAIN->nb_mobs].type = random_mobs_type(def);
        new_mobs[MAIN->nb_mobs].clock = sfClock_create();
        new_mobs[MAIN->nb_mobs].sprite = sfSprite_create();
        new_mobs[MAIN->nb_mobs].pos = (sfVector2f)
            {-80 + 64, ((20 + (rand() % 100)) + 64)};
        new_mobs[MAIN->nb_mobs].resize = (sfVector2f){1, 1};
        new_mobs[MAIN->nb_mobs].rect = (sfIntRect){0, 0, 128, 128};
        new_mobs[MAIN->nb_mobs] =
            set_specific_mob(new_mobs[MAIN->nb_mobs]);
        }
    free(MAIN->mobs);
    MAIN->mobs = new_mobs;
}

void add_mobs(def_t *def, int mobs_to_add)
{
    mob_t *new_mobs = NULL;
    int tmp_copy = MAIN->nb_mobs;
    int j = 0;

    for (int i = 0; i < MAIN->nb_mobs && MAIN->nb_mobs > 0; i++) {
        if (MAIN->mobs[i].pos.x < 0 && MAIN->mobs[i].pos.y > 500) {
            MAIN->mobs[i].HP = -5;
            MAIN->lifes--;
        }
        if (MAIN->mobs[i].HP <= 0)
            MAIN->nb_mobs--;
    }
    new_mobs = malloc(sizeof(mob_t) * (MAIN->nb_mobs + mobs_to_add));
    for (int i = 0; i < tmp_copy && MAIN->nb_mobs > 0; i++) {
        if (MAIN->mobs[i].HP <= 0)
            continue;
        new_mobs[j] = MAIN->mobs[i];
        j++;
    }
    set_mobs_struct(def, mobs_to_add, new_mobs);
}
