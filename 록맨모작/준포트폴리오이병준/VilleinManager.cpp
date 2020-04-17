#include "stdafx.h"
#include "VilleinManager.h"
#include "Player.h"

VilleinManager::VilleinManager()
{
}


VilleinManager::~VilleinManager()
{
}

HRESULT VilleinManager::init()
{
	_RockBuster = new RockBuster;
	_RockBuster->init("Bullet", 50, 800);
	_Villein_Count = V_ONE;

	
	return S_OK;
}

void VilleinManager::release()
{

}

void VilleinManager::update()
{
	Bosscollisvion();
	for (_viF_villein = _vF_villein.begin(); _viF_villein != _vF_villein.end(); ++_viF_villein)
	{
		(*_viF_villein)->update();
	}
	_RockBuster->update();

	VilleinFire();
	collisiom();
}

void VilleinManager::render()
{
	for (_viF_villein = _vF_villein.begin(); _viF_villein != _vF_villein.end(); ++_viF_villein)
	{
		(*_viF_villein)->render();
	}
	RECT rc = RectMake(_Player->getPlayer()._x,
		_Player->getPlayer()._y,
		_Player->getPlayerImage()->getFrameWidth(),
		_Player->getPlayerImage()->getFrameHeight());

	//Rectangle(getMemDC(), rc);
	for (int i = 0; i < _vF_villein.size(); i++)
	{
		RECT ins = _vF_villein[i]->getRect();
		//Rectangle(getMemDC(), ins);
	}
	_RockBuster->render();

	sprintf_s(testHP, "%d", _Player->getHP());
	TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, testHP, strlen(testHP));
}

void VilleinManager::SettingVillein()
{
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			Villein* Sky_Villein;
			Sky_Villein = new First_Villein;
			Sky_Villein->SetType(_Villein_Count);

			if (_Villein_Count == V_ONE) {
				Sky_Villein->init("villein1", PointMake(100 + j * 200, 100 + i * 200));
			}
			if (i == 0) {
				Sky_Villein->SetLorR(RIGHT);
			}
			if (i == 1)
			{
				Sky_Villein->SetLorR(LEFT);
			}
			_vF_villein.push_back(Sky_Villein);
		}
		
	}

}

void VilleinManager::SettingBoss()
{
	_Villein_Count++;
	Villein* _MiniBoss;
	_MiniBoss = new MiniBoss;
	_MiniBoss->init();
	_MiniBoss->SetType(1);
	_MiniBoss->SetPlayerAdress(_Player);
	_vF_villein.push_back(_MiniBoss);

}

void VilleinManager::VilleinFire()
{
	
	for (_viF_villein = _vF_villein.begin(); _viF_villein != _vF_villein.end(); ++_viF_villein)
	{
		if ((*_viF_villein)->CountFire())
		{
			RECT rc = (*_viF_villein)->getRect();
			float temp;
			temp = getAngle(rc.left + (rc.right - rc.left) / 2 , rc.bottom + 5, _Player->getPlayer()._x + 80, _Player->getPlayer()._y + 50);
			_RockBuster->RockBusterFire(rc.left + (rc.right - rc.left) / 2, rc.bottom + 5, temp, 8.0f);
		}
	}
	
}

void VilleinManager::removeMop(int arrNum)
{
	_vF_villein.erase(_vF_villein.begin() + arrNum);
}

void VilleinManager::ReMop()
{
	if (_vF_villein.size() == 0)
	{
		SettingVillein();
	}
}

void VilleinManager::collisiom()
{
	for (int i = 0; i < _RockBuster->getVABuster().size(); i++)
	{
		RECT temp;

		//RECT rc = RectMakeCenter(_Player->getPlayerImage()->getX() + _Player->getPlayerImage()->getFrameWidth() / 2,
		//	_Player->getPlayerImage()->getFrameHeight() / 2, _Player->getPlayerImage()->getFrameWidth(), _Player->getPlayerImage()->getFrameHeight());

		RECT rc = RectMakeCenter(_Player->getPlayer()._x, _Player->getPlayer()._y, _Player->getPlayerImage()->getFrameWidth(), _Player->getPlayerImage()->getFrameHeight());

		
		if (IntersectRect(&temp, &_RockBuster->getVABuster()[i]._rc, &rc))
		{
			_Player->HitDmage(10);
			_RockBuster->RemoveRockBuster(i);
			break;
		}
	}
}

void VilleinManager::Bosscollisvion()
{
	for (int i = 0; i < _vF_villein.size(); i++) 
	{
		cout << _vF_villein[i]->getEnemyType() << endl;
		if (_vF_villein[i]->getEnemyType() == V_BOSS)
		{
			
		}
	}
}

