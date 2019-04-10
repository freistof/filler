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
# include <unistd.h>
# include <stdio.h> // remove
# include <fcntl.h> // remove ?


# define FD 1
//# define FD 3

typedef struct 				s_filler
{
	char					player;
	int						mapx;
	int						mapy;
	char					*map;
	int						x;
	int						y;
	char					*piece;
	int						*xpiece;
	int						*ypiece;
}							t_filler;	

char						*get_map(t_filler *filler, char *line);
char						*fill_map(char *map, int x, int y);
void						get_piece(t_filler *filler, char *line);
void						place_piece(t_filler *filler);

#endif
