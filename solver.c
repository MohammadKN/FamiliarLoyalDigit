
#include <stdio.h>
#include <unistd.h>

void	findView4(int game[6][6], int *count);
void	findView1(int game[6][6]);
void	find(int game[6][6], int num);
void	match_3_1(int game[6][6], int *count);
void	find3s(int game[6][6], int rowID, int colID, int *count);
int	fillGaps(int game[6][6]);

void	solve(int game[6][6])
{
	int	i;
	int	j;
	int	changed;
	int	count;

	count = 0;
	findView4(game, &count);
	findView1(game);
	find(game, 4);
	match_3_1(game, &count);
	find3s(game, 0, 0, &count);
	find(game, 3);
	changed = 1;
	while (changed)
	{
		changed = 0;
		if (fillGaps(game))
			changed = 1;
	}
	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
		{
			printf("%d ", game[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
