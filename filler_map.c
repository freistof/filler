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

char				*score_map(t_filler *filler)
{
	int				i;
	int				score;
	int				save;

	i = 0;
	score = 0;
	while (filler->map[i] != '\0')
	{
		if (filler->map[i] == '.')
		{
			save = filler->mapx;
			while (i + save < filler->mapsize &&
				filler->map[i + save] != filler->enemy \
				&& filler->map[i + save] != filler->enemy + 32)
			{
				score++;
				save += save;
			}
			if (save + filler->mapx < filler->mapsize)
			filler->map[i] = score + '0';
		}
		i++;
	}
	return (filler->map);
}

/*
** first skips the first line (because it just shows the index)
** updates or fills map with y_lines function
*/

char				*fill_map(t_filler *filler, int y, int notfirst)
{
	int				i;
	char			*line;

	i = 0;
	get_next_line(FD, &line);
	free(line);
	if (notfirst)
		ft_bzero(filler->map, filler->mapy * (filler->mapx + 1) + 1);
	filler->map = get_y_lines(y, filler->map, 4);
	return (filler->map);
}

/*
** mallocs enough space for map according to input from first line above map
*/

char				*get_map(t_filler *filler, char *line)
{
	filler->mapy = ft_atoi(line + 8);
	filler->mapx = ft_atoi(line + 8 + ft_getdigits(filler->mapy) + 1);
	filler->mapsize = filler->mapy * filler->mapx;
	filler->map = ft_strnew(filler->mapsize + 1);
	filler->map = fill_map(filler, filler->mapy, 0);
	filler->map = score_map(filler);
	printf("%s\n", filler->map);
	return (filler->map);
}
