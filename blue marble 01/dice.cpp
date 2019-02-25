#include "pch.h"
#include"dice.h"

using namespace std;

void textcolor2(int color_number)

{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

void gotoxy2(int x, int y)//커서의 위치를 옮긴다
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void upLinePrompt(int count)
{
	for (int i = 0; i < count; ++i) {
		//printf("%c[2K",27);
		cout << "\33[2K"; //line clear
		cout << "\x1b[A"; //up line (ESC [ A) must be support VT100 escape seq
	}
}


void Dice::printdicebound(int x, int y, int number)
{
	textcolor2(rand() % 5 + 10);
	gotoxy2(x, y);
	cout << "----------------";
	for (int i = 0; i < 6; i++) {
		gotoxy2(x, ++y);
		cout << "|";
	}
	y -= 6;
	for (int i = 0; i < 6; i++) {
		gotoxy2(x + 15, ++y);
		cout << "|";
	}
	y -= 6;
	gotoxy2(x, y + 7);
	cout << "----------------";

	switch (number)
	{
	case 1:
		gotoxy2(x + 7, y + 3);
		cout << "@";
		break;
	case 2:
		gotoxy2(x + 3, y + 3);
		cout << "@      @";
		break;

	case 3:
		gotoxy2(x + 7, y + 1);
		cout << "@";
		gotoxy2(x + 7, y + 3);
		cout << "@";
		gotoxy2(x + 7, y + 6);
		cout << "@";
		break;

	case 4:
		gotoxy2(x + 3, y + 1);
		cout << "@      @";
		gotoxy2(x + 3, y + 5);
		cout << "@      @";
		break;
	case 5:
		gotoxy2(x + 3, y + 1);
		cout << "@      @";
		gotoxy2(x + 3, y +5);
		cout << "@      @";
		gotoxy2(x + 7, y + 3);
		cout << "@";
		break;
	case 6:
		gotoxy2(x + 3, y + 1);
		cout << "@      @";
		gotoxy2(x + 3, y + 3);
		cout << "@      @";
		gotoxy2(x + 3, y + 5);
		cout << "@      @";
		break;
	default:
		break;
	}
}

int Dice::drawdice()
{
	srand((unsigned int)time(0));
	int double_cnt = 0, sum = 0;
	int x1 = 109, x2 = 129;//주사위 시작 좌표
	int y = 4;
	int number1, number2;
	number1 = rand() % 6 + 1;
	number2 = rand() % 6 + 1;

	if (number1 == number2) {
		gotoxy2(x1, y + 15);
		std::cout << "double("<<number1+number2<<") 이 나왔으므로 한번 더\n";
		int number3, number4;
		number3 = rand() % 6 + 1;
		number4 = rand() % 6 + 1;
		printdicebound(x1, y, number3);
		printdicebound(x2, y, number4);
		double_cnt++;
		sum += (2 * number1+number3+number4);
		gotoxy2(x1, y + 17);
		std::cout << "주사위의 합은: " << sum <<"입니다"<< endl;
		return sum;
	}
	else {
		printdicebound(x1, y, number1);
		printdicebound(x2, y, number2);
		sum += (number2 + number1);
		gotoxy2(x1, y + 17);
		std::cout << "주사위의 합은: " << sum << "입니다" << endl;
		return sum;
	}
	gotoxy2(x1, y + 17);
	std::cout << "주사위의 합은: " << sum << "입니다" << endl;
	return sum;
}
