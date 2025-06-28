#include <unistd.h>

int	is_valid_placement(int grid[4][4], int row, int col, int num);
int	check_views(int grid[4][4], int views[16]);

int	solve_recursive(int grid[4][4], int views[16], int pos)
{
	int	row;
	int	col;
	int	num;

	if (pos == 16)
		return (check_views(grid, views));
	row = pos / 4;
	col = pos % 4;
	num = 1;
	while (num <= 4)
	{
		if (is_valid_placement(grid, row, col, num))
		{
			grid[row][col] = num;
			if (solve_recursive(grid, views, pos + 1))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

#include <stdlib.h>



int	check_views(int grid[4][4], int views[16])
{
	int	i;
	int	j;
	int	count;
	int	max_height;

	i = 0;
	while (i < 4)
	{
		count = 0;
		max_height = 0;
		j = 0;
		while (j < 4)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				count++;
			}
			j++;
		}
		if (count != views[i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		count = 0;
		max_height = 0;
		j = 0;
		while (j < 4)
		{
			if (grid[j][i] > max_height)
			{
				max_height = grid[j][i];
				count++;
			}
			j++;
		}
		if (count != views[4 + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		count = 0;
		max_height = 0;
		j = 3;
		while (j >= 0)
		{
			if (grid[i][j] > max_height)
			{
				max_height = grid[i][j];
				count++;
			}
			j--;
		}
		if (count != views[8 + i])
			return (0);
		i++;
	}
	i = 0;
	while (i < 4)
	{
		count = 0;
		max_height = 0;
		j = 3;
		while (j >= 0)
		{
			if (grid[j][i] > max_height)
			{
				max_height = grid[j][i];
				count++;
			}
			j--;
		}
		if (count != views[12 + i])
			return (0);
		i++;
	}
	return (1);
}

int	parse_views(char *arg, int views[16])
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arg[i])
	{
		if (arg[i] >= '1' && arg[i] <= '4')
		{
			views[j] = arg[i] - '0';
			j++;
		}
		else if (arg[i] != ' ')
			return (0);
		i++;
	}
	if (j != 16)
		return (0);
	return (1);
}