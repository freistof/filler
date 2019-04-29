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
	if (i / mapx == (i + 1) / mapx && filler->score[i + 1] != score + 1)
		make_score_map(filler, i + 1, score + 1, mapx);
	make_score_map(filler, i - mapx, score + 1, mapx);
	if (i / mapx == (i - 1) / mapx && filler->score[i - 1] != score + 1)
		make_score_map(filler, i - 1, score + 1, mapx);
}
