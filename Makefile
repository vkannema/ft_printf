# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/21 21:10:13 by vkannema          #+#    #+#              #
#    Updated: 2017/01/05 11:33:47 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_putchar.c \
	ft_putoctal.c \
	ft_putstr.c \
	print_arg.c \
	flags.c \
	ft_size_nbr.c \
	check_type.c \
	ft_strlen.c \
	ft_printf.c \
	ft_print_o.c \
	ft_print_x.c \
	ft_print_xcap.c \
	ft_print_di.c \
	ft_print_p.c \
	ft_print_s.c \
	ft_print_c.c \
	ft_print_pe.c \
	ft_isdigit.c \
	precision.c \
	type_flag.c \
	ft_atoi.c \
	ft_putnbr.c \
	print_precision.c \
	width.c \
	ft_memdel.c


OBJ = $(SRC:.c=.o)

FLAGS = -g -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRC)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf done"

clean :
	@rm -f $(OBJ)

fclean : clean
	@rm -f $(NAME)

re : fclean all
