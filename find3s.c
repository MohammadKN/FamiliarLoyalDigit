
#include <stdio.h>
#include <unistd.h>

void	findView3(int game[6][6], int rowID, int colID, int *is3);
void	checkRowCol(int game[6][6], int rowID, int colID, int num, int *exist);

void	process_row_1(int game[6][6], int *count)
{
	int	i;
	int	x;
	int	y;
	int	*is3;
	int	*exist;
	int	possible;
	int	rowID;
	int	colID;

	is3 = &x;
	exist = &y;
	possible = 0;
	i = 0;
	while (++i <= 4)
	{
		*is3 = 0;
		if (game[1][i] == 0)
		{
			findView3(game, 1, i, is3);
			if (!*is3)
			{
				checkRowCol(game, 1, i, 3, exist);
				if (!*exist)
				{
					rowID = 1;
					colID = i;
					possible++;
				}
				*exist = 0;
			}
		}
	}
	if (possible == 1)
	{
		game[rowID][colID] = 3;
		(*count)++;
	}
}

void	process_row_4(int game[6][6], int *count)
{
	int	i;
	int	x;
	int	y;
	int	*is3;
	int	*exist;
	int	possible;
	int	rowID;
	int	colID;

	is3 = &x;
	exist = &y;
	possible = 0;
	i = 1;
	while (i++ <= 4)
	{
		*is3 = 0;
		if (game[4][i] == 0)
		{
			findView3(game, 4, i, is3);
			if (!*is3)
			{
				checkRowCol(game, 4, i, 3, exist);
				if (!*exist)
				{
					rowID = 4;
					colID = i;
					possible++;
				}
				*exist = 0;
			}
		}
	}
	if (possible == 1)
	{
		game[rowID][colID] = 3;
		(*count)++;
	}
}

void	process_col_1(int game[6][6], int *count)
{
	int	i;
	int	x;
	int	y;
	int	*is3;
	int	*exist;
	int	possible;
	int	rowID;
	int	colID;

	is3 = &x;
	exist = &y;
	possible = 0;
	i = 1;
	while (i++ <= 4)
	{
		*is3 = 0;
		if (game[i][1] == 0)
		{
			findView3(game, i, 1, is3);
			if (!*is3)
			{
				checkRowCol(game, i, 1, 3, exist);
				if (!*exist)
				{
					rowID = i;
					colID = 1;
					possible++;
				}
				*exist = 0;
			}
		}
	}
	if (possible == 1)
	{
		game[rowID][colID] = 3;
		(*count)++;
	}
}

void	process_col_4(int game[6][6], int *count)
{
	int	i;
	int	x;
	int	y;
	int	*is3;
	int	*exist;
	int	possible;
	int	rowID;
	int	colID;

	is3 = &x;
	exist = &y;
	possible = 0;
	i = 1;
	while (i++ <= 4)
	{
		*is3 = 0;
		if (game[i][4] == 0)
		{
			findView3(game, i, 4, is3);
			if (!*is3)
			{
				checkRowCol(game, i, 4, 3, exist);
				if (!*exist)
				{
					rowID = i;
					colID = 4;
					possible++;
				}
				*exist = 0;
			}
		}
	}
	if (possible == 1)
	{
		game[rowID][colID] = 3;
		(*count)++;
	}
}

void	find3s(int game[6][6], int rowID, int colID, int *count)
{
	while (*count < 4)
	{
		process_row_1(game, count);
		process_row_4(game, count);
		process_col_1(game, count);
		process_col_4(game, count);
	}
}
