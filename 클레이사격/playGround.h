#pragma once
#include "gameNode.h"
#define BULLETMAX 25  //총알 갯수 
#define Target 15  //  일반 타겟 갯수 
#define S_Target 5 // 특수 타겟 갯수 . 

struct _Target {

	//RECT TARGET; // 타겟 갯수 
	bool turn;  // 다음 라운드 셋팅 
	//float h, w; // 세로 , 가로  크기 
	float x, y;  // 위 아래 타겟점
	float angle;  // 타겟 각도
	float speed;  // 타겟 스피드 
	float gravity; // 타켓 중력 값 
	bool  isfire; // 타겟 확인 ㅡ
};

struct _Fire {

	bool isfire;  // 발사 유무 
	// RECT AIM;  // 에임점 
	float angle2; // 에임 각도 
	float speed2; // 에임 스피드 
	float x, y;// 위아 래 
	float h, w;  //세로 , 가로 크기 , 
};


class playGround : public gameNode
{
private:

	char buf[100];
	char buf2[100];
//	RECT _Cannon; // 발사대 
//	RECT _Cannon2; // 발사대 
	RECT _Player;  // 플레이어 이미지 
	

	
	_Fire  _AIM;   // 왼쪾 에임
	_Fire  __AIM;  // 오른쪾 에임 

	_Target __Target[15];  //구조체 만듬.
	_Target S_TargeT[6];

	int _score; // 점수 
	int _count;
	int S_count;

	image* _num[10];// 점수 
	image* _Aim;
	image* _BG; // 배경 
	image* _right; // 오른쪽 타겟 
	image* _left; // 왼쪽 타겟 
	image* _PlayerM; // 플레이어 중간
	image* _PlayerL; // 플레이어 왼쪽
	image* _PlayerR; // 플레이어 오른쪽. 


public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 전용 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render(HDC hdc);	//그리기 전용 함수

	void Targetfire();
	void TargetMove();

	void Targetfire_2();
	void TargetMove_2();

	void AIMControl(_Target, _Fire &fire);


};

