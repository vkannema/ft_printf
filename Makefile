# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkannema <vkannema@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/21 21:10:13 by vkannema          #+#    #+#              #
#    Updated: 2016/12/21 21:25:06 by vkannema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_print_s.c \
	ft_print_c.c \
	ft_putchar.c \
	ft_putoctal.c \
	ft_putstr.c \
	print_arg.c \
	ft_printf.c \
	flags.c \
	check_type.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) :
	@gcc $(FLAGS) -c $(SRC) 
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "libftprintf done"

clean :
	rm -f $(OBJ)
	make clean -C ./Libft

fclean : clean
	rm -f $(NAME)
	make fclean -C ./Libft

re : fclean all
