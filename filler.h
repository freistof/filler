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
# include "printf/ft_printf.h"
# include <unistd.h>
# include <fcntl.h>

# define FD 0

typedef struct				s_filler
{
	char					player;
	char					enemy;
	int						mapx;
	int						mapy;
	int						mapsize;
	char					*map;
	int						*score;
	int						count;
	int						start;
	int						*x;
	int						*y;
	int						xshift;
	int						yshift;
	int						size;
	int						piecex;
	int						piecey;
	char					*piece;
}							t_filler;

char						*get_map(t_filler *filler, const char *line);
char						*fill_map(t_filler *filler, int y, int notfirst);

void						get_piece(t_filler *filler, const char *line);
void						place_piece(t_filler *filler);
void						move_piece_top_left(t_filler *filler);

void						make_score_map(t_filler *f, int i, int s, int mapx);

char						*get_y_lines(int y, char *string, int start);

#endif
