
#include <stdio.h>
#include <unistd.h>

void	checkRowCol(int game[6][6], int rowID, int colID, int num, int *exist)
{
	int	i;

	i = 1;
	while (i < 5)
	{
		if (game[rowID][i] == num)
		{
			*exist = 1;
			break ;
		}
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (game[i][colID] == num)
		{
			*exist = 1;
			break ;
		}
		i++;
	}
}

void	find(int game[6][6], int num)
{
	int	i;
	int	j;
	int	does_exist;
	int	no_of_unfilled;
	int	row;
	int	column;

	i = 1;
	does_exist = 0;
	no_of_unfilled = 0;
	row = 0;
	column = 0;
	while (i < 5)
	{
		j = 1;
		does_exist = 0;
		while (j < 5)
		{
			if (game[j][i] == num)
			{
				does_exist = 1;
				break ;
			}
			j++;
		}
		if (!does_exist)
		{
			no_of_unfilled++;
			row = i;
		}
		i++;
	}
	if (no_of_unfilled == 1)
	{
		i = 1;
		while (i < 5)
		{
			j = 1;
			does_exist = 0;
			while (j < 5)
			{
				if (game[i][j] == num)
				{
					does_exist = 1;
					break ;
				}
				j++;
			}
			if (!does_exist)
				column = i;
			i++;
		}
		game[column][row] = num;
	}
}

int	fillGaps(int game[6][6])
{
	int	i;
	int	j;
	int	sum;
	int	no_of_gaps;
	int	did_change;

	did_change = 0;
	i = 1;
	while (i < 5)
	{
		j = 1;
		sum = 0;
		no_of_gaps = 0;
		while (j < 5)
		{
			if (game[i][j] == 0)
				no_of_gaps++;
			sum += game[i][j];
			j++;
		}
		if (no_of_gaps == 1)
		{
			j = 1;
			while (j < 5)
			{
				if (game[i][j] == 0)
				{
					game[i][j] = 10 - sum;
					did_change = 1;
				}
				j++;
			}
		}
		i++;
	}
	i = 1;
	while (i < 5)
	{
		j = 1;
		sum = 0;
		no_of_gaps = 0;
		while (j < 5)
		{
			if (game[j][i] == 0)
				no_of_gaps++;
			sum += game[j][i];
			j++;
		}
		if (no_of_gaps == 1)
		{
			j = 1;
			while (j < 5)
			{
				if (game[j][i] == 0)
				{
					game[j][i] = 10 - sum;
					did_change = 1;
				}
				j++;
			}
		}
		i++;
	}
	return (did_change);
}
