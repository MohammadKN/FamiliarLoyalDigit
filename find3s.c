#include <unistd.h>
#include <stdlib.h>

void	findView3(int game[4][4], int rowID, int colID, int *is3);
void	checkRowCol(int game[4][4], int rowID, int colID, int num, int *exist);

void	process_row_1(int game[4][4], int *count)
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
	while (++i <= 3)
	{
		*is3 = 0;
		if (game[0][i] == 0)
		{
			findView3(game, 0, i, is3);
			if (!*is3)
			{
				checkRowCol(game, 0, i, 3, exist);
				if (!*exist)
				{
					rowID = 0;
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

void	process_row_3(int game[4][4], int *count)
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
	while (++i <= 3)
	{
		*is3 = 0;
		if (game[3][i] == 0)
		{
			findView3(game, 3, i, is3);
			if (!*is3)
			{
				checkRowCol(game, 3, i, 3, exist);
				if (!*exist)
				{
					rowID = 3;
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

void	process_col_0(int game[4][4], int *count)
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
	while (++i <= 3)
	{
		*is3 = 0;
		if (game[i][0] == 0)
		{
			findView3(game, i, 0, is3);
			if (!*is3)
			{
				checkRowCol(game, i, 0, 3, exist);
				if (!*exist)
				{
					rowID = i;
					colID = 0;
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

void	process_col_3(int game[4][4], int *count)
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
	while (++i <= 3)
	{
		*is3 = 0;
		if (game[i][3] == 0)
		{
			findView3(game, i, 3, is3);
			if (!*is3)
			{
				checkRowCol(game, i, 3, 3, exist);
				if (!*exist)
				{
					rowID = i;
					colID = 3;
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

void	find3s(int game[4][4], int *count)
{
	while (*count < 4)
	{
		process_row_1(game, count);
		process_row_3(game, count);
		process_col_0(game, count);
		process_col_3(game, count);
	}
}

void	findView3(int game[4][4], int rowID, int colID, int *is3)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (game[rowID][i] == 3)
			*is3 = 1;
		if (game[i][colID] == 3)
			*is3 = 1;
		i++;
	}
}

void	checkRowCol(int game[4][4], int rowID, int colID, int num, int *exist)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (game[rowID][i] == num)
			*exist = 1;
		if (game[i][colID] == num)
			*exist = 1;
		i++;
	}
}

int isValidInput(int argc, char *argv[]) {
    if (argc != 17) {
        return 0;
    }

    for (int i = 1; i < 17; i++) {
        if (argv[i][0] == '\0' || argv[i][1] != '\0') {
            return 0;
        }
        if (argv[i][0] < '1' || argv[i][0] > '4') {
            return 0;
        }
    }
    return 1;
}

void fill_views(int views[4][4], char *argv[]) {
    int k = 1;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            views[i][j] = argv[k++][0] - '0';
        }
    }
}

int solve(int game[4][4], int views[4][4]) {
    int count = 0;
    find3s(game, &count);
    return 1;
}

void print_grid(int grid[4][4]) {
    char c;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            c = grid[i][j] + '0';
            write(1, &c, 1);
            if (j < 3)
                write(1, " ", 1);
        }
        write(1, "\n", 1);
    }
}

int main(int argc, char *argv[]) {
    int views[4][4];
    int game[4][4];

    if (!isValidInput(argc, argv)) {
        write(1, "Error\n", 6);
        return 1;
    }

    fill_views(views, argv);

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            game[i][j] = 0;
        }
    }

    if (solve(game, views)) {
        print_grid(game);
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}