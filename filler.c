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

/*
** while there is a line, gets the next line
** if line is "Plateau x y" get_map()
** mallocs map if it doesn't exist yet (see initalise_filler)
** else fill_map() updates the map
** moves on to get_piece function to find the correct place
*/

static void					filler_loop(t_filler *filler)
{
	int						ret;
	char					*line;

	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(FD, &line);
		if (!line)
			continue ;
		if (ft_strnequ("Plateau ", line, 8) && !filler->map)
			filler->map = get_map(filler, line);
		else if (ft_strnequ("Plateau ", line, 8))
			filler->map = fill_map(filler, filler->mapy, 1);
		else if (ft_strnequ("Piece ", line, 6))
			get_piece(filler, line);
		ft_strdel(&line);
	}
	ft_strdel(&filler->map);
}

/*
** defines player and enemy chars
*/

static int					define_players(char *line, t_filler *filler)
{
	if (line[10] == '1')
	{
		filler->player = 'O';
		filler->enemy = 'X';
	}
	else if (line[10] == '2')
	{
		filler->player = 'X';
		filler->enemy = 'O';
	}
	return (0);
}

/*
** mallocs and initialises the filler so player, map, and enemy
** can be defined
*/

static t_filler				*initialise_filler(void)
{
	t_filler				*filler;

	filler = malloc(sizeof(t_filler));
	filler->player = 0;
	filler->enemy = 0;
	filler->map = NULL;
	filler->score = NULL;
	return (filler);
}

/*
** the main check the first line to define the player
** if there is no line or no player defined, return (0)
*/

int							main(void)
{
	t_filler				*filler;
	char					*line;

	filler = initialise_filler();
	get_next_line(FD, &line);
	define_players(line, filler);
	ft_strdel(&line);
	filler_loop(filler);
	return (0);
}
