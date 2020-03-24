#pragma once
#include "gameNode.h"
#define BULLETMAX 25  //�Ѿ� ���� 
#define Target 15  //  �Ϲ� Ÿ�� ���� 
#define S_Target 5 // Ư�� Ÿ�� ���� . 

struct _Target {

	//RECT TARGET; // Ÿ�� ���� 
	bool turn;  // ���� ���� ���� 
	//float h, w; // ���� , ����  ũ�� 
	float x, y;  // �� �Ʒ� Ÿ����
	float angle;  // Ÿ�� ����
	float speed;  // Ÿ�� ���ǵ� 
	float gravity; // Ÿ�� �߷� �� 
	bool  isfire; // Ÿ�� Ȯ�� ��
};

struct _Fire {

	bool isfire;  // �߻� ���� 
	// RECT AIM;  // ������ 
	float angle2; // ���� ���� 
	float speed2; // ���� ���ǵ� 
	float x, y;// ���� �� 
	float h, w;  //���� , ���� ũ�� , 
};


class playGround : public gameNode
{
private:

	char buf[100];
	char buf2[100];
//	RECT _Cannon; // �߻�� 
//	RECT _Cannon2; // �߻�� 
	RECT _Player;  // �÷��̾� �̹��� 
	

	
	_Fire  _AIM;   // �ަU ����
	_Fire  __AIM;  // �����U ���� 

	_Target __Target[15];  //����ü ����.
	_Target S_TargeT[6];

	int _score; // ���� 
	int _count;
	int S_count;

	image* _num[10];// ���� 
	image* _Aim;
	image* _BG; // ��� 
	image* _right; // ������ Ÿ�� 
	image* _left; // ���� Ÿ�� 
	image* _PlayerM; // �÷��̾� �߰�
	image* _PlayerL; // �÷��̾� ����
	image* _PlayerR; // �÷��̾� ������. 


public:
	playGround();
	~playGround();

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render(HDC hdc);	//�׸��� ���� �Լ�

	void Targetfire();
	void TargetMove();

	void Targetfire_2();
	void TargetMove_2();

	void AIMControl(_Target, _Fire &fire);


};

