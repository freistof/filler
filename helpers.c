/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 18:14:34 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/11 18:14:34 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** gets y lines and strcats them
*/

char			*get_y_lines(int y, char *string, int start)
{
	int			i;
	int			ret;
	char		*line;

	i = 0;
	while (i < y)
	{
		ret = get_next_line(FD, &line);
		string = ft_strcat(string, line + start);
		i++;
		ft_strdel(&line);
	}
	return (string);
}

/*
** checks if at least one of the ints in the int array is zero
*/

int				no_zeroes(int *array, int len)
{
	int			i;

	i = 0;
	while (i < len)
	{
		if (array[i] == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
** moves piece to top left position in cell
** determines the x/y shift accordingly
*/

void			move_piece_top_left(t_filler *filler)
{
	int			i;

	while (no_zeroes(filler->x, filler->size))
	{
		i = 0;
		while (i < filler->size)
		{
			filler->x[i]--;
			i++;
		}
		filler->xshift++;
	}
	while (no_zeroes(filler->y, filler->size))
	{
		i = 0;
		while (i < filler->size)
		{
			filler->y[i]--;
			i++;
		}
		filler->yshift++;
	}
}
