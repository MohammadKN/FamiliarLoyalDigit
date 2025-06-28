#include <unistd.h>

int	count_visible_left(int grid[4][4], int row)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_right(int grid[4][4], int row)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[row][i] > max_height)
		{
			max_height = grid[row][i];
			count++;
		}
		i--;
	}
	return (count);
}

int	count_visible_top(int grid[4][4], int col)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 0;
	while (i < 4)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			count++;
		}
		i++;
	}
	return (count);
}

int	count_visible_bottom(int grid[4][4], int col)
{
	int	count;
	int	max_height;
	int	i;

	count = 0;
	max_height = 0;
	i = 3;
	while (i >= 0)
	{
		if (grid[i][col] > max_height)
		{
			max_height = grid[i][col];
			count++;
		}
		i--;
	}
	return (count);
}

int	check_views(int grid[4][4], int views[16])
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (count_visible_top(grid, i) != views[i])
			return (0);
		if (count_visible_bottom(grid, i) != views[i + 4])
			return (0);
		if (count_visible_left(grid, i) != views[i + 8])
			return (0);
		if (count_visible_right(grid, i) != views[i + 12])
			return (0);
		i++;
	}
	return (1);
}