#include "map_generator.cpp"
/*
#ifndef SNAKE
#define SNAKE
*/
void init_snake()
{
    int init_pos = GRID_SIZE / 2;
    snake[0] = {init_pos, init_pos};
    snake[1] = {init_pos - 1, init_pos};
    snake[2] = {init_pos - 2, init_pos};
    snake[3] = {init_pos - 3, init_pos};
    snake[4] = {init_pos - 4, init_pos};
    snake[5] = {init_pos - 5, init_pos};
}

void draw_snake()
{
    for (int i = 0; i < SIZE_SNAKE; i++)
    {
        go_to_xy(snake[i].x, snake[i].y);
        text_color(BLACK, GREEN);
        std::cout << "0";
        text_color(BLACK, WHITE);
    }
}

void eat()
{
    snake[SIZE_SNAKE] = food[FOOD_IDX];
    if (FOOD_IDX == MAX_SIZE_FOOD - 1)
    {
        FOOD_IDX = 0;
        SIZE_SNAKE = 6;
        if (SPD == MAX_SPEED) SPD = 1;
        else SPD++;
    }
    else
    {
        FOOD_IDX++;
        SIZE_SNAKE++;
    }
}

void process_dead()
{
    ALIVE = 0;
    go_to_xy(0, GRID_SIZE + 2);
    std::cout << "Dead!!! Please enter any key to exit";
}

bool self_collision()
{
    for (int i = 0; i < SIZE_SNAKE - 1; i++)
        if (snake[SIZE_SNAKE - 1].x == snake[i].x && snake[SIZE_SNAKE - 1].y == snake[i].y)
            return 1;
    return 0;
}

void move_right(char grid[][GRID_SIZE])
{
    if (snake[SIZE_SNAKE - 1].x + 1 == GRID_SIZE)
        process_dead();
    else
    {
        if (snake[SIZE_SNAKE - 1].x + 1 == food[FOOD_IDX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_IDX].y)
            eat();
        go_to_xy(snake[0].x, snake[0].y);
        text_color(BLACK, BLACK);
        //grid[snake[0].x][snake[0].y] = ' ';
        std::cout << " ";
        text_color(BLACK, WHITE);

        for (int i = 0; i < SIZE_SNAKE - 1; i++)
        {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].x++;

        grid[snake[SIZE_SNAKE - 1].x][snake[SIZE_SNAKE - 1].y] = 'O';
        draw_snake();

        if (self_collision()) 
        {
            process_dead();
            return;
        }
    }
}

void move_left(char grid[][GRID_SIZE])
{
    if (snake[SIZE_SNAKE - 1].x - 1 == 0)
        process_dead();
    else
    {
        if (snake[SIZE_SNAKE - 1].x - 1 == food[FOOD_IDX].x && snake[SIZE_SNAKE - 1].y == food[FOOD_IDX].y)
            eat();
        go_to_xy(snake[0].x, snake[0].y);
        text_color(BLACK, BLACK);
        //grid[snake[0].x][snake[0].y] = ' ';
        std::cout << " ";
        text_color(BLACK, WHITE);

        for (int i = 0; i < SIZE_SNAKE - 1; i++)
        {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].x--;

        grid[snake[SIZE_SNAKE - 1].x][snake[SIZE_SNAKE - 1].y] = 'O';
        draw_snake();

        if (self_collision()) 
        {
            process_dead();
            return;
        }
    }
}

void move_up(char grid[][GRID_SIZE])
{
    if (snake[SIZE_SNAKE - 1].y - 1 == 0)
        process_dead();
    else
    {
        if (snake[SIZE_SNAKE - 1].x == food[FOOD_IDX].x && snake[SIZE_SNAKE - 1].y - 1 == food[FOOD_IDX].y)
            eat();
        go_to_xy(snake[0].x, snake[0].y);
        text_color(BLACK, BLACK);
        //grid[snake[0].x][snake[0].y] = ' ';
        std::cout << " ";
        text_color(BLACK, WHITE);

        for (int i = 0; i < SIZE_SNAKE - 1; i++)
        {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].y--;

        grid[snake[SIZE_SNAKE - 1].x][snake[SIZE_SNAKE - 1].y] = 'O';
        draw_snake();

        if (self_collision()) 
        {
            process_dead();
            return;
        }
    }
}

void move_down(char grid[][GRID_SIZE])
{
    if (snake[SIZE_SNAKE - 1].y + 1 == GRID_SIZE)
        process_dead();
    else
    {
        if (snake[SIZE_SNAKE - 1].x == food[FOOD_IDX].x && snake[SIZE_SNAKE - 1].y + 1 == food[FOOD_IDX].y)
            eat();
        go_to_xy(snake[0].x, snake[0].y);
        text_color(BLACK, BLACK);
        //grid[snake[0].x][snake[0].y] = ' ';
        std::cout << " ";
        text_color(BLACK, WHITE);

        for (int i = 0; i < SIZE_SNAKE - 1; i++)
        {
            snake[i].x = snake[i + 1].x;
            snake[i].y = snake[i + 1].y;
        }
        snake[SIZE_SNAKE - 1].y++;

        grid[snake[SIZE_SNAKE - 1].x][snake[SIZE_SNAKE - 1].y] = 'O';
        draw_snake();

        if (self_collision()) 
        {
            process_dead();
            return;
        }
    }
}

/*
int main() {
    char grid[GRID_SIZE][GRID_SIZE];
    generate_board(grid, NUM_OBSTACLES_LV_2);
    init_snake();
    draw_snake();
    go_to_xy(22,22);
    system("pause");
    return 0;
}


#endif*/