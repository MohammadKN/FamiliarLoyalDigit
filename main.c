
#include <unistd.h>
#include <stdlib.h>

void	solve(int grid[4][4], int views[16]);
int		parse_input(char *str, int views[16]);
void	print_grid(int grid[4][4]);
void	print_error(void);

int	is_digit(char c)
{
	return (c >= '1' && c <= '4');
}

int	parse_input(char *str, int views[16])
{
	int	i;
	int	view_count;

	i = 0;
	view_count = 0;
	while (str[i] && view_count < 16)
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		if (!is_digit(str[i]))
			return (0);
		views[view_count] = str[i] - '0';
		view_count++;
		i++;
		while (str[i] && str[i] != ' ')
		{
			if (str[i] != ' ')
				return (0);
		}
	}
	while (str[i] == ' ')
		i++;
	if (view_count != 16 || str[i])
		return (0);
	return (1);
}

void	print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			if (write(1, &c, 1) == -1)
				return ;
			if (j < 3)
				if (write(1, " ", 1) == -1)
					return ;
			j++;
		}
		if (write(1, "\n", 1) == -1)
			return ;
		i++;
	}
}

void	print_error(void)
{
	if (write(1, "Error\n", 6) == -1)
		return ;
}

int	main(int argc, char **argv)
{
	int	views[16];
	int	grid[4][4];

	if (argc != 2)
	{
		print_error();
		return (1);
	}
	if (!parse_input(argv[1], views))
	{
		print_error();
		return (1);
	}
	solve(grid, views);
	return (0);
}
