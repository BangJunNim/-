#include "stdafx.h"
#include "MiniBoss.h"


MiniBoss::MiniBoss()
{
}


MiniBoss::~MiniBoss()
{
}

HRESULT MiniBoss::init()
{
	IMAGEMANAGER->addFrameImage("Boss", "MinBoss/Boss.bmp", 3400, 120, 17, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("idle", "MinBoss/Bossidle.bmp", 600, 224, 3, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Walk", "MinBoss/BossWalk.bmp", 2000, 224, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("DashAttack", "MinBoss/BossAttack.bmp", 3400, 224, 17, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Attack", "MinBoss/Attack2.bmp",1200, 224, 6, 2, true, RGB(255, 0, 255));
	// º¸½º ÁÂÇ¥ 
	Boss_._x = 950; Boss_._y = 570;

	_count = _index = 0;
	_currentX = _currentY = 0;
	_BossState = Boss_Boss;
	_DirR = RIGHT2;
	_DirL = LEFT2;
	Boss_._speed = 5;
	__Boss = IMAGEMANAGER->findImage("Boss");
	_currentMaxX = IMAGEMANAGER->findImage("Boss")->getMaxFrameX();
	_currentMaxY = IMAGEMANAGER->findImage("Boss")->getMaxFrameY();

	_Boss = RectMakeCenter(Boss_._x + __Boss->getFrameWidth() / 2,
		Boss_._y + __Boss->getFrameHeight() / 2, 
		__Boss->getFrameWidth(),
		__Boss->getFrameHeight());

	_B = RectMakeCenter(Boss_._x +__Boss->getFrameWidth()/2, Boss_._y+ __Boss->getFrameHeight() / 2, 700, 150);
	interver = 0;
	attack2interver = 0;
	return S_OK;
}


void MiniBoss::release()
{
}

void MiniBoss::update()
{
	BossFrame();

	SwitchImage();

	
	RECT trigger = RectMake(_P->getPlayer()._x,
		_P->getPlayer()._y,
		_P->getPlayerImage()->getFrameWidth(),
		_P->getPlayerImage()->getFrameHeight());
	RECT collision = _Boss;
	RECT temp;
	int a = 20;
	interver++;
	if (interver > 50) {
		if (_BossState == Boss_idle) {
			_BossState = Boss_run;
		}
		interver2++;
		if (IntersectRect(&temp, &trigger, &collision))
		{
			_BossState = Boss_Attack2;
		}
		if (interver2 < 100 && _BossState != Boss_Attack2) {
			_BossState = Boss_run;
			interver2 = 0;
		}
	}
	else
	{
		_BossState = Boss_idle;
	}
	

	_Boss = RectMakeCenter(Boss_._x + __Boss->getFrameWidth() / 2, Boss_._y + __Boss->getFrameHeight() / 2, __Boss->getFrameWidth(), __Boss->getFrameHeight());
	RECT temp1;
	RECT ins = WALL1;
	RECT ins2 = WALL2;
	

	switch (_BossState) {
	case Boss_Boss:
		break;
	case Boss_idle:
		break;
	case Boss_Attack:
		break;
	case Boss_Attack2:
		attack2interver++;
		if (attack2interver > 10) {
			Boss_._x += Boss_._speed;
			
			if (IntersectRect(&temp1, &_Boss, &ins)) {
				Boss_._x += Boss_._speed;
				Boss_._x = ins.right + __Boss->getFrameWidth() / 2.f;
				_BossState = Boss_run;
			}
			else if (IntersectRect(&temp1, &_Boss, &ins2)) {
				Boss_._x -= Boss_._speed;
				Boss_._x = ins2.left - __Boss->getFrameWidth();
				_BossState = Boss_run;
			}
		}
		break;
	case Boss_run:
		move();
		break;
	}

}

void MiniBoss::move()
{

	Boss_._x += Boss_._speed;
	_Boss = RectMakeCenter(Boss_._x + __Boss->getFrameWidth() / 2, Boss_._y + __Boss->getFrameHeight() / 2,__Boss->getFrameWidth(),__Boss->getFrameHeight());
	RECT temp;
	RECT ins = WALL1;
	RECT ins2 = WALL2;
	if (IntersectRect(&temp, &_Boss, &ins))
	{
		Boss_._speed *= -1;
	}
	else if (IntersectRect(&temp, &_Boss, &ins2))
	{
		Boss_._speed *= -1;
	}
	
}


void MiniBoss::render()
{
	// Rectangle(getMemDC(), _Boss);
	__Boss->frameRender(getMemDC(), _Boss.left, _Boss.top, _currentX, _currentY);
	
}


void MiniBoss::BossFrame()
{
	if (Boss_._speed < 0) {
		_currentY = 1;
	}
	else {
		_currentY = 0;
	}
	_count++;
	if (_count % 7 == 0) {
		if (Boss_._speed < 0) {
			_currentX--;
			if (_currentX < 0)
			{
				_currentX = _currentMaxX;
				_currentY = 1;
			}
		}
		else {
			_currentX++;
			if (_currentX > _currentMaxX)
			{
				_currentX = 0;
				_currentY = 0;
			}
		}
	}
}

			/*if (__Boss == IMAGEMANAGER->findImage("Boss"))
			{

				__Boss = IMAGEMANAGER->findImage("Walk");
				_currentMaxX = __Boss->getMaxFrameX();
				_currentX = 0;
			}
			if (__Boss == IMAGEMANAGER->findImage("Walk"))
			{

				_currentX = 0;

			}
			else
			{
				_currentX = 0;
			}*/
	/*	}
	}
	if (Boss_._speed < 0) {
		_currentY = 1;
	}
	else {
		_currentY = 0;
	}*/


void MiniBoss::SwitchImage()
{
	switch (_BossState)
	{
	case Boss_Boss:
		__Boss = IMAGEMANAGER->findImage("Boss"); 
		_currentMaxX = __Boss->getMaxFrameX();
		break;
		
	case Boss_idle:
		__Boss = IMAGEMANAGER->findImage("idle");
		_currentMaxX = __Boss->getMaxFrameX();
		break;
	case Boss_run:
		__Boss = IMAGEMANAGER->findImage("Walk");
		_currentMaxX = __Boss->getMaxFrameX();
		break;
	case Boss_Attack :
		__Boss = IMAGEMANAGER->findImage("Attack");
		_currentMaxX = __Boss->getMaxFrameX();
		break;
	case Boss_Attack2:
		__Boss = IMAGEMANAGER->findImage("DashAttack");
		_currentMaxX = __Boss->getMaxFrameX();
		break;
	default:
		break;
	}

}

void MiniBoss::collision()
{
}

void MiniBoss::hitDmage(float Dmage)
{
}
