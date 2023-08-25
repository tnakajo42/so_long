NAME		=	so_long
INCLUDE		=	-I./include -I $(LIBMLX)/include/MLX42

SRCS_DIR	=	./src/
OBJS_DIR	=	./obj/
LIB_DIR		=	./lib/
GETNL_DIR	=	./lib/get_next_line/
LIBFT_DIR	=	./lib/libft/
LIBMLX		=	./lib/MLX42/
LIBMUSIC	=	./lib/miniaudio/
GETNL_PATH	=	./lib/get_next_line/get_next_line.a
LIBFT_PATH	=	./lib/libft/libft.a
PRINTF_PATH	=	./lib/ft_printf/libftprintf.a
MLX_PATH	=	./lib/MLX42/build/libmlx42.a

LIB_PATH		= $(GETNL_PATH) $(LIBFT_PATH) $(PRINTF_PATH)

AR			=	ar rcs
RM			=	rm -f
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
MFLAGS		=	-L./lib/MLX42/build -lmlx42 -Iinclude -ldl -lglfw -pthread -lm

GIT_MLX		=	git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)
GIT_MUSIC	=	git clone https://github.com/mackron/miniaudio miniaudio

SRC_FILES	=	so_long \
				ft_error \
				utility \
				init_layer \
				init_game \
				init_map \
				init_image \
				place_texture \
				event \
				event_bonus \
				delete_image \
				delete_image_bonus \
				flood_fill

SRCS		= 	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS		=	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))

all:		$(NAME)

$(NAME):	$(OBJS)
			@make -C $(GETNL_DIR) 
			@make -C $(LIBFT_DIR) 
			@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4
			$(CC) -g $(CFLAGS) $(MFLAGS) $(OBJS) \
			$(LIB_PATH) $(MLX_PATH) -o $(NAME)
			@echo "\n ---  --       -     --  -  -  -- "
			@echo "-    -  -      -    -  - -- - -  -"
			@echo "-    -  -      -    -  - -- - -   "
			@echo " --  -  -      -    -  - ---- - --"
			@echo "   - -  -      -    -  - - -- -  -"
			@echo "   - -  -      -    -  - - -- -  -"
			@echo "---   --  ---- ----  --  -  -  -- \n"
			@echo "---- Type: % ./so_long ./map/a.ber"
			@echo "----  Try: % make switch_charactor"

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c ./include/so_long.h
			@mkdir -p $(@D)
			$(CC) -g $(INCLUDE) -c $< -o $@

clean:
			$(RM) -rf $(OBJS_DIR)
			$(RM) -rf $(LIBMLX)/build
			@make clean -C $(GETNL_DIR)
			@make clean -C $(LIBFT_DIR)

fclean:		clean
			$(RM) -f $(NAME)
			@$(RM) -f $(LIB_PATH)

re:			fclean all

download_mlx42:
			$(GIT_MLX)
			cd $(LIBMLX) && cmake -B build
			cd $(LIBMLX) && cmake --build build -j4 && clear
			@echo "Next you do is % make download_music"

download_music:
			cd $(LIB_DIR) && $(GIT_MUSIC) && clear
			@echo "Now you do is % make"

undownload_mlx42:
			rm -rf $(LIBMLX)

undownload_music:
			rm -rf $(LIBMUSIC)

switch_charactor:
			mv assets/charactor/enemy.png assets/charactor/template.png
			mv assets/charactor/player.png assets/charactor/enemy.png
			mv assets/charactor/enemy_strong.png assets/charactor/player.png
			mv assets/charactor/template.png assets/charactor/enemy_strong.png

			mv assets/charactor/enemy_flipped.png assets/charactor/template.png
			mv assets/charactor/player_flipped.png assets/charactor/enemy_flipped.png
			mv assets/charactor/enemy_strong_flipped.png assets/charactor/player_flipped.png
			mv assets/charactor/template.png assets/charactor/enemy_strong_flipped.png

			mv assets/collect/treasure.png assets/collect/template.png
			mv assets/collect/treasure_for_enemy.png assets/collect/treasure.png
			mv assets/collect/treasure_for_strong.png assets/collect/treasure_for_enemy.png
			mv assets/collect/template.png assets/collect/treasure_for_strong.png

			mv assets/walls/walls_1.png assets/walls/template.png
			mv assets/walls/walls_2.png assets/walls/walls_1.png
			mv assets/walls/walls_3.png assets/walls/walls_2.png
			mv assets/walls/walls_4.png assets/walls/walls_3.png
			mv assets/walls/template.png assets/walls/walls_4.png

			mv assets/floor/floor01_1.png assets/floor/template.png
			mv assets/floor/floor01_2.png assets/floor/floor01_1.png
			mv assets/floor/floor01_3.png assets/floor/floor01_2.png
			mv assets/floor/floor01_4.png assets/floor/floor01_3.png
			mv assets/floor/template.png assets/floor/floor01_4.png

			mv assets/floor/floor02_1.png assets/floor/template.png
			mv assets/floor/floor02_2.png assets/floor/floor02_1.png
			mv assets/floor/floor02_3.png assets/floor/floor02_2.png
			mv assets/floor/floor02_4.png assets/floor/floor02_3.png
			mv assets/floor/template.png assets/floor/floor02_4.png && clear
			@echo "Switched your charactor and enemies, and also changed the map textures"

_tester:
			git clone https://github.com/augustobecker/so_long_tester _tester
			cd _tester && make
			rm -rf _tester

.PHONY:		all clean fclean re
