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

SRCS = filler.c filler_map.c filler_piece.c make_piece.c helpers.c \
		filler_score.c

all: $(NAME)

$(NAME):
	make -C libft/
	make -C printf/
	gcc -o $(NAME) $(FLAGS) $(SRCS) libft/libft.a printf/libftprintf.a

clean:
	make -C libft/ clean
	make -C printf/ clean
	rm -f $(TRACE)

fclean: clean
	make -C libft/ fclean
	make -C printf/ fclean
	rm -f $(NAME)

re: fclean all
