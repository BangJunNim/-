#include "stdafx.h"
#include "HPSetting.h"


HPSetting::HPSetting()
{
}


HPSetting::~HPSetting()
{
}

HRESULT HPSetting::init_Player(float x, float y)
{
	_x = x, _y = y;
	// 체력 바의 렉트 생성
	// 렉트 위 불러올 이미지 정보 
	_HpBarFront = IMAGEMANAGER->addImage("PlayerHp_B", "HpBar/HP_Back.bmp", 40, 161, true, RGB(255, 0, 255));
	_HpBarBack = IMAGEMANAGER->addImage("PlayerHp_F", "HpBar/HpFront.bmp", 17, 95, true, RGB(255, 0, 255));

	_HpBar = RectMakeCenter(x, y,_HpBarFront->getWidth(),_HpBarFront->getHeight());
	_HpFront = RectMakeCenter(x , y-20, _HpBarBack->getWidth(), _HpBarBack->getHeight());
	 
	
	P_width = _HpBarBack->getWidth();

	return S_OK;
}

HRESULT HPSetting::init_Villein(float x, float y, int width, int height, int type)
{
	_x = x, _y = y;

	V_HpBar = RectMake(x, y, width, height);
	_HpBarBack = IMAGEMANAGER->addImage("V_HpBack", "HpBar/enemyHPBack.bmp", width, height, true, RGB(255, 0, 255));
	_HpBarFront = IMAGEMANAGER->addImage("V_HpFront", "HpBar/enemyHPFornt.bmp", width, height, true, RGB(255, 0, 255));
	

	_width = _HpBarBack->getWidth();

	return S_OK;
}

void HPSetting::release()
{
}
///////////////////////////////////////////////////////////////////////////////////
void HPSetting::update()
{
}

void HPSetting::Render_Player()
{
	//Rectangle(getMemDC(), _HpBar);
	IMAGEMANAGER->render("PlayerHp_B", getMemDC(), _HpBar.left,_HpBar.top);

	//Rectangle(getMemDC(), _HpFront);
	IMAGEMANAGER->render("PlayerHp_F", getMemDC(), _HpFront.left , _HpFront.top,0,0, IMAGEMANAGER->findImage("PlayerHp_F")->getWidth(), P_width);

}

void HPSetting::Render_Villein(int type)
{

	//IMAGEMANAGER->render("V_HpBack", getMemDC(), _HpBar.left + _HpBarBack->getWidth() / 2 - 5,
	//	_y + _HpBarBack->getHeight() / 2, 0, 0, _hight, _HpBarBack->getHeight());
	//IMAGEMANAGER->render("V_HpFront", getMemDC(), _HpBar.left + _HpBarBack->getWidth() / 2 - 5,
	//	_y + _HpBarBack->getHeight() / 2, 0, 0, _HpBarBack->getWidth(), _HpBarBack->getHeight());

}
	
	

void HPSetting::SetGauge(float currentGauge, float MaxGauge)
{
	if (_HpFront.bottom >= _HpFront.top) {
		P_width = (currentGauge / MaxGauge) * _HpBarBack->getHeight();
		_HpFront.top = 235 + (1.f - (currentGauge / MaxGauge)) * _HpBarBack->getHeight();
	}
}
