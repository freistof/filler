/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/11 18:14:34 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/11 18:14:34 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** gets y lines and strcats them
*/

char			*get_y_lines(int y, char *string, int start)
{
	int			i;
	char		*line;
//	char		*dup;

	i = 0;
	while (i < y)
	{
		get_next_line(FD, &line);
		string = ft_strcat(string, line + start);
		i++;
		ft_strdel(&line);
	}
	return (string);
}
