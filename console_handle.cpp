#include <windows.h>

#define BLACK 0
#define AQUA 3
#define RED 4
#define WHITE 7
#define GRAY 8
#define GREEN 10
#define PINK 13
#define YELLOW 14

#ifndef CMD
#define CMD

void fix_console_window()
{
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZE) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void set_center_window(){
	RECT rectClient, rectWindow;
	GetClientRect(GetConsoleWindow(), &rectClient), GetWindowRect(GetConsoleWindow(), &rectWindow);
	int width = 980;
	int height = 680;
	int posX = (GetSystemMetrics(SM_CXSCREEN) - width) / 2,
		posY = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
	MoveWindow(GetConsoleWindow(), posX, posY, width, height, TRUE);
}

void hide_scrollbar()
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, false);
}

void text_color(int background_color, int text_color)
{
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    int color_code = background_color * 16 + text_color;
	SetConsoleTextAttribute(color, color_code);
}

void go_to_xy(int x, int y)
{
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

#endif