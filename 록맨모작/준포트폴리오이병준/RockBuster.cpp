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
// �Ѿ� ���
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
// �Ѿ� ���� 
void RockBuster::RockBusterFire(float x, float y, float angle, float speed )//int direction)
{
	if (_RockBusterMax < vRockBuster.size()) return;

	tagRockBuster Buster;
	ZeroMemory(&Buster, sizeof(tagRockBuster));

	Buster.RockBusterImage = IMAGEMANAGER->findImage(_ImageName);  //�̹��� ã�� 
	Buster._speed = speed;
	//Buster._radius = Buster.RockBusterImage->getWidth() / 2;  // �߻�ü�� �������� �ҷ����� ������ �̹����� �� 
	// �߻� ��ǥ ���� 
	Buster._x = Buster._FireX = x;
	Buster._y = Buster._FireY = y; 
	Buster._angle = angle;  // �߻�ü�� ������ �̷���
	//Buster.currentFrameY = direction;
	//�߻�ü ����� 
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

//������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������//

HRESULT NomalAttack::init(int BulletMax, float range)
{
	
		// tagBulletŸ������ ������ �����.
		// ZeroMemory�Լ��� �̿��Ͽ� �޸𸮻� ���? �� �����ش�.
		tagRockBuster  bullet;
		ZeroMemory(&bullet, sizeof(bullet));

		bullet.RockBusterImage = new image;													// �Ҵ��� �޴´�.
		bullet.RockBusterImage->init("Player_Fire/1.bmp", 400, 156, 4, 2, true, RGB(255, 0, 255));// �̹����� �����Ѵ�.
		bullet._speed = 10.0f;															// �Ѿ��� ���ǵ带 �����Ѵ�.
		bullet._isFire = true;															// �� �Ѿ��� �̻��

		vRockBuster.push_back(bullet);														// ���Ϳ� �Ѿ� ������ �����Ѵ�.
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

