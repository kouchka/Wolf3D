# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: allallem <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/22 16:48:55 by allallem          #+#    #+#              #
#    Updated: 2018/03/08 16:57:15 by allallem         ###   ########.fr        #
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
				ft_wolf.c\
				my_keys_event.c\
				ft_game.c\
				ft_calc_in_game.c\
				ft_print_map.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC		=	gcc

CFLAGS	=	-Werror -Wextra -Wall -I $(HEADER) -I $(LIB_PATH) -I $(MINI)

DEL		=	rm -f

LIBX 	= -L minilibx_macos -lmlx -framework OpenGL -framework appkit -lpthread

LIB		= -L libft -lft

all: init $(NAME)

init:
	@mkdir -p $(OBJDIR)

view:
	@echo $(OBJ)
	echo $(SRCS)
	@echo $(SRC)

norm:
	norminette $(SRCDIR) $(HEADER)

re:fclean all

$(NAME):$(OBJ)
	make -C libft
	make -C minilibx_macos
	$(CC) -o $(NAME) $^ $(CFLAGS) $(LIB) $(LIBX)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean:clean
	make -C libft fclean
	make -C minilibx_macos clean
	@$(DEL) $(NAME)

clean:
	@$(DEL) $(OBJ)
