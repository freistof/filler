int				filler_enemy(t_filler *filler, char c)
{
	if (c == filler->enemy || filler->enemy + 32)
		return (1);
	return (0);
}

int				define_y(t_filler *filler, int i)
{
	return (i / filler->mapx);
}

void		make_score_map(t_filler *filler, int i, int score, int *dir)
{
	if (i < 0 || i >= filler->mapsize)
		return ;
	if (filler->map[i] == filler->enemy)
	{
		filler->score[i] = 0;
		score = 0;
	}
	if (filler->score[i] == -1)
		filler->score[i] = score;
	if (define_y(filler, i) == define_y(filler, i + dir[0]) && filler->score[i + dir[0]] == -1)
		make_score_map(filler, i + dir[0], score + 1, dir);
	if (i + dir[1] >= 0 && filler->score[i + dir[1]] == -1)
		make_score_map(filler, i + dir[1], score + 1, dir);
}

void		four_directions_map(t_filler *filler, int i)
{
	int		dir[2];

	dir[0] = -1;
	dir[1] = -filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = +1;
	dir[1] = +filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = -1;
	dir[1] = +filler->mapx;
	make_score_map(filler, i, 0, dir);
	dir[0] = 1;
	dir[1] = -filler->mapx;
	make_score_map(filler, i, 0, dir);
}
