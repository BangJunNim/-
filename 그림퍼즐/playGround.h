#pragma once
#include "gameNode.h"

struct tagPuzzle
{
	RECT rc;
	float x, y;
};
struct tagPoint //움직이지않는 좌표, 위치를 가르키기 위한거
{
	float x, y;
};

class playGround : public gameNode
{
private:
	image* _background;
	image* _sample;

	tagPuzzle _puzzle[9];
	tagPoint _point[9];

	int _white;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 전용 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render(HDC hdc);	//그리기 전용 함수

};

