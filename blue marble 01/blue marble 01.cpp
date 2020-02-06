// blue marble 01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include"pch.h"
#include"dice.h"
#include"map.h"
#include"player.h"

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
		korea.printplayer();

		//_kbhit() ���ۿ� Ű�� ������ 1 ���ۿ� Ű�� ������ 0
		if (_kbhit()==0) {

			dicehit = _getch();
			if (dicehit == ' ')
			{
				Sleep(150);
				system("cls");
			}
			
			
		}
		//���ӵ� ���� �Է��ϸ� ���۸� ���� �ش�
		else
		{
			//���ۿ� �Էµ� ���� ���� ������ �Է��� �޴´�
			while (_kbhit() == 1)
			{
				cout << _getch() << endl;
			}
			Sleep(150);
			system("cls");
		}
	
	}
	
	return 0;
}