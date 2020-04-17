#include "stdafx.h"
#include "playGround.h"
 #pragma comment(linker,"/entry:WinMainCRTStartup /subsystem:console") // 좌표 확인

playGround::playGround()
{
	
	IMAGEMANAGER->addImage("HPFRONT", "HpBar/enemyHPFornt.bmp", 200, 40, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("HPBACK", "HpBar/enemyHPBack.bmp", 200, 40, true, RGB(255, 0, 255));
}


playGround::~playGround()
{
}

//초기화는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HRESULT playGround::init()
{
	gameNode::init(true);
	//BackGround 설정 
	_index = 0;
	_BackGroundIn = 0;
	_BackGroundOut = 255;
	_StartButton = 0;
	_startCount = 0;

	IMAGEMANAGER->addImage("Main", "Main.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("BackGround", "배경.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BackGroundObject", "맵게이지.bmp", 840, 35, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BackGroundObject2", "맵게이지중간.bmp", 840, 35, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("BackGroundObject3", "맵게이지오른쪽.bmp", 840, 35, 6, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Start", "StartButton.bmp",440 ,56 , true, RGB(255, 0, 255));
	
	_changeScreen = Screen;
	startCheck = true;
	

	_player = new Player;
	_player->init();

	_First_Villein = new VilleinManager;
	_First_Villein->init();
	_First_Villein->SettingVillein();

	_player->setEnemyAddressLink(_First_Villein);
	_First_Villein->setPlayerAddressLink(_player);

	return S_OK;
}

//메모리 해제는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::release()
{
	gameNode::release();

}

//연산은 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::update()
{
	gameNode::update();
	//  처음Screen 화면 설정  
	_StartButton -= 3;

	if (Screen == _changeScreen)
	{
		if (KEYMANAGER->isToggleKey('R'))
		{

			if (_BackGroundOut >= 1)
			{
				_BackGroundOut -= 8;
			}
			else
			{
				_changeScreen = Screen2;
				startCheck = true;
			}
		}
	}

	if (Screen2 == _changeScreen)
	{
		if (startCheck) 
		{
			_player->init();
			startCheck = false;
		}
		if(!startCheck)
		{
			_player->update();
		}
		if (_count % 5 == 0)
		{
			_index++;
		}
		if (_index > IMAGEMANAGER->findImage("BackGroundObject")->getMaxFrameX())
		{
			_index = 0;
		}
		if (_First_Villein->getVillein().size() == 0)
		{
			_First_Villein->SettingBoss();
		}
		
	}
		_count++;
		_First_Villein->update();
}

//여기다 그려라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//==================================================
	//cout << _ptMouse.x << " , " << _ptMouse.y << endl; // 좌표 확인 용 

	


	switch (_changeScreen)
	{
	case playGround::Screen:  // 여기에 추가 할수 있는 것  코인 시스템 (시간 남을 때 구현)
		IMAGEMANAGER->findImage("Main")->alphaRender(getMemDC(), _BackGroundOut);
		IMAGEMANAGER->findImage("Start")->alphaRender(getMemDC(),420,670, _StartButton);
		

		break;

	case playGround::Screen2:  //  잡몹,중간 보스, 플레이어, 투명 벽 , ui 등 
		
		//Rectangle(getMemDC(), WALL1);
		//Rectangle(getMemDC(), WALL2);
		//RectangleMake(getMemDC(), _Wall._rc3.left, _Wall._rc3.top, _Wall._rc3.right, _Wall._rc3.bottom);
		IMAGEMANAGER->findImage("BackGroundObject")->frameRender(getMemDC(), 258, 709, _index,0);
		IMAGEMANAGER->findImage("BackGroundObject2")->frameRender(getMemDC(), 578, 709, _index, 0);
		IMAGEMANAGER->findImage("BackGroundObject3")->frameRender(getMemDC(), 906, 709, _index, 0);
		IMAGEMANAGER->findImage("BackGround")->render(getMemDC());
		_player->render();

		_First_Villein->render();


		break;

	default:
		break;

	}

	//===================================================
	//딱 말했다
	_backBuffer->render(getHDC(), 0, 0);
}
