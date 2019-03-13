#pragma once


#include<string>

class Player {
	friend class Map;    //mapŬ�������� �÷��̾� ������ ����Ѵ�
	friend class country; //country Ŭ�������� �÷��̾� ������ ����Ѵ�

private:
	enum { Maxland = 25 };
	std::string m_name;

	double m_assets;
	char *property[Maxland] = {}; //�÷��̾ ������ �ִ� ���� ���
	int landnumber = 0; //�÷��̾ ������ �ִ� ���� ����

public:
	Player(std::string in_name="No Name", double in_assets=1.0);
	//������ �ŷ��� ����
	void Buy_land(country &con,Player other);
	//���� �����ڿ��� �Ǹ��ǻ� ����
	bool allowsell();
	//����� ����
	void Pay_tolls(country& con);
	//������ ������ �ٲ۴� //************** ������ �ʿ�(������ ������ �ٲٷ��� country Ŭ�������� ��ȭ�� ���� ã�� �ٲٴ°� ȿ����***********//  
	void changeplayer(country &c);
	//�÷��̾� ���� ����
	void show_player_info();
};