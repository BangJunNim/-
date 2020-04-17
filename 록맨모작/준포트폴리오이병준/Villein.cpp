#include "stdafx.h"
#include "Villein.h"
#include "Player.h"

Villein::Villein()
{
}


Villein::~Villein()
{
}

HRESULT Villein::init()
{
	return S_OK;
}

HRESULT Villein::init(const char * imageName, POINT position)
{
	_imageName = IMAGEMANAGER->addFrameImage(imageName, "Villein/1.bmp",230, 71, 4, 1, true, RGB(255, 0, 255));
	_imageName = IMAGEMANAGER->addFrameImage(imageName, "MiniBoss/MiniBossidle.bmp", 1190, 51, 17, 1, true, RGB(255, 0, 255));

	_RndFireCount = RND->getFromIntTo(1, 270);

	_rc = RectMakeCenter(position.x + 450, position.y, _imageName->getFrameWidth(), _imageName->getFrameHeight());
	_MiniBoss = RectMakeCenter(position.x + (WINSIZEX / 2), position.y + 480, _imageName->getFrameWidth(), _imageName->getFrameHeight());
	_dir = Left;
	//동적 할당 
	_HP = new HPSetting;
	_HP->init_Villein(_rc.left, _rc.right, _imageName->getFrameWidth(), 10, _Move.Villein);
	
	_currentHP = _MaxHP = 100;
	
	return S_OK;
}

void Villein::release()
{
}

void Villein::update()
{
	_count++;
	//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (_count % 8 == 0 && _Move.Villein != V_BOSS ) 
	{
		if (_currentFrameX >= _imageName->getFrameX()) _currentFrameX = 0;
		_currentFrameX = 0;
		_imageName->setFrameX(_currentFrameX);
		_currentFrameX++;
		_count = 0;
	}
	if (_count % 8 == 0 && _Move.Villein == V_BOSS)
	{
		if (_currentFrameX >= _imageName->getMaxFrameX()) _currentFrameX = 0;

		_imageName->setFrameX(_currentFrameX);
		_currentFrameX++;
		_count++;
	}

	_HP->SetX(_rc.left);
	_HP->SetY(_rc.top - 20);
	_HP->update();
	_HP->SetGauge(_currentHP, _MaxHP);

	move();
}

void Villein::render()
{
	draw();
}

void Villein::move()
{
}

void Villein::draw()
{
		_imageName->frameRender(getMemDC(), _rc.left , _rc.top, FrameCount, _currentFrameY);
		FrameCount2++;
		if (FrameCount2 == 10) {
			FrameCount++; 
			if (FrameCount ==4) {
				FrameCount = 0;
			}
			FrameCount2 = 0;
		}

		_HP->Render_Villein(_Move.Villein);
}

bool Villein::CountFire()
{
	_FireCount++;
	if (_RndFireCount != 0) {
		if (_FireCount % _RndFireCount == 0) {
			_FireCount = 0;
			_RndFireCount = RND->getFromFloatTo(1, 270);
			return true;
		}
	}
	return false;
}

void Villein::HitDamage(float Damge)
{
	_currentHP -= Damge;
}
