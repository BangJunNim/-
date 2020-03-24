#include "stdafx.h"
#include "playGround.h"

#define D 180/PI

playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init();
	// 이미지 소환.
	_BG = new image;
	_BG->init("배경.bmp", 1100, 800, false, RGB(0, 0, 0));
	_right = new image;
	_right->init("타겟반대.bmp", 60, 60, true, RGB(255, 0, 255));
	_left = new image;
	_left->init("타겟.bmp", 60, 60, true, RGB(255, 0, 255));
	_Aim = new image;
	_Aim->init("오른쪽에임.bmp", 60, 60, true, RGB(255, 0, 255));
	_PlayerM = new image;
	_PlayerM->init("정면.bmp", 50, 60, true, RGB(255, 0, 255));
	_PlayerR = new image;
	_PlayerR->init("오른쪽사격.bmp", 50, 60, true, RGB(255, 0, 255));
	_PlayerL = new image;
	_PlayerL->init("왼쪽사격.bmp", 50, 60, true, RGB(255, 0, 255));

	_Player.left = WINSIZEX / 2 - 25;
	_Player.top = WINSIZEY / 2 + 320;

	char str[128];
	for (int i = 0; i < 10; i++) {
		sprintf_s(str, "%d.bmp", i);
		_num[i] = new image;
		_num[i]->init(str,20, 40, true, RGB(255, 0, 255));
	}


	// 왼쪽 에임 
	_AIM.x = WINSIZEX /2 - 80;
	_AIM.y = WINSIZEY /2 - 100; 

	//오른쪽 에임 
	__AIM.x = WINSIZEX / 2 + 80;
	__AIM.y = WINSIZEY / 2 - 100;

	// 오른쪽 타겟 설정값 
	for (int i = 0; i < Target; i++) {

		__Target[i].isfire = false;
		__Target[i].gravity = 0;
		__Target[i].speed = 11.0f;
	}
	// 왼쪽 타겟 설정값. 
	for (int i = 0; i < S_Target; i++) {

		S_TargeT[i].isfire = false;
		S_TargeT[i].gravity = 0;
		S_TargeT[i].speed = 14.5f;

	}


	return S_OK;
}

void playGround::release()
{
	gameNode::release();

}

void playGround::update()
{
	gameNode::update();


	_count++;  // 오른쪽 발사 시간 
	if (_count > 200) {
		Targetfire();
		_count = 0;
	}

	S_count++; // 왼쪽  발사 시간 
	if (S_count > 280) {
		Targetfire_2();
		S_count = 0;
	}

	_AIM.y += 0.5f; // 내려가게 . 
	__AIM.y += 0.5f;
	TargetMove_2();
	TargetMove();
	
	if (KEYMANAGER->isOnceKeyDown('D'))
	{
		for (int i = 0; i < BULLETMAX; i++) {
			if (__Target[i].x < __AIM.x + 30 && __Target[i].x > __AIM.x - 30 && __Target[i].y > __AIM.y - 30 && __Target[i].y < __AIM.y + 30)
			{
				__Target[i].isfire = false;
				_score++;
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		for (int i = 0; i < BULLETMAX; i++) {
			if (S_TargeT[i].x > _AIM.x - 30 && S_TargeT[i].x < _AIM.x + 30 && S_TargeT[i].y > _AIM.y - 30 && S_TargeT[i].y < _AIM.y + 30)
			{
				S_TargeT[i].isfire = false;
				_score++;
			}
		}
	}





}

void playGround::render(HDC hdc)
{
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================

	// 배경 
	_BG->render(backDC, 0, 0);

	// 타겟 이미지!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	for (int i = 0; i < Target; i++)
	{
		if (!__Target[i].isfire) continue;
		_left->render(backDC, __Target[i].x - 30, __Target[i].y - 30);
	}
	for (int i = 0; i < S_Target; i++) {
		if (!S_TargeT[i].isfire) continue;
		_right->render(backDC, S_TargeT[i].x - 30, S_TargeT[i].y - 30);
	}
	_PlayerM->render(backDC, _Player.left, _Player.top);
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_PlayerM = _PlayerL;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		_PlayerM = _PlayerR;
	}


	
	_Aim->render(backDC, _AIM.x - 30, _AIM.y - 30);  // 에임 이미지 . 
	_Aim->render(backDC, __AIM.x - 30, __AIM.y - 30);// 에임 이미지 . 

	if (_score > 9) {
		int a;
		int b;
		a = _score / 10;
		b = _score % 10;
		_num[a]->render(backDC, 50, 50);
		_num[b]->render(backDC, 70, 50);
	}
	else {

		_num[_score]->render(backDC, 50, 50);
	}


	//===================================================
	this->getBackBuffer()->render(hdc, 0, 0);
}
// 오른쪽 타겟 설정 
void playGround::Targetfire()
{
	for (int i = 0; i < Target; i++) {
		if (__Target[i].isfire) continue;

		__Target[i].isfire = true; 
		__Target[i].x = WINSIZEX / 2 + 520;  // 타겟의 시작 위치
		__Target[i].y = WINSIZEY / 2 + 230;  // 타겟의 시작 위치 
		__Target[i].angle = PI / RND->getFromFloatTO(3.0f, 9.0f);
	
		break;
	}
}

void playGround::TargetMove()
{
	for (int i = 0; i < Target; i++) {

		if (!__Target[i].isfire) continue;

		__Target[i].gravity += 0.03f;
		__Target[i].x -= cosf(__Target[i].angle) * __Target[i].speed; // 오른쪽에서 왼쪽으로 나오게 .
		__Target[i].y += -sinf(__Target[i].angle) * __Target[i].speed + __Target[i].gravity; // y 축 중력 갑 ㅅ 

		if (__Target[i].x + 15 < 0 || __Target[i].y + 15 < 0 || __Target[i].y - 15 > WINSIZEY)
		{
			__Target[i].isfire = false;
			__Target[i].gravity = 0;
		}
		AIMControl(__Target[i], __AIM);  // 오른쪽 
		sprintf_s(buf2, "%d", i);
	}

}

// 왼쪽 타겟 설정 
void playGround::Targetfire_2()
{
	{
		for (int i = 0; i < S_Target; i++) {
			if (S_TargeT[i].isfire) continue;

			S_TargeT[i].isfire = true;
			S_TargeT[i].x = WINSIZEX / 2 - 520;  // 타겟의 시작 위치
			S_TargeT[i].y = WINSIZEY / 2 + 230;  // 타겟의 시작 위치 
			S_TargeT[i].angle = PI / RND->getFromFloatTO(4.0f, 12.0f);
			break;
		}
	}
}

void playGround::TargetMove_2()
{
	for (int i = 0; i < S_Target; i++){
	
		if (!S_TargeT[i].isfire) continue;
		S_TargeT[i].gravity += 0.06;
		S_TargeT[i].x += cosf(S_TargeT[i].angle) * S_TargeT[i].speed;
		S_TargeT[i].y += -sinf(S_TargeT[i].angle)* S_TargeT[i].speed + S_TargeT[i].gravity;
		if (S_TargeT[i].x - 15 > WINSIZEX || S_TargeT[i].y + 15 < 0 || S_TargeT[i].y - 15 > WINSIZEY)
		{
			S_TargeT[i].isfire = false;
			S_TargeT[i].gravity = 0;
		}
		AIMControl(S_TargeT[i], _AIM);  //왼쪾 에임 
		sprintf_s(buf, "%d", i);
	}
}

void playGround::AIMControl(_Target T, _Fire &fire)
{
	fire.y = T.y;
}


