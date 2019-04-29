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
#include <stdio.h> // remove

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

int					define_x(t_filler *filler, int i)
{
	return (i % filler->mapy);
}

int					absolute(int a)
{
	if (a < 0)
		return (a * -1);
	return (a);
}

void				make_side_scores(t_filler *filler)
{
	int i;

	i = 0;
	while (i < filler->mapsize)
	{
		filler->score[i] -= (
			absolute(filler->mapy / 2  - define_y(filler, i)) + \
			absolute(filler->mapx / 2 - define_x(filler, i)));
		i++;
	}
}

/*
** starts at the first filler enemy piece
** goes to directions (four times) and gives score according
** to how far from the enemy the position is
*/

void				make_score_map(t_filler *filler, int i, int score, int mapx)
{
	if (i < 0 || i > filler->mapsize || filler->score[i] <= score)
		return ;
	if (filler->map[i] == filler->enemy || filler->map[i] == filler->enemy + 32)
		score = 0;
	filler->score[i] = score;
	make_score_map(filler, i + mapx, score + 1, mapx);
	if (i / mapx == (i + 1) / mapx)/* && filler->score[i + 1] != score + 1*/
		make_score_map(filler, i + 1, score + 1, mapx);
	make_score_map(filler, i - mapx, score + 1, mapx);
	if (i / mapx == (i - 1) / mapx)/* && filler->score[i - 1] != score + 1*/
		make_score_map(filler, i - 1, score + 1, mapx);
}

/*
** filler score map is divided in four fields, then filled with score
*/

void				four_directions_map(t_filler *filler, int i)
{
//	int		dir[2];

//	FILE *test;
//	test = fopen("scorechecker", "w!");

//	dir[0] = -1;
//	dir[1] = -filler->mapx;
	make_score_map(filler, i, 0, filler->mapx);
/*	dir[0] = +1;
	dir[1] = -filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = +1;
	dir[1] = +filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = -1;
	dir[1] = +filler->mapx;
	make_score_map(filler, i, 0, dir);*/

//	make_side_scores(filler);
/*	for (int i = 0; i < filler->mapy; i++)
	{
		for (int j = 0; j < filler->mapx; j++)
			fprintf(test, "%c\t%i\t", filler->map[i * filler->mapx + j], filler->score[i * filler->mapx + j]);
		fprintf(test, "\n");
	}*/
}

/*	if (define_y(filler, i) == define_y(filler, i + dir[0])
		&& (filler->score[i + dir[0]] == 0 || filler->score[i + dir[0]] > score))
		make_score_map(filler, i + dir[0], score + 1, dir);
	if (i + dir[1] >= 0 && i + dir[1] < filler->mapsize && (filler->score[i + dir[1]] == 0 || filler->score[i + dir[1]] > score))
		make_score_map(filler, i + dir[1], score + 1, dir);*/
