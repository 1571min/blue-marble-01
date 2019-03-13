#include "pch.h"
#include "player.h"
#include<iostream>
#include"map.h"



Player::Player(std::string in_name, double in_assets)
	:m_name(in_name),m_assets(in_assets)
{
}

void Player::Buy_land(country & con,Player other)
{

	if (other.m_name == "No Name") {
		std::cout << this->m_name << "��" << con.getname() << " ���� �����ϼ̽��ϴ�\n"
			<< "���� ������" << con.getprice();
		m_assets -= con.getprice();
		std::cout << "������ �ڻ��� " << m_assets << "\n";
		other.changeplayer(con);
	
	}
	else {
		//�Ǹ��ڰ� ����� �Ѵٸ� �Ǹ�
		if (other.allowsell()) {
			std::cout << this->m_name << "��" << con.getname() << " ����"<<other.m_name<<"�Կ��� �����ϼ̽��ϴ�\n"
				      << "���� ������" << con.getprice();

			m_assets -= con.getprice();
			std::cout << "������ �ڻ��� " << m_assets << "\n";


			other.m_assets += con.getprice();
			std::cout << other.m_name << "���� " << con.getname() << "���� �Ǹ��ϼ̽��ϴ�\n"
				<< other.m_name << "���� �Ǹ��� �ڻ��� " << other.m_assets << "�Դϴ�";
		}
		else {
			std::cout << "���� �Ǹ��ں��� �ǸŸ� ���� �ϼ̽��ϴ�.\n";
		}
	}



	

	std::cout << con.getname() << "���� �Ǹ��ϼ̽��ϴ�\n";
	m_assets += con.getprice();
	std::cout << "�Ǹ��� �ڻ��� " << m_assets << "\n";


}
//�÷��̾ y�� �Է��ϸ� true, n�� �Է��ϸ� falss
bool Player::allowsell()
{
	char answer;
	std::cout << this->m_name << "�� ���� �Ǹ��Ͻðڽ��ϱ�?(�Ǹ��Ѵٸ� y,�׷��� �ʴٸ� n) \n";
	std::cin >> answer;
	if (answer == 'y')
		return true;
	else return false;
}

void Player::Pay_tolls(country & con)
{
	const Player* temp = con.getplayer();
	if (temp->m_name == "No Name") {
		std::cout << "���� �����ڰ� �����Ƿ� ����Ḧ �������� �ʽ��ϴ�\n";
	}
	else {
		std::cout << "���� �������� " << temp->m_name << " �� ���� ����� " << con.getfee()
			<< "�� �����մϴ�";
		this->m_assets -= con.getfee();
	}
}

void Player::changeplayer(country &c)
{
	c.m_player= this;
}

void Player::show_player_info()
{
	std::cout << "|         " << m_name << "         |        " << m_assets<<"        |";
}


