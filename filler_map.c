/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler_map.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 18:34:42 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/11 18:34:43 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** finds the first position that contains an enemy character
*/

static int			first_enemy(t_filler *filler)
{
	int i;

	i = 0;
	while (filler->map[i] != '\0')
	{
		if (filler->map[i] == filler->enemy || filler->map[i] == filler->enemy + 32)
			return (i);
		i++;
	}
	return (0);
}

/*
** mallocs the score map if it's the first time
** initalises points to zero
** fills the score map with scores (filler_score.c)
*/

int					*fill_score_map(t_filler *filler)
{
	int				i;

	i = 0;
	filler->start = first_enemy(filler);
	while (i < filler->mapsize)
	{
		filler->score[i] = -1;
		i++;
	}
	four_directions_map(filler, filler->start);
	return (filler->score);
}

/*
** first skips the first line (because it just shows the index)
** updates or fills map with y_lines function
*/

char				*fill_map(t_filler *filler, int y, int notfirst)
{
	int				i;
	int				ret;
	char			*line;

	i = 0;
	ret = 1;
	get_next_line(FD, &line);
	ft_strdel(&line);
	if (notfirst)
		ft_bzero(filler->map, filler->mapy * (filler->mapx + 1) + 1);
	filler->map = get_y_lines(y, filler->map, 4);
	filler->score = fill_score_map(filler);
	return (filler->map);
}



/*
** mallocs enough space for map according to input from first line above map
*/

char				*get_map(t_filler *filler, const char *line)
{
	filler->mapy = ft_atoi(line + 8);
	filler->mapx = ft_atoi(line + 8 + ft_getdigits(filler->mapy) + 1);
	filler->mapsize = filler->mapy * filler->mapx;
	while (!filler->map)
		filler->map = ft_strnew(filler->mapsize + 1);
	while (!filler->score)
	filler->score = malloc(sizeof(int) * filler->mapsize);
	filler->map = fill_map(filler, filler->mapy, 0);
	return (filler->map);
}
