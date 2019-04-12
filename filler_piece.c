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

static int						real_pos(t_filler *filler, int i, int fi)
{
	return (i + filler->mapx * filler->y[fi] + filler->x[fi]);
}

static int						fit_piece(t_filler *filler, int i)
{
	int		fi;
	int		count;
	
	fi = 0;
	count = 0;
	while (fi < filler->size)
	{
		// i / filler->mapx = Y
		// i % filler->mapx = X
//    printf("%i\n%i\n\n", real_pos(filler, i, fi) / filler->mapx, filler->y[fi]);
/*		if (real_pos(filler, i, fi) / filler->mapx == filler->y[fi])
			return (0);
    if (real_pos(filler, i, fi) % filler->mapx == filler->x[fi])
      return (0);*/
		if (filler->map[real_pos(filler, i, fi)] == filler->enemy ||
			filler->map[real_pos(filler, i, fi)] == filler->enemy + 32)
			return (0);
		if (filler->map[real_pos(filler, i, fi)] == filler->player)
			count++;
		fi++;
	}
	if (count == 1)
		return (1);
	return (0);
}

static void                               	place_piece(t_filler *filler)
{
       int i;
       int x;
       int y;

       x = 0;
       y = 0;
       i = 0;
       while (filler->map[i] != '\0')
       {
			if (fit_piece(filler, i))
			{
				y = i / filler->mapx;
				x = i % filler->mapx;
			}
               i++;
       }
       ft_printf("%i %i\n", y, x);
}

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