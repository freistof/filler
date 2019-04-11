
#include "filler.h"

char				*fill_map(char *map, int y, int x)
{
	int		i;
	char	*line;
	char 	*temp;

	temp = map;
	i = 0;
	get_next_line(0, &line);
	free (line);
	while (i < y)
	{
		get_next_line(STDIN_FILENO, &line);
		map = ft_strcpy(map, line + 4);
		map[x] = '\n';
		map += x + 1;
		i++;
		free(line);
	}
	return (temp);
}

char				*get_map(t_filler *filler, char *line)
{
	char	*map;

	filler->mapy = ft_atoi(line + 8);
	filler->mapx = ft_atoi(line + 8 + ft_getdigits(filler->mapy) + 1);
	map = malloc(sizeof(char) * (filler->mapy) * (filler->mapx + 1) + 1);
	map[(filler->mapy) * (filler->mapx + 1)] = '\0';
	map = fill_map(map, filler->mapy, filler->mapx);
	return (map);
}
