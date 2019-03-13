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
		std::cout << this->m_name << "님" << con.getname() << " 땅을 구입하셨습니다\n"
			<< "땅의 가격은" << con.getprice();
		m_assets -= con.getprice();
		std::cout << "구매후 자산은 " << m_assets << "\n";
		other.changeplayer(con);
	
	}
	else {
		//판매자가 허락을 한다면 판매
		if (other.allowsell()) {
			std::cout << this->m_name << "님" << con.getname() << " 땅을"<<other.m_name<<"님에게 구입하셨습니다\n"
				      << "땅의 가격은" << con.getprice();

			m_assets -= con.getprice();
			std::cout << "구매후 자산은 " << m_assets << "\n";


			other.m_assets += con.getprice();
			std::cout << other.m_name << "님은 " << con.getname() << "땅을 판매하셨습니다\n"
				<< other.m_name << "님의 판매후 자산은 " << other.m_assets << "입니다";
		}
		else {
			std::cout << "땅의 판매자분이 판매를 거절 하셨습니다.\n";
		}
	}



	

	std::cout << con.getname() << "땅을 판매하셨습니다\n";
	m_assets += con.getprice();
	std::cout << "판매후 자산은 " << m_assets << "\n";


}
//플레이어가 y를 입력하면 true, n을 입력하면 falss
bool Player::allowsell()
{
	char answer;
	std::cout << this->m_name << "님 땅을 판매하시겠습니까?(판매한다면 y,그렇지 않다면 n) \n";
	std::cin >> answer;
	if (answer == 'y')
		return true;
	else return false;
}

void Player::Pay_tolls(country & con)
{
	const Player* temp = con.getplayer();
	if (temp->m_name == "No Name") {
		std::cout << "땅의 소유자가 없으므로 통행료를 지불하지 않습니다\n";
	}
	else {
		std::cout << "땅의 소유자인 " << temp->m_name << " 님 에게 통행료 " << con.getfee()
			<< "를 지불합니다";
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


