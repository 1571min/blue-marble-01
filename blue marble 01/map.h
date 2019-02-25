#pragma once
#include"pch.h"



class country {
	friend class Map;
private:
	std::string m_name;  //맵 이름
	double m_tollfee;    //통행료 
	double m_landprice;  //땅값
	int m_player;        //소유 플레이어
	country *m_next;     //다음 나라
	country *m_prev;     //이전 나라
public:
	country(std::string name, double toll, double price, country*next = nullptr, country*prev = nullptr, int player = 0)
		:m_name(name), m_tollfee(toll), m_landprice(price), m_player(player), m_next(next), m_prev(prev) {}

};

class Map {
private:
	country *head;
	country *midle;// 중간부터 탐색 가능
	int size;
public:
	Map(std::ifstream& is);//파일을 읽어들어서 생성자안에서 맵 리스트 초기화 //동적 할당 했음
	country& insert(country* head, country* new_country); //각각의 맵을 연결 리스트로써 구현한다
	void printmap(country* head);  // 맵을 그린다
	void printcontry(int x, int y);// 각 나라의 경계선을 그린다
	country* gethead() { return head; }
};



class player {

};

