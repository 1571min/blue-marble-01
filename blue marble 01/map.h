#pragma once
#include"player.h"

class country {
	friend class Map;
	friend class Player;
private:

	std::string m_name;  //�� �̸�
	double m_tollfee;    //����� 
	double m_landprice;  //����
	Player *m_player =new Player("noname",1.0); //���� �÷��̾�
	country *m_next;     //���� ����
	country *m_prev;     //���� ����
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
	country *midle;// �߰����� Ž�� ����
	int size;
	Player player[4] = { {"lee",22},
						 {"kim",22},
						 {"jun",22},
						 {"cho",22},
	};

public:
	Map(std::ifstream& is);//������ �о�� �����ھȿ��� �� ����Ʈ �ʱ�ȭ //���� �Ҵ� ����
	country& insert(country* head, country* new_country); //������ ���� ���� ����Ʈ�ν� �����Ѵ�
	void printmap(country* head);  // ���� �׸���
	void printcontry(int x, int y);// �� ������ ��輱�� �׸���
	country* gethead() { return head; }
	void printplayer(); //�÷��̾��� ������ �Է��Ѵ�
	
	//����� ���� �����Ͽ� ���ο��� ��ĥ �� �ΰ� �ƴϸ� ����� map Ŭ�������� ��Ƽ� ��ĥ ���ΰ� ����
	// �ǹ� ���࿡ ���� �����Ѵٸ� ���� �Լ����� Ŭ������ ����������Ѵ�
};

