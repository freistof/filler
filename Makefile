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

SRCS = filler.c filler_map.c filler_piece.c

all: $(NAME)

$(NAME):
	gcc -o $(NAME) $(FLAGS) $(SRCS) libft/libft.a

clean:
	rm -f $(TRACE)

fclean: clean
	rm -f $(NAME)

re: fclean all
