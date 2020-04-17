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
	Player_Start,  //처음 내려오는 이미지 ,
	Player_Appear,			// 등장 
	Player_Idle,
	Player_Run,
	Player_Jump,
	Player_Wall_Jump,		// 벽 점프 
	Player_Dash,
	Player_Attack,			// 제자리 공격
	Player_Run_Attack,		// 달리면서 공격
	Player_Jump_Attack,		// 점프 공격 
	Player_Next_Stage,		// 스테이지 이동
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

// bool 타입 상태를 저장하는 구조체
struct tagBoolState
{
	bool _isJump;
	bool _gravityOnOff;
	bool _WallJump;
};
// Player 구조체 
struct Player_
{
	// 매달리기 렉트
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

	// 점프 관련 
	VilleinManager* _Vi;
	float JumpPower, gravity;
	RECT _rc;	//플레이어 렉트
	bool _usingCharging;

	M_Wall _Wall;

	// 특수 모션 카운트 
	image* _PlayerEffect;
	int _FrameCount; // 차징 !!!!!!!!!!!!
	int _FrameX, _FrameY;
	int _EffectR;
	int _EffectL;
	int _EffectMaxFrameX;
	int _EffectMaxFrameY;

	// 플레이어 카운트 
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
	 플레이어 중점값
	int _centerX, _centerY; 
	중점 좌표  // 플레이어를 그리는 프레임이미지의 width, height를 써야함.
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

