#pragma once
#include "gameNode.h"

struct tagPuzzle
{
	RECT rc;
	float x, y;
};
struct tagPoint //���������ʴ� ��ǥ, ��ġ�� ����Ű�� ���Ѱ�
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

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render(HDC hdc);	//�׸��� ���� �Լ�

};

