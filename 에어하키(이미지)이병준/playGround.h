#pragma once
#include "gameNode.h"

struct _Player
{
	float x, y;   // 플레이어 중심값 
	float angle;  // 플레이어 각도 
	float radius; // 플레이어 반지름
	float speed; // 속도 
	int score = 0;

};

struct _Ball
{
	float x2, y2;  // 공 중심값
	float angle2;  // 공 각도
	float radius2; // 공 반지름.  
	float speed2;
	bool center; // 공  센터 확인 유무
};

struct _Goal
{
	RECT Goal;

};

class playGround : public gameNode
{
private:
/*
	image* _background;
	image* _boYoung;
	image* _taeYeon;
	image* _slime;*/

	bool _Start;  // 게임 스타트 
	_Player  Player;
	_Player  Player2;
	_Ball  Ball;
	char buf[100];
	float h; // 공 충돌 


	RECT GoalPost;
	RECT GoalPost2;

	image* _num[5];

	image* _BG; // 백그라운드
	image* _Hall; // 경기장
	image* _1P;
	image* _2P;
	image* _Ball;
	image* _point;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 전용 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render(HDC hdc);	//그리기 전용 함수

	void KEY();  // 1Player KEYMANAGER
	void KEY2(); // 2Player KEYMANAGER
	void BallMove(); // Ball MOVING
	void BallCrash();
	void BallGoal(); //  Ball Goal

};

