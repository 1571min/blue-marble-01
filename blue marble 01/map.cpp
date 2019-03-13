#include "pch.h"
#include "map.h"
#include"win.h"
using namespace std;


Map::Map(std::ifstream & is)
{
	head = nullptr;
	double toll, land;
	std::string name;

	if (is.is_open()) {
		while (!is.eof()) {
			is >> name >> land >> toll;
			country *new_cou = new country(name, toll, land);
			head = &insert(head, new_cou);//연결리스트 추가
		}
	}
	else {
		cout << "파일을 찾을 수 없습니다\n" << endl;
	}
}

country& Map::insert(country * head, country * new_country)
{
	if (head == nullptr) {
		new_country->m_next = head;
		head = new_country;
		return *head;

	}
	else {
		new_country->m_next = head;
		head= new_country;
		return *head;
	}
}

void Map::printmap(country* head)
{
	country* front = head;
	//맵과 주사위,플레이어 화면 구분선
	for (int i = 0; i < 50; i++){
		gotoxy(100, i);
		cout << "|*|";
	}
	gotoxy(103, 24);
	cout << "_______________________________________________";

	//각각의 4개의 기준점 부터 5번 4번 4번 3번 씩 반복 하며 맵을 그려준다
	while (front->m_next!= nullptr) {
		for (int i = 0; i < 5; i++) {
			printcontry(73 - 16 * i, 36);
			gotoxy(73 - 16 * i + 4, 36 + 2);
			cout << front->m_name;
			front = front->m_next;
		}
		for (int i = 0; i < 4; i++) {
			printcontry(9, 28 - i * 8);
			gotoxy(9+4, 28 - i * 8+2);
			cout << front->m_name;
			front = front->m_next;
		}
		for (int i = 0; i < 4; i++) {
			printcontry(25 + i * 16, 4);
			gotoxy(25 + i * 16+4, 4+2);
			cout << front->m_name;
			front = front->m_next;
		}
		for (int i = 0; i < 3; i++) {
			printcontry(73, 12 + i * 8);
			gotoxy(73+4, 12 + i * 8+2);
			cout << front->m_name;
			front = front->m_next;
		}
	}
}

void Map::printcontry(int x, int y)
{
	textcolor(rand() % 5 + 10);
	gotoxy(x, y);
	cout << "================";
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
	gotoxy(x, y+7);
	cout << "================";
}

void Map::printplayer()
{
	gotoxy(105, 29);
	std::cout << "|    플레이어 이름    |       자산       |\n";
	for (int i = 0; i < 4; i++) {
		gotoxy(105, 30 + i*2);
		player[i].show_player_info();
	}
}




