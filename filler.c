/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 13:15:20 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/08 13:15:21 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void					filler_loop(t_filler *filler)
{
	int						ret;
	char					*line;

	ret = 1;
	while (ret > -1)
	{
		ret = get_next_line(0, &line);
		if (!line || !ft_strlen(line))
			continue ;
		if (ft_strnequ("Plateau ", line, 8) && !filler->map)
			filler->map = get_map(filler, line);
		else if (ft_strnequ("Plateau ", line, 8))
			filler->map = fill_map(filler, filler->mapy, 1);
		else if (ft_strnequ("Piece ", line, 6))
			get_piece(filler, line);
		free(line);
	}
	free(filler->map);
}

static int					define_player(char *line)
{
	if (line[10] == '1')
		return ('O');
	else if (line[10] == '2')
		return ('X');
	return (0);
}

static t_filler				*initialise_filler(void)
{
	t_filler				*filler;

	filler = malloc(sizeof(t_filler));
	filler->player = 0;
	filler->map = NULL;
	return (filler);
}

int							main(void)
{
	t_filler				*filler;
	char					*line;

	filler = initialise_filler();
	get_next_line(0, &line);
	if (line && ft_strnequ("$$$ exec p", line, 10))
		filler->player = define_player(line);
	free(line);
	filler_loop(filler);
	return (0);
}
