/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler_score.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/15 19:56:11 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/15 19:56:11 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				filler_enemy(t_filler *filler, char c)
{
	if (c == filler->enemy)
		return (1);
	return (0);
}

int				define_y(t_filler *filler, int i)
{
	return (i / filler->mapx);
	return (0);
}

int				define_x(t_filler *filler, int i)
{
	return (i % filler->mapx);
	return (0);
}

void			score_map(t_filler *filler, int input, int score)
{
	int		i;

	i = input;
	filler->score[i] = score;

	if (i - 1 > 0 && define_y(filler, i) == define_y(filler, i - 1))
	{
		score_map(filler, i - 1, score + 1);
	}
	i = input;
	if (i + filler->mapx < filler->mapsize)
	{
		score_map(filler, i + filler->mapx, score + 1);
	}

}

void			score_map_minus(t_filler *filler, int input, int score)
{
	int			i;

	i = input;
	filler->score[i] = score;
	if (i + 1 < filler->mapsize && define_y(filler, i) == define_y(filler, i + 1))
	{
		score_map(filler, i + 1, score + 1);
	}
	i = input;
	if (i - filler->mapx > 0)
	{
		score_map(filler, i - filler->mapx, score + 1);
	}
}