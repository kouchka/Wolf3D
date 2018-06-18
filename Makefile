# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <allallem@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 16:48:55 by allallem          #+#    #+#              #
#    Updated: 2018/06/18 07:50:57 by allallem         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	wolf3d

MINI = minilibx_macos/

LIB_PATH = libft/Includes/

SRCDIR = Sources/

OBJDIR = Objets/

HEADER = Includes/

SRC		= main.c\
				ft_check_map.c\
				ft_check_map_two.c\
				ft_wolf.c\
				ft_my_keys_event.c\
				ft_my_keys_event_two.c\
				ft_game.c\
				ft_calc_in_game.c\
				ft_print_map.c\
				ft_get_texture.c\
				ft_draw_skybox.c\
				ft_trace_fov.c\
				ft_trace_seg.c\
				ft_intro.c\
				ft_last_functions.c\
				ft_draw_wall.c\
				ft_raycasting.c\
				ft_recalc.c\
				ft_shot.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC		=	gcc

CFLAGS	=	-Wextra -Wall -Werror -I $(HEADER) -I $(LIB_PATH) -I $(MINI)\
					$(shell sdl-config --cflags)

DEB =  -fsanitize=address -g

DEL		=	rm -f

LIBX 	= -L minilibx_macos -lmlx -framework OpenGL -framework appkit -lpthread

LIB		= -L libft -lft $(shell sdl-config --libs) -lSDL_mixer

all: init $(NAME)

init:
	@mkdir -p $(OBJDIR)

view:
	@echo $(OBJ)
	echo $(SRCS)
	@echo $(SRC)

norm:
	norminette $(SRCDIR) $(HEADER) libft/Sources libft/Includes

debug	:	fclean
	make DEBUG=1

re:fclean all

$(NAME):$(OBJ)
	make -C libft
	make -C minilibx_macos
ifdef DEBUG
	$(CC) -o $(NAME) $^ $(CFLAGS) $(DEB) $(LIB) $(LIBX)
else
	$(CC) -o $(NAME) $^ $(CFLAGS) $(LIB) $(LIBX)
endif

$(OBJDIR)%.o:$(SRCDIR)%.c
ifdef DEBUG
	$(CC) $(CFLAGS) $(DEB) -c $^ -o $@
else
	$(CC) $(CFLAGS) -c $^ -o $@
endif

fclean:clean
	make -C libft fclean
	make -C minilibx_macos clean
	@$(DEL) $(NAME)

clean:
	@$(DEL) $(OBJ)
