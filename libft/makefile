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

NAME	=	libft.a

OBJDIR = Objets/

HEADER = Includes/

SRCDIR = Sources/

SRC		=	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_strcat.c ft_strchr.c ft_strcmp.c ft_strclr.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striteri.c ft_striter.c ft_strlcat.c ft_strmapi.c ft_strjoin.c ft_strlen.c ft_strncat.c ft_strncmp.c ft_strmap.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strrchr.c ft_strnstr.c ft_strstr.c ft_strsplit.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_splitlist.c ft_printlist.c ft_sqrt.c ft_strchr_one_more.c ft_sizeoflonglongint.c ft_putaddress.c ft_putoctal.c ft_strstr_int.c ft_atoi_longlongint.c ft_putnbr_spe.c ft_strlen_longlong.c ft_printf.c ft_printf_spe.c ft_verification_last.c ft_printfdi.c ft_printfdi_flags.c ft_putstr_printf.c ft_putaddress_printf.c ft_printfs.c ft_fillstruct_printf.c ft_buffer_printf.c ft_bufnbr_printf.c ft_putnbr_printf.c ft_atoi_longlongint.c ft_strlen_longlong.c ft_sizeoflonglongint.c ft_strstr_int.c ft_toupper.c ft_putpercent.c ft_typefor_address.c ft_printf_c.c ft_printfcsmaj.c ft_flagscmaj.c ft_flagssmaj.c ft_adjust_struct.c ft_starflag.c get_next_line.c ft_sizeofint.c ft_abs.c ft_compare.c ft_count_number.c ft_tablen.c

SRCS = $(addprefix $(SRCDIR), $(SRC))

OBJ = $(SRC:%.c=$(OBJDIR)%.o)

CC		=	gcc

CFLAGS	=	-Werror -Wextra -Wall -I $(HEADER)

DEL		=	rm -f

all: init $(NAME)

init:
		@mkdir -p $(OBJDIR)
norm:
		norminette $(SRCDIR) $(HEADER)

re:fclean all

$(NAME):$(OBJ)
	@ar rc $(NAME) $^

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $^ -o $@

fclean:clean
	@$(DEL) $(NAME)

clean:
	@$(DEL) $(OBJ)
