#pragma once
#include"player.h"

class country {
	friend class Map;
	friend class Player;
private:

	std::string m_name;  //맵 이름
	double m_tollfee;    //통행료 
	double m_landprice;  //땅값
	Player *m_player =new Player("noname",1.0); //소유 플레이어
	country *m_next;     //다음 나라
	country *m_prev;     //이전 나라
public:
	country(std::string name="No Name", double toll=0, double price=0, country*next = nullptr, country*prev = nullptr)
		:m_name(name), m_tollfee(toll), m_landprice(price), m_next(next), m_prev(prev) {}
	const std::string getname() { return m_name; }
	const double getprice() { return m_landprice; }
	const double getfee() { return m_tollfee; }
	const Player* getplayer() const { return m_player; }
};

class Map {
private:
	country *head;
	country *midle;// 중간부터 탐색 가능
	int size;
	Player player[4] = { {"lee",22},
						 {"kim",22},
						 {"jun",22},
						 {"cho",22},
	};

public:
	Map(std::ifstream& is);//파일을 읽어들어서 생성자안에서 맵 리스트 초기화 //동적 할당 했음
	country& insert(country* head, country* new_country); //각각의 맵을 연결 리스트로써 구현한다
	void printmap(country* head);  // 맵을 그린다
	void printcontry(int x, int y);// 각 나라의 경계선을 그린다
	country* gethead() { return head; }
	void printplayer(); //플레이어의 정보를 입력한다
	
	//기능을 따로 구현하여 메인에서 합칠 것 인가 아니면 기능을 map 클래스에서 모아서 합칠 것인가 결저
	// 의문 만약에 따로 구현한다면 메인 함수에서 클래스를 생성해줘야한다
};

