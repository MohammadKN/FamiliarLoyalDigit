
#include <stdio.h>
#include <unistd.h>

void	fillView4(int game[6][6], int x, int y, int direction, int *count)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (direction == 0)
		while (++i < 5)
			game[i][y] = i;
	else if (direction == 1)
		while (++j < 5)
			game[x][j] = j;
	else if (direction == 2)
	{
		j = 5;
		while (--j > 0)
			game[x][j] = 5 - j;
	}
	else if (direction == 3)
	{
		i = 5;
		while (--i > 0)
			game[i][y] = 5 - i;
	}
	(*count)++;
}

void	findView4(int game[6][6], int *count)
{
	int	i;

	i = 0;
	while (i++ <= 4)
		if (game[0][i] == 4)
			fillView4(game, 0, i, 0, count);
	i = 0;
	while (i++ <= 4)
		if (game[5][i] == 4)
			fillView4(game, 5, i, 3, count);
	i = 0;
	while (i++ <= 4)
		if (game[i][0] == 4)
			fillView4(game, i, 0, 1, count);
	i = 0;
	while (i++ <= 4)
		if (game[i][5] == 4)
			fillView4(game, i, 5, 2, count);
}

void	findView1(int game[6][6])
{
	int	i;

	i = 0;
	while (i++ <= 4)
		if (game[0][i] == 1)
			game[1][i] = 4;
	i = 1;
	while (i++ <= 4)
		if (game[5][i] == 1)
			game[4][i] = 4;
	i = 1;
	while (i++ <= 4)
		if (game[i][0] == 1)
			game[i][1] = 4;
	i = 1;
	while (i++ <= 4)
		if (game[i][5] == 1)
			game[i][4] = 4;
}
