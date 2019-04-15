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
	if (c == filler->enemy || c == filler->enemy + LOWERCASE)
		return (1);
	return (0);
}

int				define_y(t_filler *filler, int i)
{
	if (i != 0)
		return (i / filler->mapx);
	return (0);
}

int				define_x(t_filler *filler, int i)
{
	if (i != 0)
		return (i % filler->mapx);
	return (0);
}

void			score_map(t_filler *filler, int i, int score)
{
	if (filler_enemy(filler, filler->map[i]))
	{
		filler->score[i] = 0;
		score = 0;
	}
	else if (filler->score[i] != 0)
		filler->score[i] = score;

	if (i + 1 < filler->mapsize)
	{
		printf("score: %i\n", score);
		printf("%i\n", i);
		score_map(filler, i + 1, score + 1);
	}

	if (i - 1 > 0)
	{
		printf("score: %i\n", score);
		printf("%i\n", i);
		score_map(filler, i - 1, score + 1);
	}

	if (i + filler->mapx < filler->mapsize)
	{
		printf("score: %i\n", score);
		printf("%i\n", i);
		score_map(filler, i + filler->mapx, score + 1);
	}

	if (i - filler->mapx > 0)
	{
		printf("score: %i\n", score);
		printf("%i\n", i);
		score_map(filler, i - filler->mapx, score + 1);
	}
}
