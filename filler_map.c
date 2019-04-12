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

char				*fill_map(t_filler *filler, int y, int notfirst)
{
	int		i;
	char	*line;

	i = 0;
	get_next_line(FD, &line);
	free(line);
	if (notfirst)
		ft_bzero(filler->map, filler->mapy * (filler->mapx + 1) + 1);
	filler->map = get_y_lines(y, filler->map, 4);
	return (filler->map);
}

char				*get_map(t_filler *filler, char *line)
{
	filler->mapy = ft_atoi(line + 8);
	filler->mapx = ft_atoi(line + 8 + ft_getdigits(filler->mapy) + 1);
	filler->map = ft_strnew(filler->mapy * filler->mapx + 1);
	filler->map = fill_map(filler, filler->mapy, 0);
	return (filler->map);
}
