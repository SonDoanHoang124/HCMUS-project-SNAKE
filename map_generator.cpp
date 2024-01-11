#include "console_handle.cpp"
#include "header.h"

#define GRID_SIZE 20
#define NUM_OBSTACLES_LV_1 int(15)
#define NUM_OBSTACLES_LV_2 int(22)
#define NUM_OBSTACLES_LV_3 int(30)

void initialize_grid(char grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (i == 0 || i == GRID_SIZE - 1 || j == 0 || j == GRID_SIZE - 1)
                grid[i][j] = '#';
            else
                grid[i][j] = ' ';
        }
    }
}

void print_grid(char grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) 
        {
            go_to_xy(i, j);
            if (grid[i][j] == 'O')
                text_color(BLACK, YELLOW);
            std::cout << grid[i][j];
            text_color(BLACK, WHITE);
        }
    }
    //go_to_xy(0, 0);
}

bool has_dead_end(char grid[][GRID_SIZE], int x, int y) {
    int count = 0;

    if (grid[x - 1][y] == '#') count++;
    if (grid[x + 1][y] == '#') count++;
    if (grid[x][y - 1] == '#') count++;
    if (grid[x][y + 1] == '#') count++;

    if (grid[x - 1][y - 1] == '#' || grid[x + 1][y + 1] == '#') count += 3;
    
    return count >= 3; // Check if there are at least 3 walls surrounding the position
}

bool is_snake_init(int x, int y)
{
    int head_x = GRID_SIZE / 2, head_y = head_x;
    if ((x == head_x && y == head_y) || (x == head_x - 1 && y == head_y) || (x == head_x - 2 && y == head_y) || 
(x == head_x - 3 && y == head_y) || (x == head_x - 4 && y == head_y) || (x == head_x - 5 && y == head_y))
        return 1;
    return 0;
}

void generate_obstacles(char grid[][GRID_SIZE], int num_obstacles) {
    for (int i = 0; i < num_obstacles; ++i) {
        int x, y;
        do {
            x = rand() % (GRID_SIZE - 2) + 1;
            y = rand() % (GRID_SIZE - 2) + 1;
        } while ((grid[x][y] == '#' || has_dead_end(grid, x, y)) && !is_snake_init(x, y));

        grid[x][y] = '#'; // '#' represents an obstacle
    }
}

void generate_food(char grid[][GRID_SIZE])
{
    for (int i = 0; i < MAX_SIZE_FOOD; i++)
    {
        int x, y;
        do 
        {
            x = rand() % (GRID_SIZE - 2) + 1;
            y = rand() % (GRID_SIZE - 2) + 1;
        } while (grid[x][y] == '#' && !is_snake_init(x, y));
        grid[x][y] = 'O';
        
    }
}

void generate_board(char grid[][GRID_SIZE], int num_obstacles)
{
    srand(time(0));
    initialize_grid(grid);
    generate_obstacles(grid, num_obstacles);
    generate_food(grid);
    print_grid(grid);
}
/*
int main()
{
    char grid[GRID_SIZE][GRID_SIZE];
    generate_board(grid, 12);
    system("pause");
    return 0;
}*/