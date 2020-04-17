#pragma once
#include "gameNode.h"
#include "Player.h"
#include "VilleinManager.h"

// 맵 벽 설정
struct MapWall 
{
	RECT _rc3;
};

class playGround : public gameNode
{
	enum changeScreen
	{
		Screen,
		Screen2
	};

private:
	MapWall _Wall;
	changeScreen _changeScreen;
	int _index, _count, _StartButton,_BackGroundOut, _BackGroundIn;
	bool startCheck;
	int _startCount;
	
	//class  참조
	Player* _player;
	VilleinManager* _First_Villein;

public:
	playGround();
	~playGround();

	virtual HRESULT init();	//초기화 전용 함수
	virtual void release();	//메모리 해제 함수
	virtual void update();	//연산 전용 함수
	virtual void render();	//그리기 전용 함수




};

