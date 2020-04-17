#pragma once
#include "gameNode.h"
class HPSetting : public gameNode
{
private:
	RECT _HpBar;
	RECT _HpFront;
	RECT V_HpBar;
	float _x, _y;
	float P_width;
	float P_hight;
	float _width;
	float _hight;

	// ü�� ���� '
	image* _HpBarFront;
	image* _HpBarBack;

	

public:
	HPSetting();
	~HPSetting();

	HRESULT init_Player(float x, float y);
	HRESULT init_Villein(float x, float y, int width, int height, int type);
	void release();
	void update();
	void Render_Player();
	void Render_Villein(int type);  // �������� �ٸ��� hp ���� �ٸ��� 

	void SetGauge(float currentGauge, float MaxGauge);

	void SetX(float x) { _x = x; }
	
	void SetY(float y) { _y = y; }
	//�÷��̾�
	RECT getRC() { return _HpBar; }
	// ����
	RECT getrc() { return V_HpBar;  }

};

