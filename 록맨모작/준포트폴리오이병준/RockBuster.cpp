#include "stdafx.h"
#include "RockBuster.h"


RockBuster::RockBuster(){
	
}


RockBuster::~RockBuster()
{
}

HRESULT RockBuster::init(const char * ImageName, int RockBusterMax, float Range)
{
	_ImageName = ImageName;
	_RockBusterMax = RockBusterMax;
	_Range = Range;
	return S_OK;
}

void RockBuster::release()
{
}

void RockBuster::update()
{
	RockBusterMove();
}
// 총알 출력
void RockBuster::render()
{
	for (viRockBuster = vRockBuster.begin(); viRockBuster != vRockBuster.end(); ++viRockBuster)
	{
		viRockBuster->RockBusterImage->frameRender(getMemDC(), viRockBuster->_rc.left, viRockBuster->_rc.top);
		/*viRockBuster->RockBusterImage->frameRender(getMemDC(), viRockBuster->_x, viRockBuster->_y,
			viRockBuster->currentFrameX, viRockBuster->currentFrameY);
		viRockBuster->count++;

		if (viRockBuster->count % 7 == 0)
		{
			viRockBuster->currentFrameX++;
			if (viRockBuster->currentFrameX >= viRockBuster->RockBusterImage->getMaxFrameX())
			{
				viRockBuster->currentFrameX = 0;
			}
		}*/
	}

}
// 총알 생성 
void RockBuster::RockBusterFire(float x, float y, float angle, float speed )//int direction)
{
	if (_RockBusterMax < vRockBuster.size()) return;

	tagRockBuster Buster;
	ZeroMemory(&Buster, sizeof(tagRockBuster));

	Buster.RockBusterImage = IMAGEMANAGER->findImage(_ImageName);  //이미지 찾고 
	Buster._speed = speed;
	//Buster._radius = Buster.RockBusterImage->getWidth() / 2;  // 발사체의 반지름은 불러오는 프레임 이미지의 반 
	// 발사 좌표 설정 
	Buster._x = Buster._FireX = x;
	Buster._y = Buster._FireY = y; 
	Buster._angle = angle;  // 발사체의 각도는 이렇게
	//Buster.currentFrameY = direction;
	//발사체 만들기 
	Buster._rc = RectMakeCenter(Buster._x, Buster._y, Buster.RockBusterImage->getFrameWidth(), Buster.RockBusterImage->getFrameHeight());
	
	vRockBuster.push_back(Buster);
}

void RockBuster::RockBusterMove()
{
	for (viRockBuster = vRockBuster.begin(); viRockBuster != vRockBuster.end();)
	{
		viRockBuster->_x += cosf(viRockBuster->_angle) *viRockBuster->_speed;
		viRockBuster->_y += -sinf(viRockBuster->_angle) *viRockBuster->_speed;

		viRockBuster->_rc = RectMakeCenter(viRockBuster->_x, viRockBuster->_y, viRockBuster->RockBusterImage->getFrameWidth(), viRockBuster->RockBusterImage->getFrameHeight());

		if (_Range < getDistance(viRockBuster->_x, viRockBuster->_y, viRockBuster->_FireX, viRockBuster->_FireY))
		{
			viRockBuster = vRockBuster.erase(viRockBuster);
		}
		else ++viRockBuster;
	}

}
void RockBuster::RemoveRockBuster(int arrNum)
{
	vRockBuster.erase(vRockBuster.begin() + arrNum);
}

//─────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────//

HRESULT NomalAttack::init(int BulletMax, float range)
{
	
		// tagBullet타입으로 변수를 만든다.
		// ZeroMemory함수를 이용하여 메모리상 찌꺼기? 를 지워준다.
		tagRockBuster  bullet;
		ZeroMemory(&bullet, sizeof(bullet));

		bullet.RockBusterImage = new image;													// 할당을 받는다.
		bullet.RockBusterImage->init("Player_Fire/1.bmp", 400, 156, 4, 2, true, RGB(255, 0, 255));// 이미지를 저장한다.
		bullet._speed = 10.0f;															// 총알의 스피드를 저장한다.
		bullet._isFire = true;															// 이 총알은 미사용

		vRockBuster.push_back(bullet);														// 벡터에 총알 정보를 저장한다.
	//_BullerMax = BulletMax;
		

	_Range = range;
	return S_OK;
}

void NomalAttack::release()
{
	for (viRockBuster = vRockBuster.begin(); viRockBuster != vRockBuster.end(); ++viRockBuster)
	{
		SAFE_RELEASE(viRockBuster->RockBusterImage);
		SAFE_DELETE(viRockBuster->RockBusterImage);
	}
	vRockBuster.clear();
}

void NomalAttack::update()
{
	Move();
}

void NomalAttack::render()
{
	for (viRockBuster = vRockBuster.begin(); viRockBuster != vRockBuster.end(); ++viRockBuster) {
		if (!viRockBuster->_isFire) continue;

		viRockBuster->RockBusterImage->frameRender(getMemDC(), viRockBuster->_rc.left, viRockBuster->_rc.top, 3, 1);
	
	}
}

void NomalAttack::fire(float x, float y, int Dir)
{
	tagRockBuster ins;
	ZeroMemory(&ins, sizeof(ins));
	ins.RockBusterImage = IMAGEMANAGER->findImage("1Fire");
	ins._isFire = true;
	ins._x = ins._FireX = x;
	ins._y = ins._FireY = y;
	if (Dir == 0)
		ins._speed = -10.0f;
	else
		ins._speed = 10.0f;
	ins._rc = RectMakeCenter(ins._x, ins._y, ins.RockBusterImage->getFrameWidth(),
		ins.RockBusterImage->getFrameHeight());
	vRockBuster.push_back(ins);

}


void NomalAttack::Move()
{


	for (viRockBuster = vRockBuster.begin(); viRockBuster != vRockBuster.end(); ++viRockBuster)
	{
		if (!viRockBuster->_isFire) continue;

		viRockBuster->_x -= viRockBuster->_speed;
		viRockBuster->_rc = RectMakeCenter(viRockBuster->_x, viRockBuster->_y, viRockBuster->RockBusterImage->getFrameWidth(),
											viRockBuster->RockBusterImage->getFrameHeight());

		if (_Range < getDistance(viRockBuster->_FireX, viRockBuster->_FireY, viRockBuster->_x, viRockBuster->_y))
		{
			viRockBuster->_isFire = false;
		}
	}
}

void NomalAttack::Remove(int arrNum)
{

	vRockBuster.erase(vRockBuster.begin()+arrNum);
}

