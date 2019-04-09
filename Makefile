#******************************************************************************#
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fblom <marvin@codam.nl>                      +#+                      #
#                                                    +#+                       #
#    Created: 2019/04/08 12:42:21 by fblom         #+#    #+#                  #
#    Updated: 2019/04/08 12:42:21 by fblom         ########   odam.nl          #
#                                                                              #
#******************************************************************************#

LOGIN = fblom

TRACE = filler.trace

NAME = $(LOGIN).filler

FLAGS = -Wall -Werror -Wextra

SRCS = filler.c filler_map.c

all: $(NAME)

$(NAME):
	make -C libft/
	gcc -o $(NAME) $(FLAGS) $(SRCS) libft/libft.a

clean:
	make -C libft/ clean
	rm -f $(TRACE)

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

libre:
	make -C libft/ re

re: libre fclean all
