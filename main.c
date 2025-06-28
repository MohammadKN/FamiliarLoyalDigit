#include <stdio.h>
#include <unistd.h>

void	fillView4 (int	game[6][6], int x, int y, int direction, int *count) {
	int i = 0;
	int j = 0;

	
	if(direction == 0)
		while (++i < 5)
			game[i][y] = i;	
	else if(direction == 1)
		while (++j < 5)
			game[x][j] = j;
	else if(direction == 2)
	{
		j = 5;
		while (--j > 0)
			game[x][j] = 5 - j;
	}
	else if(direction == 3)
		{
		i = 5; 
		while (--i > 0)
			game[i][y] = 5 - i;
		}
		
	count++;
}

void	findView4 (int game[6][6], int *count)
{
	int i = 0;
	while (i++ <= 4)
		if (game[0][i] == 4)
			fillView4(game, 0, i, 0, count);
	i = 0;
	while (i++ <= 4)
		if (game[5][i] == 4)
			fillView4(game, 5, i, 3, count);
	i = 0;
	while (i++ <= 4)
		if (game[i][0] == 4)
			fillView4(game, i, 0, 1, count);
	i = 0;
	while (i++ <= 4)
		if (game[i][5] == 4)
			fillView4(game, i, 5, 2, count);
}

	
void	findView1(int game[6][6]){

	int i = 0;
	while ( i++ <= 4){
		if (game[0][i] == 1){
			game[1][i] = 4;
		}
		
	}

	i = 1;
	while ( i++ <= 4){
		if (game[5][i] == 1){
			game[4][i] = 4;
		}	
	}

	i = 1;
	while ( i++ <= 4){
		if (game[i][0] == 1){
			game[i][1] = 4;
		}
	}

	i = 1;
	while ( i++ <= 4){
		if (game[i][5] == 1){
			game[i][4] = 4;
		}	
	}

}

void	findView3(int game[6][6], int rowID, int colID, int *is3){
	
	if (game[0][colID] == 3 && rowID == 1){
		*is3 = 1; 
	}
	if (game[5][colID] == 3 && rowID == 4){
		*is3 = 1;
	}
	if (game[rowID][0] == 3 && colID == 1){
		*is3 = 1;
	}
	if (game[rowID][5] == 3 && colID == 4){
		*is3 = 1;
	}
	

}
void	match_3_1(int game[6][6], int *count){
	int i = 1;
	while ( i++ <= 4){
		if (game[0][i] == 2){
			if(game[5][i] == 1)
				game[1][i] = 3;
			else if(game[5][i] == 3)
				game[2][i] = 4;
			count++;
		}
	}

	i = 1;
	while ( i++ <= 4){
		if (game[5][i] == 2){
			if(game[0][i] == 1)
				game[4][i] = 3;
			else if(game[0][i] == 3)
				game[3][i] = 4;
			count++;
		}	
	}

	i = 1;
	while ( i++ <= 4){
		if (game[i][0] == 2){
			if(game[i][5] == 1)
				game[i][1] = 3;
			else if(game[i][5] == 3)
				game[i][2] = 4;
		count++;
		}
	}

	i = 1;
	while ( i++ <= 4){
		if (game[i][5] == 2){
			if(game[i][0] == 1)
				game[i][4] = 3;
			else if(game[i][0] == 3)
				game[i][3] = 4;
		count++;
		}	
	}

}



void	checkRowCol(int	game[6][6], int rowID, int colID, int num, int *exist){
	int i;

	i = 1;
	while(i<5){
		if(game[rowID][i] == num){
			*exist = 1;
			break;
		}
		i++;
	}
	i = 1;
	while(i<5){
		if(game[i][colID] == num){
			*exist = 1;
			break;
		}
		i++;
	}
}

