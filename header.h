#include <iostream>
#include <ctime>
#include <conio.h>

#define ARROW_UP 0x48
#define ARROW_LEFT 0x4B
#define ARROW_RIGHT 0x4D
#define ARROW_DOWN 0x50
#define ARROW_NONE 0x00
#define ESC_KEY 0x1B
#define ENTER_KEY 0x0D
#define SPACE_KEY 0x20

#define GRID_SIZE 20
#define NUM_OBSTACLES_LV_1 int(15)
#define NUM_OBSTACLES_LV_2 int(22)
#define NUM_OBSTACLES_LV_3 int(30)

#define MAX_SIZE_SNAKE 16
#define MAX_SIZE_FOOD 5
#define MAX_SPEED 3

#define MSSV "22127365_"

POINT snake[MAX_SIZE_SNAKE];
POINT food[MAX_SIZE_FOOD];
int DIR_LOCK, DIR, SPD, WIN_HEIGHT;
int FOOD_IDX, SIZE_SNAKE = 6;
bool ALIVE;
