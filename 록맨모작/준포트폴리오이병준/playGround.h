#pragma once
#include "gameNode.h"
#include "Player.h"
#include "VilleinManager.h"

// �� �� ����
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
	
	//class  ����
	Player* _player;
	VilleinManager* _First_Villein;

public:
	playGround();
	~playGround();

	virtual HRESULT init();	//�ʱ�ȭ ���� �Լ�
	virtual void release();	//�޸� ���� �Լ�
	virtual void update();	//���� ���� �Լ�
	virtual void render();	//�׸��� ���� �Լ�




};

