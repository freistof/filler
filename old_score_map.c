/*int			*score_map(t_filler *filler, int i, int score)
{
	if (i < 0 || i >= filler->mapsize)
		return (filler->score);
	if (filler->map[i] == filler->enemy)
	{
		filler->score[i] = 0;
		score = 0;
	}
	if (filler->score[i] == -1)
		filler->score[i] = score;
	if (define_y(filler, i) == define_y(filler, i - 1) && filler->score[i - 1] == -1)
		filler->score = score_map(filler, i - 1, score + 1);
	if (i - filler->mapx >= 0 && filler->score[i - filler->mapx] == -1)
		filler->score = score_map(filler, i - filler->mapx, score + 1);
	return (filler->score);
}

int			*score_map_two(t_filler *filler, int i, int score)
{
	if (i < 0 || i >= filler->mapsize)
		return (filler->score);
	if (filler->map[i] == filler->enemy)
	{
		filler->score[i] = 0;
		score = 0;
	}
	if (filler->score[i] == -1)
		filler->score[i] = score;
	if (define_y(filler, i) == define_y(filler, i + 1) && filler->score[i + 1] == -1)
		filler->score = score_map_two(filler, i + 1, score + 1);
	if (i + filler->mapx <= filler->mapsize && filler->score[i + filler->mapx] == -1)
		filler->score = score_map_two(filler, i + filler->mapx, score + 1);
	return (filler->score);
}

int			*score_map_three(t_filler *filler, int i, int score)
{
	if (i < 0 || i >= filler->mapsize)
		return (filler->score);
	if (filler->map[i] == filler->enemy)
	{
		filler->score[i] = 0;
		score = 0;
	}
	if (filler->score[i] == -1)
		filler->score[i] = score;
	if (define_y(filler, i) == define_y(filler, i - 1) && filler->score[i - 1] == -1)
		filler->score = score_map_three(filler, i - 1, score + 1);
	if (i + filler->mapx <= filler->mapsize && filler->score[i + filler->mapx] == -1)
		filler->score = score_map_three(filler, i + filler->mapx, score + 1);
	return (filler->score);
}

int			*score_map_four(t_filler *filler, int i, int score)
{
	if (i < 0 || i >= filler->mapsize)
		return (filler->score);
	if (filler->map[i] == filler->enemy)
	{
		filler->score[i] = 0;
		score = 0;
	}
	if (filler->score[i] == -1)
		filler->score[i] = score;
	if (define_y(filler, i) == define_y(filler, i + 1) && filler->score[i + 1] == -1)
		filler->score = score_map_four(filler, i + 1, score + 1);
	if (i - filler->mapx <= filler->mapsize && filler->score[i - filler->mapx] == -1)
		filler->score = score_map_four(filler, i - filler->mapx, score + 1);
	return (filler->score);
}*/