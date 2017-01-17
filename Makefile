# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/21 21:10:13 by vkannema          #+#    #+#              #
#    Updated: 2017/01/17 14:31:52 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC =./libft/ft_isalnum.c \
	./libft/ft_isalpha.c \
	./libft/ft_isascii.c \
	./libft/ft_isdigit.c \
	./libft/ft_isprint.c \
	./libft/ft_itoa.c \
	./libft/ft_memset.c \
	./libft/ft_putchar_fd.c \
	./libft/ft_putendl.c \
	./libft/ft_putendl_fd.c \
	./libft/ft_putnbr_fd.c \
	./libft/ft_putstr_fd.c \
	./libft/ft_strncat.c \
	./libft/ft_strrchr.c \
	./libft/ft_strchr.c \
	./libft/ft_strcpy.c \
	./libft/ft_strdup.c \
	./libft/ft_strequ.c \
	./libft/ft_striter.c \
	./libft/ft_striteri.c \
	./libft/ft_strmap.c \
	./libft/ft_strmapi.c \
	./libft/ft_strcat.c \
	./libft/ft_strcmp.c \
	./libft/ft_strncpy.c \
	./libft/ft_strnequ.c \
	./libft/ft_strnstr.c \
	./libft/ft_strstr.c \
	./libft/ft_tolower.c \
	./libft/ft_toupper.c \
	./libft/ft_strncmp.c \
	./libft/ft_memset.c \
	./libft/ft_bzero.c \
	./libft/ft_memcpy.c \
	./libft/ft_memccpy.c \
	./libft/ft_memmove.c \
	./libft/ft_memchr.c \
	./libft/ft_memcmp.c \
	./libft/ft_strlcat.c \
	./libft/ft_memalloc.c \
	./libft/ft_memdel.c \
	./libft/ft_strnew.c \
	./libft/ft_strdel.c \
	./libft/ft_strclr.c \
	./libft/ft_strsub.c \
	./libft/ft_strjoin.c \
	./libft/ft_strtrim.c \
	./libft/ft_strsplit.c \
	./libft/ft_lstnew.c \
	./libft/ft_lstdelone.c \
	./libft/ft_lstdel.c \
	./libft/ft_lstadd.c \
	./libft/ft_lstiter.c \
	./libft/ft_lstmap.c \
	ft_putchar.c \
	ft_putoctal.c \
	ft_putstr.c \
	print_arg.c \
	flags.c \
	ft_size_nbr.c \
	check_type.c \
	ft_strlen.c \
	ft_printf.c \
	ft_print_o.c \
	ft_print_o_cap.c \
	ft_print_x.c \
	ft_print_xcap.c \
	ft_print_di.c \
	ft_print_d_cap.c \
	ft_print_p.c \
	ft_print_s.c \
	ft_print_c.c \
	ft_print_pe.c \
	ft_print_u.c \
	ft_print_u_cap.c \
	ft_print_c_cap.c \
	ft_print_s_cap.c \
	ft_isdigit.c \
	precision.c \
	ft_atoi.c \
	ft_putnbr.c \
	print_precision.c \
	width.c \
	ft_memdel.c \
	modif.c \
	preci_and_width.c \
	convert.c \
	unsigned_utility.c \
	clean_env.c


OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@make -C ./libft
	@echo "lib done"
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf done"
##	gcc main.c libftprintf.a

clean :
	@make clean -C ./libft
	@echo "./libft cleaned"
	@rm -f $(OBJ)
	@echo "printf clean"

fclean : clean
	@make fclean -C ./libft
	@rm -f $(NAME)

re : fclean all
