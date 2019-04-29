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
** where the asterixes need to overlap with the pieces already placed,
** but the coordinates of the top left corner should be given
** real_pos() defines the position of the stars to check if
** there is already an obstacle or not
*/

static int					real_pos(t_filler *filler, int i, int fi)
{
	return (i + filler->mapx * filler->y[fi] + filler->x[fi]);
}

/*
** out of map checks if 'the coordinate is within the map, by checking
** if x and y values still correspond with original values
*/

static int					out_of_map(t_filler *filler, int i)
{
	int						fi;
	int						pos[filler->size];
	int						dif;

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
** loops through the current map and checks if there is only ONE overlap
** with player's pieces, and if there are no obstacles in the form of
** enemy pieces
*/

static int					fit_piece(t_filler *filler, int i)
{
	int						fi;
	int						count;

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
** gives pieces a score depending on the score map
** the closer to the enemy, the lower the points
*/

static unsigned int			get_points(t_filler *filler, int i)
{
	int						points;
	int						fi;

	fi = 0;
	points = 0;
	while (fi < filler->size)
	{
		points += filler->score[real_pos(filler, i, fi)];
		fi++;
	}
	return (points);
}

/*
** loops through map string and checks if piece fits with fit_piece()
** defines y and x coordinates and prints them
*/

void						place_piece(t_filler *filler)
{
	int						i;
	int						x;
	int						y;
	unsigned int			points;

	x = 0;
	y = 0;
	i = 0;
	points = -1;
	while (i < filler->mapsize)
	{
		if (fit_piece(filler, i) && get_points(filler, i) <= points)
		{
			x = i % filler->mapx - filler->xshift;
			y = i / filler->mapx - filler->yshift;
			points = get_points(filler, i);
		}
		i++;
	}
	ft_printf("%i %i\n", y, x);
}
