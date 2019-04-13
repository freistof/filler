/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 12:17:01 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/10 12:17:01 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** blocks could be formatted like this:
** ..*
** ..*
** where the asterixes need to overlap with the current map,
** but the coordinates of the top left corner should be given
** real_pos() defines the position of the stars to check if
** there is already an obstacle or not
*/

static int						real_pos(t_filler *filler, int i, int fi)
{
	return (i + filler->mapx * filler->y[fi] + filler->x[fi]);
}

static int            out_of_map(t_filler *filler, int i)
{
	int		fi;
	int		pos[filler->size];
	int		dif;

	fi = 0;
	while (fi < filler->size)
	{
		pos[fi] = real_pos(filler, i, fi) / filler->mapx;
		fi++;
	}
	dif = pos[0] - filler->y[0];
	fi = 0;
	while (fi < filler->size)
	{
		if (filler->y[fi] + dif != pos[fi])
			return (1);
		fi++;
	}
	return (0);
}

/*
** 
*/

static int						fit_piece(t_filler *filler, int i)
{
	int		fi;
	int		count;
	
	fi = 0;
	count = 0;
	if (out_of_map(filler, i))
		return (0);
	while (fi < filler->size)
	{
		if (real_pos(filler, i, fi) >= filler->mapsize)
			return (0);
		if (filler->map[real_pos(filler, i, fi)] == filler->enemy ||
			filler->map[real_pos(filler, i, fi)] == filler->enemy + 32)
			return (0);
		if (filler->map[real_pos(filler, i, fi)] == filler->player ||
			filler->map[real_pos(filler, i, fi)] == filler->player + 32)
			count++;
		fi++;
	}
	if (count == 1)
		return (1);
	return (0);
}

/*
** loops through map string and checks if piece fits with fit_piece()
** defines y and x coordinates and prints them
*/

static void                               	place_piece(t_filler *filler)
{
	   int i;
	   int x;
	   int y;

	   x = 0;
	   y = 0;
	   i = 0;
	   while (i < filler->mapsize)
		{
			if (fit_piece(filler, i))
			{
				if (i / filler->mapx + filler->piecey < filler->mapy)
					y = i / filler->mapx;
				if (i % filler->mapx + filler->piecex < filler->mapx)
					x = i % filler->mapx;
			}
			i++;
		}
		ft_printf("%i %i\n", y, x);
}

/*
** mallocs and reads from the filler->piece string
** then puts x and y coordinates in the int arrays accordingly
*/

static void                               	make_piece_arrays(int size, char *piece, t_filler *filler)
{
	   int             i;
	   int             arr_i;

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

static int                                	piece_size(t_filler *filler)
{
	   int             i;
	   int             count;

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

void                                      	get_piece(t_filler *filler, char *line)
{
	   int             i;

	   i = 0;
	   filler->piecey = ft_atoi(line + 6);
	   filler->piecex = ft_atoi(line + 6 + ft_getdigits(filler->piecey) + 1);
	   filler->piece = ft_strnew(filler->piecey * filler->piecex + 1);
	   filler->piece = get_y_lines(filler->piecey, filler->piece, 0);
	   make_piece_arrays(piece_size(filler), filler->piece, filler);
	   free(filler->piece);
	   place_piece(filler);
	   free(filler->x);
	   free(filler->y);
}
