
#include "filler.h"

char				*fill_map(char *map, int y, int x)
{
	int		i;
	char	*line;
	char 	*temp;

	temp = map;
	i = 0;
	get_next_line(FD, &line);
	free (line);
	while (i < y - 1)
	{
		get_next_line(FD, &line);
		map = ft_strcpy(map, line + 4);
		map[x] = '\n';
		if (i != y - 2)
			map += x + 1;
		i++;
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
	FILE *fileno = fopen("testwrite", "w+");
	fprintf(fileno, "%s\n", map);
	return (map);
}
