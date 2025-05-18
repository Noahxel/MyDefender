##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## compile main.c and u.t
##

SRCTEST		=		test/test_project.c

SRC		=		src/main.c	\
				src/structures_gestion/set_buttons_structs.c	\
				src/structures_gestion/set_menus_structs.c	\
				src/structures_gestion/set_structures.c	\
				src/my_defender.c	\
				src/display_gestion/display_menus.c	\
				src/display_gestion/set_textures_pos.c	\
				src/endgame_gestion/my_reset.c	\
				src/my_game/my_game_gestion.c	\
				src/menu_gestion/specific_menus_gestion.c	\
				src/menu_gestion/menus_gestion.c	\
				src/my_game/music_gestion.c	\
				src/structures_gestion/set_main_struct.c	\
				src/my_game/money_lifes_gestion.c	\
				src/structures_gestion/set_tower_struct.c	\
				src/my_game/main_gestion.c	\
				src/structures_gestion/set_menu_struct2.c	\
				src/my_game/mob_gestion.c	\
				src/my_game/main_buttons_event.c	\
				src/my_game/main_event.c	\
				src/my_game/tower_gestion.c	\
				src/structures_gestion/set_mob_struct.c	\
				src/display_gestion/display_main.c	\
				src/my_game/mob_movement.c	\
				src/my_game/tower_shot_gestion.c	\
				src/endgame_gestion/free_all.c	\
				src/my_game/sell_tower.c

TEST		=		unit_tests

NAME		=		my_defender

OBJ		=		$(SRC:.c=.o)

LDFLAGS		=		-Llib/my -lmy
CFLAGS		=		-Wall -Wextra -g3
TFLAGS		=		--coverage -lcriterion
GFLAG		=		-l csfml-graphics
WFLAG		=		-l csfml-window
SFLAG		=		-l csfml-system
AFLAGS		=		-l csfml-audio

all:	$(NAME)

$(NAME):		$(OBJ)
		make re -sC lib/my/
		gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LDFLAGS) $(GFLAG) $(AFLAGS) $(SFLAG) $(WFLAG)

tests_run:
		gcc $(CFLAGS) $(SRCTEST) $(SRC) -o $(TEST) $(LDFLAGS) $(TFLAGS)
		./unit_tests
clean:
		rm -f *.o
		rm -f src/*.o
		rm -f src/display_gestion/*.o
		rm -f src/endgame_gestion/*.o
		rm -f src/menu_gestion/*.o
		rm -f src/structures_gestion/*.o
		rm -f src/my_game/*.o
		rm -f $(NAME)
		make clean -sC lib/my/

fclean: clean
		make fclean -sC lib/my/
		rm -f *.gcno
		rm -f *.gcda
		rm -f $(TEST)

re: fclean all
