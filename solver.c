
#include <unistd.h>

void	init_grid(int grid[4][4]);
int		is_valid_placement(int grid[4][4], int row, int col, int num);
int		check_views(int grid[4][4], int views[16]);
int		solve_recursive(int grid[4][4], int views[16], int pos);
void	print_grid(int grid[4][4]);
void	print_error(void);

void	init_grid(int grid[4][4])
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			grid[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	is_valid_placement(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

void	solve(int grid[4][4], int views[16])
{
	init_grid(grid);
	if (!solve_recursive(grid, views, 0))
		print_error();
	else
		print_grid(grid);
}
