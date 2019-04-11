
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
	filler->mapy = ft_atoi(line + 8);
	filler->mapx = ft_atoi(line + 8 + ft_getdigits(filler->mapy) + 1);
	free (line);
	filler->map = malloc(sizeof(char) * (filler->mapy) * (filler->mapx + 1) + 1);
	filler->map[(filler->mapy) * (filler->mapx + 1)] = '\0';
	filler->map = fill_map(filler->map, filler->mapy, filler->mapx);
	return (filler->map);
}
