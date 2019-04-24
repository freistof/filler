# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/30 10:51:20 by lvan-vlo       #+#    #+#                 #
#    Updated: 2019/04/18 19:40:51 by fblom         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

TEST = ft_printf

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

SRC = ft_printf.c ft_strnjoin.c ft_itoa_base.c ft_utoa_base.c \
		conversionist.c ft_make_conversion.c csp_conversion.c \
		di_conversion.c oux_conversion.c precision_padding.c \
                ft_f_conversion.c

OBJS := ${SRC:c=o}

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c $(SRC) -I ft_printf.h
	ar rc $(NAME) ../libft/libft.a

clean:
	rm -f $(OBJS) $(LOBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all