/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   readinput.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/08 14:10:13 by fblom         #+#    #+#                 */
/*   Updated: 2019/04/08 14:10:13 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void			find_first_coor(t_info *coor, char *map, char player)
{
	int		i;

	i = 0;
	ft_putnbr_fd(3, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(3, 1);
	ft_putchar_fd('\n', 1);
	return ;
	while (map[i] != '\0')
	{
		if (map[i] == player)
		{
			ft_putnbr_fd(i % coor->x, STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
			ft_putnbr_fd(i / coor->x, STDOUT_FILENO);
			ft_putchar_fd('\n', STDOUT_FILENO);
			break ;
		}
		i++;
	}

}

/*
** This function reads the map from the STDIN and saves it in variable map
** This is a string without newlines
*/

static char			*create_map(int fd, t_info *coor) 				
{
	int		i;
	char	*map;
	char	*line;

	i = 0;
	map = ft_strnew(coor->x * coor->y * coor->y);
	get_next_line(fd, &line);
	while (i < coor->y)
	{
		get_next_line(fd, &line);
		map = ft_strcat(map, line + 4);
		i++;
	}
	return (map);
}

/*
** readinput gets the coordinates from the first line of the STDIN
*/

void				readinput(t_info *coor)
{
	char	*line;
	char	*map;
	int		fd;
	char	player;

	fd = STDIN_FILENO;
	fd = open("test", O_RDONLY);
	for (int i = 0; i < 9; i++)
		get_next_line(fd, &line);
	get_next_line(fd, &line);
	player = 'O';
	coor->y = ft_atoi(line + 8);
	coor->x = ft_atoi(line + 8 + ft_getdigits(coor->x) + 1);
	free (line);
	map = create_map(fd, coor);
	find_first_coor(coor, map, player);
	return ;
}
