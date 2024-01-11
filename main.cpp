#include "snake_entity.cpp"

unsigned char input_key()
{
    unsigned char ch = getch();
    if (ch == 0x00)
    {
        // first char is a zero so lets look at the next char
        ch = getch();
        switch (ch)
        {
        case ARROW_UP:
            return ch;
        case ARROW_LEFT:
            return ch;
        case ARROW_RIGHT:
            return ch;
        case ARROW_DOWN:
            return ch;
        default:
            return ARROW_NONE;
        }
    }
    else
    {
        // When user use WASD keys + H key for SuggestMove Function
        switch (ch)
        {
        case 'w':
            return ARROW_UP;
        case 'a':
            return ARROW_LEFT;
        case 'd':
            return ARROW_RIGHT;
        case 's':
            return ARROW_DOWN;
        }
    }

    // Enter key is the same as space key
    if (ch == ENTER_KEY || ch == SPACE_KEY)
        return ENTER_KEY;

    if (ch == ESC_KEY)
        return ch;

    return ch;
}


int main()
{
    fix_console_window();
    set_center_window();
    hide_scrollbar();

    char grid[GRID_SIZE][GRID_SIZE];

    initialize_grid(grid);
    generate_board(grid, 0);
    init_snake();
    draw_snake();
    
    int get_key;
    ALIVE = true;
    while (1)
    {
        get_key = input_key();
        if (ALIVE)
        {
            switch (get_key)
            {
            case ARROW_UP:
                move_up(grid);
                break;
            case ARROW_DOWN:
                move_down(grid);
                break;
            case ARROW_LEFT:
                move_left(grid);
                break;
            case ARROW_RIGHT:
                move_right(grid);
                break;
            }

        }
        else break;
    }
    //go_to_xy(22, 22);
    //system("pause");
    return 0;
}