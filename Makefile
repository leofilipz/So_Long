CC = cc -g
CFLAGS = -Wall -Werror -Wextra 
NAME = so_long
BONUS = so_long_bonus

SRCS = ./utils/ft_strlen.c ./utils/ft_strtrim.c ./utils/ft_itoa.c \
	./utils/get_next_line.c ./utils/get_next_line_utils.c ./utils/ft_putstr_fd.c\
	./map_treatment/get_y.c ./map_treatment/free.c ./map_treatment/map_create.c ./map_treatment/map_fd.c ./main.c ./map_treatment/elements.c ./map_treatment/validation.c ./map_treatment/error.c ./map_treatment/check_path.c\
	./rendering/check_pos.c ./rendering/render_img.c ./rendering/move_player.c ./rendering/destroy.c ./rendering/function_divider.c

SRCS_BONUS =./bonus/utils/ft_strlen.c ./bonus/utils/ft_strtrim.c \
	./bonus/utils/get_next_line.c ./bonus/utils/get_next_line_utils.c ./bonus/utils/ft_putstr_fd.c ./bonus/utils/ft_itoa.c\
	./bonus/map_treatment/get_y.c ./bonus/map_treatment/free.c ./bonus/map_treatment/map_create.c ./bonus/map_treatment/map_fd.c ./bonus/main.c ./bonus/map_treatment/elements.c ./bonus/map_treatment/validation.c ./bonus/map_treatment/error.c  ./bonus/map_treatment/divide1.c ./bonus/map_treatment/check_path.c\
	./bonus/rendering/check_pos.c ./bonus/rendering/render_img.c ./bonus/rendering/move_player.c ./bonus/rendering/destroy.c ./bonus/rendering/collect_animations.c ./bonus/rendering/remove_from_array.c ./bonus/rendering/move_enemy.c ./bonus/rendering/duplicate_render_destroy.c ./bonus/rendering/duplicate_check_pos.c ./bonus/rendering/duplicate_collect_animation.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
OBJS = $(SRCS:.c=.o)
all: $(NAME)


${NAME}: ${OBJS}	
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS) -L./minilibx-linux -Iminilibx-linux -lmlx -lXext -lX11 -o $(NAME) 

bonus: ${BONUS} 
${BONUS}: ${OBJS_BONUS}	
	make -C minilibx-linux
	$(CC) $(CFLAGS) $(OBJS_BONUS) -L./minilibx-linux -Iminilibx-linux -lmlx -lXext -lX11 -o $(BONUS)

clean:
	make clean -C minilibx-linux
	rm -rf $(OBJS) objs
	
fclean: clean
	rm -rf $(NAME)
	rm -rf $(BONUS)

re: fclean all
	

