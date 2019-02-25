// blue marble 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"pch.h"
#include"dice.h"
#include"map.h"

int main() {
	system("mode con cols=150 lines=50");
	using namespace std;
	ifstream is("data.txt");
	Map korea(is);
	Dice D1;
	char dicehit = 0;
	int number;
	while (true) {
		korea.printmap(korea.gethead());
		number = D1.drawdice();
		if (!_kbhit()) {
			dicehit = _getch();
			if (dicehit == ' ')
			{
				Sleep(50);
				system("cls");
			}
			
		}
	}
	
	return 0;
}