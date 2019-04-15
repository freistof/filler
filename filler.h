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
# include <stdio.h> // remove

# define FD 3
# define LOWERCASE +32

typedef struct				s_filler
{
	char					player;
	char					enemy;
	int						mapx;
	int						mapy;
	int						mapsize;
	char					*map;
	int						*score;
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
void						place_piece(t_filler *filler);

void						score_map(t_filler *filler, int i, int score);
void						score_map_minus(t_filler *filler, int input, int score);

char						*get_y_lines(int y, char *string, int start);

#endif
