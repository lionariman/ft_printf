# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keuclide <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 14:04:37 by keuclide          #+#    #+#              #
#    Updated: 2020/12/13 18:02:52 by keuclide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INC = ft_header/

LIBA = ./libft/libft.a

VPATH = ft_main ft_types ft_utils

SRCS =	ft_flags.c \
		ft_printf.c \
		ft_parser.c \
		ft_processor.c \
		ft_char_type.c \
		ft_str_type.c \
		ft_str_one.c \
		ft_str_two.c \
		ft_dec_type.c \
		ft_dec_one.c \
		ft_dec_two.c \
		ft_hex_type.c \
		ft_hex_one.c \
		ft_hex_two.c \
		ft_ptr_type.c \
		ft_ptr_one.c \
		ft_ptr_two.c \
		ft_prc_type.c \
			 
OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

.c.o:
	@gcc $(FLAG) -I $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@make -C ./libft
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
