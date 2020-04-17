#pragma once
#include "Villein.h"
#include "RockBuster.h"
#include"gameNode.h"
enum BossState
{
	Boss_Boss,
	Boss_idle,
	Boss_Attack,
	Boss_run,
	Boss_Attack2
};

enum Dir
{
	RIGHT2,
	LEFT2
};

struct Boss_
{
	int _x, _y;
	float _speed;
};

class MiniBoss : public Villein
{

private:
	image* __Boss;
	Boss_ Boss_;
	BossState _BossState;
	Dir _Dir;

	RECT _Boss;
	RECT _B;

	int _currentX, _currentY;
	int _currentMaxX, _currentMaxY;
	int _count, _index;
	int _DirL, _DirR;
	Player* _Player;

	int interver;
	int interver2;
	int attack2interver;
public:
	MiniBoss();
	~MiniBoss();

	virtual HRESULT init();
	virtual void move();
	virtual void release();
	virtual void update();
	virtual void render();
	virtual RECT getRect() { return _B; }
	void BossFrame();
	void SwitchImage();
	virtual void setBossState(int bs) { _BossState = (BossState)bs; }
	//image* getBossImage() { return _Boss; }

	void collision();
	void hitDmage(float Dmage); 

};

