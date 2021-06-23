##
## EPITECH PROJECT, 2019
## makefile my_hunter
## File description:
## my_hunter
##

SRC	=	src/create_char/create_char.c       \
		src/create_char/init_character.c    \
		src/create_char/init_parallax.c     \
		src/create_char/init_texts.c        \
		src/create_char/get_texts.c         \
		src/create_char/getters.c           \
		src/create_char/getters2.c          \
		src/create_char/init_skill_point.c  \
		src/create_char/divs.c              \
		src/create_char/init_buttons.c      \
		src/create_char/getters_button.c    \
		src/create_char/callback.c          \
		src/create_char/callback2.c         \
		src/create_char/manage_click.c      \
		src/create_char/draw_buttons.c      \
		src/create_char/init_scene.c        \
		src/create_char/parallax_setup.c    \
		src/create_char/draw_ping.c         \
		src/create_char/set_volume.c        \
		src/game/start_game.c           	\
		src/game/init_game_scene.c      	\
		src/game/destroy_all.c				\
		src/game/scena_back.c				\
		src/game/scena_deck.c				\
		src/game/click_on_item.c            \
		src/game/analyse_game_event.c  		\
		src/game/destroy_fst_file.c			\
		src/game/destroy_pnj_quest.c		\
		src/game/reinit_pos.c				\
		src/game/destroy_scd_file.c			\
		src/game/drawing_game.c         	\
		src/game/loop.c                     \
		src/game/display_pause.c            \
		src/game/buff_and_items.c           \
		src/game/regen_stats.c              \
		src/game/death_player.c             \
		src/game/create_map.c           	\
		src/game/road.c                 	\
		src/game/too_close_road.c       	\
		src/game/int_to_str.c				\
		src/game/create_obj.c           	\
		src/game/loading_bar.c				\
		src/game/move_player.c          	\
		src/game/display_pnj.c				\
		src/game/init_pnj_quest.c			\
		src/game/event_scenario.c			\
		src/game/init_pause.c				\
		src/game/change_sprite.c			\
		src/game/init_sound_music.c			\
		src/game/collision_enn.c            \
		src/game/create_boss.c              \
		src/game/set_stat_item.c            \
		src/game/get_texture_boss.c         \
		src/game/init_pnj.c					\
		src/game/check_mouse_click.c		\
		src/game/get_game_buttons.c         \
		src/game/draw_skill_tree.c          \
		src/game/get_skills_text.c          \
		src/game/get_texture.c              \
		src/game/set_stats.c                \
		src/game/init_bat.c					\
		src/game/get_next_line.c			\
		src/game/my_realloc.c				\
		src/game/cast_spell.c               \
		src/game/draw_spell.c               \
		src/game/set_volume_game.c          \
		src/game/set_pos_stats.c            \
		src/game/create_ennemies.c          \
		src/game/init_pause_scd_file.c		\
		src/game/event_menu_pause.c			\
		src/game/draw_bat.c					\
		src/game/draw_ennemies.c            \
		src/game/damage_dealing.c           \
		src/game/regen.c                    \
		src/game/load_tuto.c                \
		src/game/draw_text.c                \
		src/game/check_click_on_item.c      \
		src/game/put_item_on_map.c          \
		src/game/spawn.c                    \
		src/game/init_spawners.c            \
		src/game/set_stat_enn.c             \
		src/game/init_game_scene2.c         \
		src/game/draw_gutlets.c             \
		src/game/attacking.c                \
		src/game/drop_items.c               \
		src/game/draw_items.c               \
		src/game/trigger_enn.c              \
		src/game/move_enn.c                 \
		src/game/move_to_inventory.c        \
		src/game/get_texture_moab.c         \
		launcher/src/main.c					\
		launcher/src/launcher.c				\
		launcher/src/register_box.c			\
		launcher/src/login.c				\
		launcher/src/keyboard.c				\
		launcher/src/draw_launcher.c		\
		launcher/src/check_content.c		\
		launcher/src/check_str.c			\
		launcher/src/create_user.c			\
		launcher/lib/my_strcat.c			\
		launcher/lib/my_strlen.c			\
		launcher/lib/my_strncmp.c			\
		launcher/lib/my_putstr.c			\
		src/game/launcher_stats.c			\
		launcher/lib/my_atoi.c				\
		src/game/parsed_quest.c				\
		src/game/start.c					\
		launcher/src/window_create.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-I ./include/ -W -Wall -g

LDFLAGS	=	-l csfml-graphics -l csfml-window -l csfml-system -l csfml-audio -lm

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME) $(TESTS)

re:	fclean all

.PHONY:		all fclean clean re $(NAME)