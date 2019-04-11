/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   filler_piece.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/10 12:17:01 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/10 12:17:01 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void					place_piece(t_filler *filler)
{
	int i;
	int x;
	int y;

	i = 0;
	while (filler->map[i] != '\0')
	{
		if (filler->map[i] == filler->player)
		{
			x = (i + 1) / (filler->mapx + 1);
			y = (i + 1) % (filler->mapx + 1) - 1;
		}
		i++;
	}
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

void					get_piece(t_filler *filler, char *line)
{
	int		i;
	int		ret;
	char	*temp;

	FILE *checker = fopen("checkerpiece", "w+");
	i = 0;
	ret = 0;
	filler->y = ft_atoi(line + 6);
	filler->x = ft_atoi(line + 6 + ft_getdigits(filler->y) + 1);
	free(line);
	filler->piece = malloc(sizeof(char) * (filler->y) * (filler->x + 1) + 1);
	filler->piece[filler->y * (filler->x + 1)] = '\0';
	temp = filler->piece;
	while (i < filler->y)
	{
		get_next_line(0, &line);
		fprintf(checker, "line: %s\n", line);
		filler->piece = ft_strcpy(filler->piece, line);
		filler->piece[filler->x + 1] = '\n';
		filler->piece += filler->x + 1;
		i++;
	}
	//get_next_line(0, &line);
	filler->piece = temp;
}
/*
void					get_piece(t_filler *filler, char *line)
{
	int					i;
	int					x;
	int					y;

	x = ft_atoi(line + 6);
	y = ft_atoi(line + 6 + ft_getdigits(filler->x) + 1);
	free(line);
	filler->xpiece = malloc(sizeof(int) * x * y);
	filler->ypiece = malloc(sizeof(int) * x * y);
	while (i < y)
	{
		get_next_line(FD, &line);

		i++;
	}
}*/