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

	filler->map = NULL;
	ret = 1;
	line = ft_strdup("Y");
	while (ret > -1)
	{
		ret = get_next_line(FD, &line);
		FILE *fileno = fopen("testret", "w+");
		fprintf(fileno, "%i\n", ret);
		if (ft_strnequ("Plateau ", line, 8) && !filler->map)
			filler->map = get_map(filler, line);
		else if (ft_strnequ("Plateau ", line, 8))
			filler->map = fill_map(filler->map, filler->mapy, filler->mapx);
		else if (ft_strnequ("Piece ", line, 6))
		{
		//	get_piece(filler, line);
			place_piece(filler);
		}
	}
	return;
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
	t_filler 				*filler;

	filler = malloc(sizeof(t_filler));
	filler->player = 0;
	return (filler);
}

int							main(void)
{
	t_filler				*filler;
	char					*line;

//	open("test", O_RDONLY);
	line = NULL;
	filler = initialise_filler();
	get_next_line(FD, &line);
	if (line && ft_strnequ("$$$ exec p", line, 10))
		filler->player = define_player(line);
	if (!filler->player)
		return (0);
	FILE *fileno = fopen("testret", "w+");
	fprintf(fileno, "kut\n");
	filler_loop(filler);
	return (0);
}
