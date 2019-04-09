
#include "filler.h"

static char				*fill_map(char *map, int x, int y)
{
	int		i;
	char	*line;
	char 	*temp;

	temp = map;
	i = 0;
	while (i < y - 1)
	{
		get_next_line(FD, &line);
		map = ft_strcpy(map, line + 4);
		map[x] = '\n';
		map += x + 1;
		i++;
	}
	*map = '\0';
//	printf("map: %s", temp);
	return (temp);
}

char				*get_map(char *line)
{
	int		x;
	int		y;
	char	*map;

	x = ft_atoi(line + 8);
	y = ft_atoi(line + 8 + ft_getdigits(x) + 1);
	map = malloc(sizeof(char) * (x + 1) * y + 1);
	map[(x + 1) * y] = '\0';
	fill_map(map, x, y);
	return (map);
}
