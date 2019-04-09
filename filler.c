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

static void					get_piece(t_filler *filler, char *line)
{
	int		i;
	int		ret;
	char	*temp;

	i = 0;
	ret = 0;
	filler->x = ft_atoi(line + 6);
	filler->y = ft_atoi(line + 6 + ft_getdigits(filler->x) + 1);
	free(line);
	filler->piece = malloc(sizeof(char) * (filler->x + 1) * filler->y + 1);
	temp = filler->piece;
	filler->piece[(filler->x + 1) * filler->y] = '\0';
	while (i < filler->y)
	{
		get_next_line(FD, &line);
		filler->piece = ft_strcpy(filler->piece, line);
		filler->piece[filler->x] = '\n';
		filler->piece += filler->x + 1;
		i++;
	}
	filler->piece = temp;
//	printf("%s\n", filler->piece);
}
	
static int					filler_loop(t_filler *filler)
{
	int		ret;
	char	*line;
	char	*map;

	map = NULL;
	ret = 1;
	while (ret > 0)
	{
		ret = get_next_line(FD, &line);
		if (ft_strnequ("Plateau ", line, 8) & !map)
			map = get_map(line);
		else if (ft_strnequ("Piece ", line, 6))
		{
			get_piece(filler, line);
			write (1, "8 2\n", 4);
		}
	}
	return (0);
}

static int					define_player(char *line)
{
	if (line[10] == '1')
		return ('O');
	else if (line[10] == '2')
		return ('X');
	return (0);
}

int							main(void)
{
	t_filler	*filler;
	char		*line;

	open("test", O_RDONLY);
	filler = malloc(sizeof(t_filler));
	filler->player = 0;
	get_next_line(FD, &line);
//	printf("%s\n", line);
	if (line && ft_strnequ("$$$ exec p", line, 10))
		filler->player = define_player(line);
	if (!filler->player)
		return (0);
	free(line);
	filler_loop(filler);
	return (0);
}
