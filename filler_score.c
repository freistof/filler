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

/*
** returns 1 if character is an enemy character
*/

int					filler_enemy(t_filler *filler, char c)
{
	if (c == filler->enemy || c == filler->enemy + 32)
		return (1);
	return (0);
}

/*
** defines the y value of a position on the map
*/

int					define_y(t_filler *filler, int i)
{
	return (i / filler->mapx);
}

void				make_side_scores(t_filler *filler)
{
	int y;
	int x;
	int	add;

	y = 0;
	while (y < filler->mapy)
	{
		add = 0;
		x = 0;
		while (x < filler->mapx / 2)
		{
			filler->score[y * filler->mapx + x] += add;
			add++;
			x++;
		}
		while (x < filler->mapx)
		{
			filler->score[y * filler->mapx + x] += add;
			add--;
			x++;
		}
		y++;
	}

}

/*
** starts at the first filler enemy piece
** goes to directions (four times) and gives score according
** to how far from the enemy the position is
*/

void				make_score_map(t_filler *filler, int i, int score, int *dir)
{
	if (i < 0 || i >= filler->mapsize)
		return ;
	if (filler->map[i] == filler->enemy)
	{
		filler->score[i] = 0;
		score = 0;
	}
	if (filler->score[i] == -1)
		filler->score[i] = score;
	if (define_y(filler, i) == define_y(filler, i + dir[0])
		&& filler->score[i + dir[0]] == -1)
		make_score_map(filler, i + dir[0], score + 1, dir);
	if (i + dir[1] >= 0 && filler->score[i + dir[1]] == -1)
		make_score_map(filler, i + dir[1], score + 1, dir);
}

/*
** filler score map is divided in four fields, then filled with score
*/

void				four_directions_map(t_filler *filler, int i)
{
	int		dir[2];

	dir[0] = -1;
	dir[1] = -filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = +1;
	dir[1] = +filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = -1;
	dir[1] = +filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = 1;
	dir[1] = -filler->mapx;
	make_score_map(filler, i, 0, dir);
//	make_side_scores(filler);
}