void	find3s (int game[6][6], int rowID, int colID, int *count)
{
	int x;
	int *is3;
	int y;
	int *exist;
	int possible;
	possible = 0;
	is3 = &x;
	exist = &y;
	
	while(*count < 4){
	int i = 0; 
	while (++i <= 4){
		*is3 = 0;
		if (game[1][i] == 0){
			findView3(game, 1, i,  is3);
			if(!*is3){
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
	if(possible == 1)
	{
		game[rowID][colID] = 3;
		count++;
	}
	possible = 0;
	i = 1;
	while ( i++ <= 4){
		*is3 = 0;
		if (game[4][i] == 0){
			findView3(game, 4, i,  is3);
			if(!*is3){
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
	if(possible == 1)
	{
		game[rowID][colID] = 3;
		count++;
	}
	possible = 0;
	i = 1;
	while ( i++ <= 4){
		*is3 = 0;
		if (game[i][1] == 0){
			findView3(game, i, 1,  is3);
			if(!*is3){
				printf("3.\n");
				checkRowCol(game, i, 1, 3, exist);
				if (!*exist)
				{
					printf("3\n");
					rowID = i;
					colID = 1;
					possible++;
				}
				*exist = 0;
			}
		}
	}

	if(possible == 1)
	{
		game[rowID][colID] = 3;
		count++;
	}
	possible = 0;
	i = 1;
	while ( i++ <= 4){
		*is3 = 0;
		if (game[i][4] == 0){
			findView3(game, i, 4,  is3);
			if(!*is3){
				printf("4\n");
				checkRowCol(game, i, 4, 3, exist);
				if (!*exist)
				{
					printf("4\n");
					rowID = i;
					colID = 4;
					possible++;
				}
				*exist = 0;
			}
		}
	}
	if(possible == 1){
		game[rowID][colID] = 3;
		count++;
	}
	possible = 0;
	}
}

void	find(int	game[6][6], int num){
	int i =1;
	int j;
	int does_3_exist=0;
	int no_of_unfilled_3s=0;
	int row = 0;
	int column = 0;
	
	while(i<5){
		j = 1;
		does_3_exist = 0;
		while(j<5)
		{
			if(game[j][i] == num){
				does_3_exist = 1;
				break;
			}
			j++;
		}
		if(!does_3_exist){
			no_of_unfilled_3s++;
			row = i;
		}
		i++;
	}
	if(no_of_unfilled_3s == 1){
		i = 1;
		while(i<5)
		{
			j = 1;
			does_3_exist = 0;
			while(j<5)
			{
				if(game[i][j] == num){
					does_3_exist = 1;
					break;
				}
				j++;
			}
			if(!does_3_exist){
				column = i;
			}
			i++;
		}
		game[column][row] = num;
	}
		
}

int	fillGaps(int	game[6][6]){
	int i;
	int j;
	int sum;
	int no_of_gaps = 0;
	int did_change = 0;

	// search for a single gap, keep track of sum, missing number
	// will alwyas be 10 - sum in a single column.
	i =	1;
	while(i < 5){
		j = 1;
		sum = 0;
		no_of_gaps = 0;
		while(j<5)
		{
			if(game[i][j] ==0){
				no_of_gaps++;
			}
			sum+=game[i][j];
			j++;
		}
		if(no_of_gaps==1){
			j = 1;
			while(j<5)
			{
				if(game[i][j] ==0){
					game[i][j] = 10 - sum;
					did_change = 1;
				}
				j++;
			}
		}
		i++;
	}
	// do the same for rows now
	i =	1;
	while(i< 5){
		j = 1;
		sum = 0;
		no_of_gaps = 0;
		while(j<5)
		{
			if(game[j][i] ==0){
				no_of_gaps++;
			}
			sum+=game[j][i];
			j++;
		}
		if(no_of_gaps==1){
			j = 1;
			while(j<5)
			{
				if(game[j][i] == 0){
					game[j][i] = 10 - sum;
					did_change = 1;
				}
				j++;
			}
		}
		i++;
	}
	return did_change;
}

void	solve(int game[6][6])
{
        int     i;
        int     j;
	int changed;
	int count = 0;
	findView4(game, &count);
    	findView1(game);
	find(game, 4);
	match_3_1(game, &count);
	find3s(game, 0, 0, &count);
	find(game, 3);
	
	changed = 1;
	
	while(changed){
		changed = 0;
		if(fillGaps(game))
			changed = 1;
	}
		
	i = 0;
	while(i<6)
	{
		j = 0;
		while (j<6)
                {
                        printf("%d ", game[i][j]);
                        j++;
                }
                printf("\n");
                i++;
        }
}

void initializeGame(int views[16], int game[6][6]){
        int     i;
        int     j;
	

        i = 0;
	while(i<6)
	{
        	j = 0;
		while (j<6)
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
			game[0][i+1] = views[i];
		else if (i < 8)
			game[5][i-3] = views[i];
		else if (i < 12)
			game[i-7][0] = views[i];
		else if  (i < 16)
			game[i-11][5] = views[i];
		i++;
	}
}
	
int main(int argc, char **argv) 
{

	// if (argc != 2)
	// {
	// 	write(2, "Error\n", 6);
	// 	return (1);
	// }
	int	rowColCapacity[8]= {0, 0, 0, 0, 0, 0, 0, 0};
	int i;
	int j;
	int views[16] = {3,2,3,1,2,3,1,2,3,2,1,2,1,2,3,2};
	int game[6][6];
	i = 0;
	j = 0; 
	// while (i < 16)
	// {
	// 	views[i] = argv[1][j] - 48;
	// 	i++;
	// 	j += 2;
	// }
	
	initializeGame(views, game);
	solve(game);
}