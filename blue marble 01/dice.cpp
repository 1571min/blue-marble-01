#include "pch.h"
#include"win.h"
#include"dice.h"

using namespace std;

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
	textcolor(rand() % 5 + 10);
	gotoxy(x, y);
	cout << "----------------";
	for (int i = 0; i < 6; i++) {
		gotoxy(x, ++y);
		cout << "|";
	}
	y -= 6;
	for (int i = 0; i < 6; i++) {
		gotoxy(x + 15, ++y);
		cout << "|";
	}
	y -= 6;
	gotoxy(x, y + 7);
	cout << "----------------";

	switch (number)
	{
	case 1:
		gotoxy(x + 7, y + 3);
		cout << "@";
		break;
	case 2:
		gotoxy(x + 3, y + 3);
		cout << "@      @";
		break;

	case 3:
		gotoxy(x + 7, y + 1);
		cout << "@";
		gotoxy(x + 7, y + 3);
		cout << "@";
		gotoxy(x + 7, y + 6);
		cout << "@";
		break;

	case 4:
		gotoxy(x + 3, y + 1);
		cout << "@      @";
		gotoxy(x + 3, y + 5);
		cout << "@      @";
		break;
	case 5:
		gotoxy(x + 3, y + 1);
		cout << "@      @";
		gotoxy(x + 3, y +5);
		cout << "@      @";
		gotoxy(x + 7, y + 3);
		cout << "@";
		break;
	case 6:
		gotoxy(x + 3, y + 1);
		cout << "@      @";
		gotoxy(x + 3, y + 3);
		cout << "@      @";
		gotoxy(x + 3, y + 5);
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
		gotoxy(x1, y + 15);
		std::cout << "double("<<number1+number2<<") 이 나왔으므로 한번 더\n";
		int number3, number4;
		number3 = rand() % 6 + 1;
		number4 = rand() % 6 + 1;
		printdicebound(x1, y, number3);
		printdicebound(x2, y, number4);
		double_cnt++;
		sum += (2 * number1+number3+number4);
		gotoxy(x1, y + 17);
		std::cout << "주사위의 합은: " << sum <<"입니다"<< endl;
		return sum;
	}
	else {
		printdicebound(x1, y, number1);
		printdicebound(x2, y, number2);
		sum += (number2 + number1);
		gotoxy(x1, y + 17);
		std::cout << "주사위의 합은: " << sum << "입니다" << endl;
		return sum;
	}
	gotoxy(x1, y + 17);
	std::cout << "주사위의 합은: " << sum << "입니다" << endl;
	return sum;
}
