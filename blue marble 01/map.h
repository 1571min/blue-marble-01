#pragma once
#include"pch.h"



class country {
	friend class Map;
private:
	std::string m_name;  //�� �̸�
	double m_tollfee;    //����� 
	double m_landprice;  //����
	int m_player;        //���� �÷��̾�
	country *m_next;     //���� ����
	country *m_prev;     //���� ����
public:
	country(std::string name, double toll, double price, country*next = nullptr, country*prev = nullptr, int player = 0)
		:m_name(name), m_tollfee(toll), m_landprice(price), m_player(player), m_next(next), m_prev(prev) {}

};

class Map {
private:
	country *head;
	country *midle;// �߰����� Ž�� ����
	int size;
public:
	Map(std::ifstream& is);//������ �о�� �����ھȿ��� �� ����Ʈ �ʱ�ȭ //���� �Ҵ� ����
	country& insert(country* head, country* new_country); //������ ���� ���� ����Ʈ�ν� �����Ѵ�
	void printmap(country* head);  // ���� �׸���
	void printcontry(int x, int y);// �� ������ ��輱�� �׸���
	country* gethead() { return head; }
};



class player {

};

