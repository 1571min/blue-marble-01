#include"pch.h"
#include "win.h"
void gotoxy(int x, int y)//커서의 위치를 옮긴다
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}
void textcolor(int color_number)

{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}