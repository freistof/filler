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

int					first_enemy(t_filler *filler)
{
	int i;

	i = 0;
	while (filler->map[i] != '\0')
	{
		if (filler->map[i] == filler->enemy || filler->map[i] == filler->enemy + LOWERCASE)
			return (i);
		i++;
	}
	return (0);
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
	filler->score = malloc(sizeof(int) * filler->mapsize);
	printf("mapsize: %i\nmapx: %i\n, mapy %i\n", filler->mapsize, filler->mapx, filler->mapy);
	score_map(filler, first_enemy(filler), 0);
	for (int i = 0; i < filler->mapsize; i++)
		printf("%c\t%i\n", filler->map[i], filler->score[i]);
	return (filler->map);
}
