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
	FILE 					*checker;

	ret = 1;
	checker = fopen("checker", "w+");
	while (ret > -1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		fprintf(checker, "line: %s\n", line);
		if (!line || !ft_strlen(line))
			continue ;
		if (ft_strnequ("Plateau ", ft_strdup(line), 8))
		{
			fprintf(checker, "Plateau: \n");
			filler->map = get_map(filler, ft_strdup(line));
		}
		// else if (ft_strnequ("Plateau ", line, 8))
		// 	filler->map = fill_map(filler->map, filler->mapy, filler->mapx);
		else if (ft_strnequ("Piece ", line, 6))
		{
			get_piece(filler, ft_strdup(line));
			place_piece(filler);
		}
/*		ft_putnbr_fd(8, STDOUT_FILENO);
		ft_putchar_fd(' ', STDOUT_FILENO);
		ft_putnbr_fd(2, STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);*/
		free(line);
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

	line = NULL;
	open("test", O_RDONLY);
	filler = initialise_filler();
	get_next_line(STDIN_FILENO, &line);
	if (line && ft_strnequ("$$$ exec p", line, 10))
		filler->player = define_player(line);
	free (line);
	filler_loop(filler);
	return (0);
}
