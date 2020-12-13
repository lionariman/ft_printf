# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: keuclide <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/29 14:04:37 by keuclide          #+#    #+#              #
#    Updated: 2020/12/13 18:02:39 by keuclide         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INC = libft.h

SRCS = ft_putnbr_fd.c \
	   ft_isdigit.c \
	   ft_putstr_fd.c \
	   ft_strlen.c \
	   ft_putchar_fd.c \
			 
OBJS = $(SRCS:.c=.o)

FLAG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

.c.o:
	@gcc $(FLAG) -I $(INC) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
