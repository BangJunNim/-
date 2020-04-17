#pragma once
#include "gameNode.h"
#include "Player.h"
#include "HPSetting.h"


//Ÿ�� 
enum Villein_Type
{
	V_ONE,		 // ù��° ���� 
	V_BOSS,		 // ������ ����  
	GameEnd		 // ���� ���� 
};

// �������� �� ���� ���� 
struct Stage
{
	Villein_Type  Villein;		 // �������� Ÿ�� 
	int			  Move;			 // �������� ������
	bool		  turn;			 // ������ �Ұ�  �� / ��
	bool		  Left_Right;	 // ���� ���� ss
};
enum direction {
	Left,
	Right
};
class Villein :
	public gameNode
{
protected:
	image* _imageName;// ���� ����  
	RECT _rc;		  // ���� ���� 
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
	int _RndFireCount;  // ���� ������ ���� �߻� ī��Ʈ ���� 

	int FrameCount, FrameCount2;

	RockBuster* _RockBuster;

	// ü�� ���� 
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
	virtual bool CountFire();   // �Ѿ��� ���� ��ȣ�� �� �Լ� ,
	virtual void SetType(int type) { _Move.Villein = (Villein_Type)type; }  //  �ҷ��� ���� Ÿ��
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

