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

static void					place_piece(t_filler *filler)
{
	int i;
	int x;
	int y;

	i = 0;
	while (filler->map[i] != '\0')
	{
		if (filler->map[i] == filler->player)
		{
			x = (i + 1) / (filler->mapx + 1);
			y = (i + 1) % (filler->mapx + 1) - 1;
		}
		i++;
	}
	ft_printf("%i %i\n", x, y);
}

static void					make_piece_arrays(int size, char *piece, t_filler *filler)
{
	int		i;
	int		arr_i;

	i = 0;
	arr_i = 0;
	filler->x = malloc(sizeof(int) * size);
	filler->y = malloc(sizeof(int) * size);
	while (piece[i] != '\0')
	{
		if (piece[i] == '*')
		{
			filler->x[arr_i] = (i + 1) / (filler->piecex + 1);
			filler->y[arr_i] = (i + 1) % (filler->piecex + 1) - 1;
			arr_i++;
		}
		i++;
	}
}

static int					piece_size(t_filler *filler)
{
	int		i;
	int		count;

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

void						get_piece(t_filler *filler, char *line)
{
	int		i;

	i = 0;
	filler->piecey = ft_atoi(line + 6);
	filler->piecex = ft_atoi(line + 6 + ft_getdigits(filler->piecey) + 1);
	filler->piece = ft_strnew(filler->piecey * (filler->piecex + 1) + 1);
	filler->piece = get_y_lines(filler->piecey, filler->piece, 0);
	make_piece_arrays(piece_size(filler), filler->piece, filler);
	free(filler->piece);
	place_piece(filler);
	free(filler->x);
	free(filler->y);
}
