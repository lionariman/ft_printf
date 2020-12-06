# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keuclide <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 14:04:37 by keuclide          #+#    #+#              #
#    Updated: 2020/12/06 20:39:01 by keuclide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = ft_print.h

LIBA = ./libft/libft.a

SRCS =	ft_flags.c \
		ft_parser.c \
		ft_printf.c \
		ft_processor.c \
		ft_type_char.c \
		ft_dec_type.c \
		ft_dec_type_utils.c \
			 
OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

.c.o:
	@gcc $(FLAG) -I $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@make bonus -C ./libft
	@cp $(LIBA) $(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "Libftprint.a has been created"

all: $(NAME)

clean:
	@make clean -C ./libft
	@rm -rf $(OBJS)
	@echo "Binaries have been removed"

fclean: clean
	@make fclean -C ./libft
	@rm -rf $(NAME)
	@echo "Libftprint.a and binaries has been removed"

re: fclean all

.PHONY: all clean fclean re
