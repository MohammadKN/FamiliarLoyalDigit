
#include <stdio.h>
#include <unistd.h>

void	findView3(int game[6][6], int rowID, int colID, int *is3)
{
	if (game[0][colID] == 3 && rowID == 1)
		*is3 = 1;
	if (game[5][colID] == 3 && rowID == 4)
		*is3 = 1;
	if (game[rowID][0] == 3 && colID == 1)
		*is3 = 1;
	if (game[rowID][5] == 3 && colID == 4)
		*is3 = 1;
}

void	match_3_1_top_bottom(int game[6][6], int *count)
{
	int	i;

	i = 1;
	while (i++ <= 4)
	{
		if (game[0][i] == 2)
		{
			if (game[5][i] == 1)
				game[1][i] = 3;
			else if (game[5][i] == 3)
				game[2][i] = 4;
			(*count)++;
		}
	}
	i = 1;
	while (i++ <= 4)
	{
		if (game[5][i] == 2)
		{
			if (game[0][i] == 1)
				game[4][i] = 3;
			else if (game[0][i] == 3)
				game[3][i] = 4;
			(*count)++;
		}
	}
}

void	match_3_1_left_right(int game[6][6], int *count)
{
	int	i;

	i = 1;
	while (i++ <= 4)
	{
		if (game[i][0] == 2)
		{
			if (game[i][5] == 1)
				game[i][1] = 3;
			else if (game[i][5] == 3)
				game[i][2] = 4;
			(*count)++;
		}
	}
	i = 1;
	while (i++ <= 4)
	{
		if (game[i][5] == 2)
		{
			if (game[i][0] == 1)
				game[i][4] = 3;
			else if (game[i][0] == 3)
				game[i][3] = 4;
			(*count)++;
		}
	}
}

void	match_3_1(int game[6][6], int *count)
{
	match_3_1_top_bottom(game, count);
	match_3_1_left_right(game, count);
}
