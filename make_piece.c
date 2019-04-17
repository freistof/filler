/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_piece.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 17:48:32 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/15 17:48:32 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** mallocs and reads from the filler->piece string
** then puts x and y coordinates in the int arrays accordingly
*/

static void			make_piece_arrays(int size, char *piece, t_filler *filler)
{
	int				i;
	int				arr_i;

	i = 0;
	arr_i = 0;
	filler->x = malloc(sizeof(int) * size);
	filler->y = malloc(sizeof(int) * size);
	while (piece[i] != '\0')
	{
		if (piece[i] == '*')
		{
			filler->x[arr_i] = i % filler->piecex;
			filler->y[arr_i] = i / filler->piecex;
			arr_i++;
		}
		i++;
	}
}

/*
** determines the size of the int arrays that contain the piece data
*/

static int			piece_size(t_filler *filler)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (filler->piece[i] != '\0')
	{
		if (filler->piece[i] == '*')
			count++;
		i++;
	}
	filler->size = count;
	return (count);
}

/*
** gets x and y values of piece from the line read in filler_loop()
** mallocs a string accordingly and then writes in it in get_y_lines()
** makes int arrays in make_piece_arrays()
** moves on to place piece
*/

void				get_piece(t_filler *filler, char *line)
{
	int				i;

	i = 0;
	filler->piecey = ft_atoi(line + 6);
	filler->piecex = ft_atoi(line + 6 + ft_getdigits(filler->piecey) + 1);
	filler->piece = ft_strnew(filler->piecey * filler->piecex + 1);
	filler->piece = get_y_lines(filler->piecey, filler->piece, 0);
	make_piece_arrays(piece_size(filler), filler->piece, filler);
	place_piece(filler);
	ft_strdel(&(filler->piece));
	free(filler->x);
	free(filler->y);
}
