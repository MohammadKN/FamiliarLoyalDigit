#include <unistd.h>
#include <stdlib.h>

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

int check_row(int grid[4][4], int row, int value) {
    for (int i = 0; i < 4; i++) {
        if (grid[row][i] == value)
            return 0;
    }
    return 1;
}

int check_col(int grid[4][4], int col, int value) {
    for (int i = 0; i < 4; i++) {
        if (grid[i][col] == value)
            return 0;
    }
    return 1;
}

int is_valid(int grid[4][4], int row, int col, int value) {
    return check_row(grid, row, value) && check_col(grid, col, value);
}

int solve(int grid[4][4], int *clues, int position) {
    if (position == 16)
        return 1;

    int row = position / 4;
    int col = position % 4;

    for (int value = 1; value <= 4; value++) {
        if (is_valid(grid, row, col, value)) {
            grid[row][col] = value;

            if (solve(grid, clues, position + 1))
                return 1;

            grid[row][col] = 0; // Backtrack
        }
    }

    return 0;
}

int check_views(int grid[4][4], int *clues) {
    int i, j, count, max_height;

    // Check top views
    for (i = 0; i < 4; i++) {
        count = 0;
        max_height = 0;
        for (j = 0; j < 4; j++) {
            if (grid[j][i] > max_height) {
                max_height = grid[j][i];
                count++;
            }
        }
        if (count != clues[i])
            return 0;
    }

    // Check bottom views
    for (i = 0; i < 4; i++) {
        count = 0;
        max_height = 0;
        for (j = 3; j >= 0; j--) {
            if (grid[j][i] > max_height) {
                max_height = grid[j][i];
                count++;
            }
        }
        if (count != clues[4 + i])
            return 0;
    }

    // Check left views
    for (i = 0; i < 4; i++) {
        count = 0;
        max_height = 0;
        for (j = 0; j < 4; j++) {
            if (grid[i][j] > max_height) {
                max_height = grid[i][j];
                count++;
            }
        }
        if (count != clues[8 + i])
            return 0;
    }

    // Check right views
    for (i = 0; i < 4; i++) {
        count = 0;
        max_height = 0;
        for (j = 3; j >= 0; j--) {
            if (grid[i][j] > max_height) {
                max_height = grid[i][j];
                count++;
            }
        }
        if (count != clues[12 + i])
            return 0;
    }

    return 1;
}

int main(int argc, char **argv) {
    if (argc != 2) {
        write(1, "Error\n", 6);
        return 1;
    }

    int clues[16];
    int grid[4][4] = {0};
    char *input = argv[1];
    int i = 0, j = 0;

    // Parse input clues
    while (input[i]) {
        if (input[i] >= '1' && input[i] <= '4') {
            clues[j++] = input[i] - '0';
        } else if (input[i] != ' ') {
            write(1, "Error\n", 6);
            return 1;
        }
        i++;
    }

    if (j != 16) {
        write(1, "Error\n", 6);
        return 1;
    }

    if (solve(grid, clues, 0)) {
        if (check_views(grid, clues))
        	print_grid(grid);
        else
        	write(1, "Error\n", 6);
    } else {
        write(1, "Error\n", 6);
    }

    return 0;
}