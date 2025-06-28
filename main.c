#include <stdio.h>
#include <unistd.h>

void	solve(int game[6][6]);
void	initializeGame(int views[16], int game[6][6]);

void	initializeGame(int views[16], int game[6][6])
{
	int	i;
	int	j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			game[i][j] = 0;
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 16)
	{
		if (i < 4)
			game[0][i + 1] = views[i];
		else if (i < 8)
			game[5][i - 3] = views[i];
		else if (i < 12)
			game[i - 7][0] = views[i];
		else if (i < 16)
			game[i - 11][5] = views[i];
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	views[16] = {3, 2, 3, 1, 2, 3, 1, 2, 3, 2, 1, 2, 1, 2, 3, 2};
	int	game[6][6];

	initializeGame(views, game);
	solve(game);
	return (0);
}