#pragma once
#include "gameNode.h"
#include "RockBuster.h"
#include "HPSetting.h"

class VilleinManager;

struct M_Wall
{
	RECT _rc;
	RECT _rc2;
};

enum PlayerState
{
	Player_Start,  //ó�� �������� �̹��� ,
	Player_Appear,			// ���� 
	Player_Idle,
	Player_Run,
	Player_Jump,
	Player_Wall_Jump,		// �� ���� 
	Player_Dash,
	Player_Attack,			// ���ڸ� ����
	Player_Run_Attack,		// �޸��鼭 ����
	Player_Jump_Attack,		// ���� ���� 
	Player_Next_Stage,		// �������� �̵�
	Player_GameOver ,
	Player_charging,
	Player_charging1,
	Player_charging2,
	Plyer_Fire
}; 

enum Direction
{
	RIGHT,
	LEFT
};

// bool Ÿ�� ���¸� �����ϴ� ����ü
struct tagBoolState
{
	bool _isJump;
	bool _gravityOnOff;
	bool _WallJump;
};
// Player ����ü 
struct Player_
{
	// �Ŵ޸��� ��Ʈ
	RECT R_rc, L_rc;
	tagBoolState Player_bool;
	int _x, _y;
	float speed;
};



class Player :	public gameNode
{
private:
	image* _PLAYER;
	Player_ Player_O;
	PlayerState _PlayerState;
	Direction _Direction;

	// ���� ���� 
	VilleinManager* _Vi;
	float JumpPower, gravity;
	RECT _rc;	//�÷��̾� ��Ʈ
	bool _usingCharging;

	M_Wall _Wall;

	// Ư�� ��� ī��Ʈ 
	image* _PlayerEffect;
	int _FrameCount; // ��¡ !!!!!!!!!!!!
	int _FrameX, _FrameY;
	int _EffectR;
	int _EffectL;
	int _EffectMaxFrameX;
	int _EffectMaxFrameY;

	// �÷��̾� ī��Ʈ 
	int _fireDirection;
	int _FireCount;
	int _currentMaxFrame;
	int _currentMaxFrameY;
	int _currentFrameX;
	int _currentFrameY;
	int _DirectionR;
	int _DirectionL;
	int _count, _index;
	
	/*
	 �÷��̾� ������
	int _centerX, _centerY; 
	���� ��ǥ  // �÷��̾ �׸��� �������̹����� width, height�� �����.
	 _centerX = _PLAYER->getFrameWidth()/2 + Player_O._x;
	 _centerY = _PLAYER->getFrameHeight()/2 + Player_O._y;*/

	// RockBuster* _RockBuster;
	NomalAttack* _Attack;

	HPSetting* _HP;
	float _currentHP, _MaxHp;

public:
	Player();
	~Player();

	
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
	void KeySetting();
	void PlayerMoveFrame();
	void EffectFramemove();
	void SwitchImage();
	Player_ getPlayer() { return Player_O; }
	image* getPlayerImage() { return _PLAYER; }

	NomalAttack* N_ATK() { return _Attack; }

	void collision();
	void HitDmage(float dmage);
	void setEnemyAddressLink(VilleinManager* vi) { _Vi = vi; }

	int getHP() { return _currentHP; }

};

