#pragma once
#include "gameNode.h"
#include "Player.h"
#include "HPSetting.h"


//타입 
enum Villein_Type
{
	V_ONE,		 // 첫번째 빌런 
	V_BOSS,		 // 마지막 보스  
	GameEnd		 // 게임 종료 
};

// 스테이지 별 빌런 패턴 
struct Stage
{
	Villein_Type  Villein;		 // 빌런들의 타입 
	int			  Move;			 // 빌런들의 움직임
	bool		  turn;			 // 움직임 불값  왼 / 오
	bool		  Left_Right;	 // 방향 설정 ss
};
enum direction {
	Left,
	Right
};
class Villein :
	public gameNode
{
protected:
	image* _imageName;// 빌런 관련  
	RECT _rc;		  // 빌런 관련 
	RECT _MiniBoss;
	Player* _P;
	HPSetting* _HP;
	Stage _Move;
	float _angle;
	
	direction _dir;
	int _currentFrameX;
	int _currentFrameY;
	int _count;
	int _FireCount;
	int _RndFireCount;  // 임의 숫자의 의해 발사 카운트 변수 

	int FrameCount, FrameCount2;

	RockBuster* _RockBuster;

	// 체력 설정 
	float _currentHP, _MaxHP; 

public:
	Villein();
	~Villein();
	virtual HRESULT init();
	virtual HRESULT init(const char* imageName, POINT position);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void move();
	virtual void draw();
	virtual bool CountFire();   // 총알을 쏘라고 신호를 줄 함수 ,
	virtual void SetType(int type) { _Move.Villein = (Villein_Type)type; }  //  불러올 빌런 타입
	virtual void SetLorR(bool LorR) { _Move.Left_Right = LorR; }
	virtual void setAngle(float angle) { _angle = angle; }
	virtual Stage getMove() { return _Move; }

	virtual void setBossState(int bs) {}
	virtual inline RECT getRect() { return _rc; }
	virtual void HitDamage(float Damge);
	Villein_Type getEnemyType() { return _Move.Villein; }
	float getCurrentHP() { return _currentHP; }

	virtual void SetPlayerAdress(Player* input) { _P = input; }

};

