#pragma once
#include "gameNode.h"

struct _Player
{
	float x, y;   // �÷��̾� �߽ɰ� 
	float angle;  // �÷��̾� ���� 
	float radius; // �÷��̾� ������
	float speed; // �ӵ� 
	int score = 0;

};

struct _Ball
{
	float x2, y2;  // �� �߽ɰ�
	float angle2;  // �� ����
	float radius2; // �� ������.  
	float speed2;
	bool center; // ��  ���� Ȯ�� ����
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

	bool _Start;  // ���� ��ŸƮ 
	_Player  Player;
	_Player  Player2;
	_Ball  Ball;
	char buf[100];
	float h; // �� �浹 


	RECT GoalPost;
	RECT GoalPost2;

	image* _num[5];

	image* _BG; // ��׶���
	image* _Hall; // �����
	image* _1P;
	image* _2P;
	image* _Ball;
	image* _point;

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render(HDC hdc);	//�׸��� ���� �Լ�

	void KEY();  // 1Player KEYMANAGER
	void KEY2(); // 2Player KEYMANAGER
	void BallMove(); // Ball MOVING
	void BallCrash();
	void BallGoal(); //  Ball Goal

};

