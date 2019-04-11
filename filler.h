/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 13:23:59 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/08 13:23:59 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft/libft.h"
# include "ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

typedef struct				s_filler
{
	char					player;
	int						mapx;
	int						mapy;
	char					*map;
	int						*x;
	int						*y;
	int						size;
	int						piecex;
	int						piecey;
	char					*piece;
}							t_filler;

char						*get_map(t_filler *filler, char *line);
char						*fill_map(t_filler *filler, int y, int notfirst);
void						get_piece(t_filler *filler, char *line);
char						*get_y_lines(int y, char *string, int start);

#endif
