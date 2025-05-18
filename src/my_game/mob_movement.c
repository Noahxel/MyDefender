/*
** EPITECH PROJECT, 2022
** defender
** File description:
** mob_movement
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

mob_t mob_movement5(mob_t mob)
{
    if (mob.move_stade == 8 && mob.pos.x >= (1100 - mob.move_gap)) {
        mob.pos.x -= mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.x <= (1100 - mob.move_gap) && mob.move_stade == 8) {
        sfSprite_setRotation(mob.sprite, -90);
        mob.move_stade = 9;
    }
    if (mob.move_stade == 9 && mob.pos.y >= (835 - mob.move_gap)) {
        mob.pos.y -= mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.y <= (835 - mob.move_gap) && mob.move_stade == 9) {
        sfSprite_setRotation(mob.sprite, 180);
        mob.move_stade = 10;
    }
    if (mob.move_stade == 10 && mob.pos.x >= -30) {
        mob.pos.x -= mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    }
    return (mob);
}

mob_t mob_movement4(mob_t mob)
{
    if (mob.move_stade == 6 && mob.pos.x <= (1705 + mob.move_gap)) {
        mob.pos.x += mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.x >= (1705 + mob.move_gap) && mob.move_stade == 6) {
        sfSprite_setRotation(mob.sprite, 90);
        mob.move_stade = 7;
    }
    if (mob.move_stade == 7 && mob.pos.y <= (820 + mob.move_gap)) {
        mob.pos.y += mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.y >= (820 + mob.move_gap) && mob.move_stade == 7) {
        sfSprite_setRotation(mob.sprite, 180);
        mob.move_stade = 8;
    }
    return (mob_movement5(mob));
}

mob_t mob_movement3(mob_t mob)
{
    if (mob.move_stade == 4 && mob.pos.x <= (1465 + mob.move_gap)) {
        mob.pos.x += mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.x >= (1465 + mob.move_gap) && mob.move_stade == 4) {
        sfSprite_setRotation(mob.sprite, 90);
        mob.move_stade = 5;
    }
    if (mob.move_stade == 5 && mob.pos.y <= (440 + mob.move_gap)) {
        mob.pos.y += mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.y >= (440 + mob.move_gap) && mob.move_stade == 5) {
        sfSprite_setRotation(mob.sprite, 0);
        mob.move_stade = 6;
    }
    return (mob_movement4(mob));
}

mob_t mob_movement2(mob_t mob)
{
    if (mob.move_stade == 2 && mob.pos.x <= (950 + mob.move_gap)) {
        mob.pos.x += mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.x >= (950 + mob.move_gap) && mob.move_stade == 2) {
        sfSprite_setRotation(mob.sprite, -90);
        mob.move_stade = 3;
    }
    if (mob.move_stade == 3 && mob.pos.y >= (190 - mob.move_gap)) {
        mob.pos.y -= mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.y <= (190 - mob.move_gap) && mob.move_stade == 3) {
        sfSprite_setRotation(mob.sprite, 0);
        mob.move_stade = 4;
    }
    return (mob_movement3(mob));
}

mob_t mob_movement(mob_t mob)
{
    if (mob.move_stade == 0 && mob.pos.x <= (315 + mob.move_gap)) {
        mob.pos.x += mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.x >= (315 + mob.move_gap) && mob.move_stade == 0) {
        sfSprite_setRotation(mob.sprite, 90);
        mob.move_stade = 1;
    }
    if (mob.move_stade == 1 && mob.pos.y <= (315 + mob.move_gap)) {
        mob.pos.y += mob.speed;
        sfSprite_setPosition(mob.sprite, mob.pos);
    } else if (mob.pos.y >= (315 + mob.move_gap) && mob.move_stade == 1) {
        sfSprite_setRotation(mob.sprite, 0);
        mob.move_stade = 2;
    }
    return (mob_movement2(mob));
}
