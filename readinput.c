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


/*
** get_player determines the player according to the what's
** written on the stdout
*/

char		get_player(char *buf)
{
	if (buf[10] == '2' || buf[6] == 'O')
		return ('X');
	else
		return ('O');
}

/*
** This function reads the map from the STDIN and saves it in variable map
** This is a string without newlines
*/

/*static char			*create_map(int fd, t_info *coor) 				
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
}*/

/*
** readinput gets the coordinates from the first line of the STDIN
*/

void				readinput(t_info *coor)
{
	int		ret;
	int		fd;
	char	player;
	char	*buf;

	ret = 1;
	fd = open("test", O_RDONLY);
	fd = STDIN_FILENO;
	player = 'X';
	while (ret)
	{
		ret = get_next_line(fd, &buf);
		if (ft_strlen(buf) == 0)
			break ;
		if (buf && buf[0] == '$')
			player = get_player(buf);
		if (buf && buf[0] == '<')
			player = get_player(buf);
		if (ret)
			free(buf);
	}
	if (player == 'X')
	{
		coor->x = 14;
		coor->y = 12;
	}
	else
	{
		coor->x = 2;
		coor->y = 8;
	}
	printf("%i %i\n", coor->x, coor->y);
	return ;
}
