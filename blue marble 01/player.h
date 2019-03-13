#pragma once


#include<string>

class Player {
	friend class Map;    //map클래스에서 플레이어 정보를 사용한다
	friend class country; //country 클래스에서 플레이어 정보를 사용한다

private:
	enum { Maxland = 25 };
	std::string m_name;

	double m_assets;
	char *property[Maxland] = {}; //플레이어가 가지고 있는 땅의 목록
	int landnumber = 0; //플레이어가 가지고 있는 땅의 숫자

public:
	Player(std::string in_name="No Name", double in_assets=1.0);
	//나라의 거래를 정의
	void Buy_land(country &con,Player other);
	//나라 소유자에게 판매의사 묻기
	bool allowsell();
	//통행료 지불
	void Pay_tolls(country& con);
	//나라의 주인을 바꾼다 //************** 수정이 필요(나라의 주인을 바꾸려면 country 클래스에서 순화을 통해 찾고 바꾸는게 효율적***********//  
	void changeplayer(country &c);
	//플레이어 정보 공개
	void show_player_info();
};