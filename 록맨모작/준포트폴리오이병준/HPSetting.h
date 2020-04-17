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

	// 체력 설정 '
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
	void Render_Villein(int type);  // 빌런마다 다르게 hp 생성 다르게 

	void SetGauge(float currentGauge, float MaxGauge);

	void SetX(float x) { _x = x; }
	
	void SetY(float y) { _y = y; }
	//플레이어
	RECT getRC() { return _HpBar; }
	// 빌런
	RECT getrc() { return V_HpBar;  }

};

