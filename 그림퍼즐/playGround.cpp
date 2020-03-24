#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//초기화는 여기다 해라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HRESULT playGround::init()
{
	gameNode::init();
	
	_background = new image;
	_background->init("900.bmp", 900, WINSIZEY, false, RGB(0, 0, 0));

	_sample = new image;
	_sample->init("900.bmp", 200, 200, false, RGB(0, 0, 0));

	// 1중 배열인데 2중 배열처럼 사용할려고 
	// 1중 배열 123456789																											   	x(0)  x (300)  x(600)   900
																																// y(0)	   
	for (int i = 0; i < 9; i++)																									// y(300)  
	{																															// y(600)  
		if (i % 3 == 0)         _point[i].x = _puzzle[i].x = 0;  // 나누기 할 때 나오는 숫자 0 들은 x 값 좌표 0 을 가진다. 		////
		if (i % 3 == 1)         _point[i].x = _puzzle[i].x = 300;																  
		if (i % 3 == 2)         _point[i].x = _puzzle[i].x = 600;																  
																																  
		if (i < 3)            _point[i].y = _puzzle[i].y = 0;																	  // i가 3보다 작을 때 숫자 는 y 좌표 0을 가진다. 
		if (2 < i && i < 6)      _point[i].y = _puzzle[i].y = 300;																  //  i 가 2보다는 크고 6보다는 작은 숫자는  y의   300좌표값 
		if (5 < i && i < 9)      _point[i].y = _puzzle[i].y = 600;																  //
																																  
		_puzzle[i].rc = RectMake(_point[i].x, _point[i].y, 300, 300);															  //  렉트 300x 300 크기 만들고 . 
		//_point는 좌표값을 쉽게쓰기위해 저장해둔것임.
	}

	for (int i=0;i < 9;i++) //퍼즐 이미지만  셔플을 돌린다.
	{
		int temp1, temp2;
		int a = RND->getInt(8);
		int b = RND->getInt(8);

		temp1 = _puzzle[a].x;
		_puzzle[a].x = _puzzle[b].x;
		_puzzle[b].x = temp1;

		temp2 = _puzzle[a].y;
		_puzzle[a].y = _puzzle[b].y;
		_puzzle[b].y = temp2;
	}

	_white = 8;  //화이트는 고정 랙트 


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

	for (int i = 0;i < 9;i++)  // 화이트 렉트 움직임 계산. 
	{
		if (PtInRect(&_puzzle[i].rc, _ptMouse) && KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			if (i == _white - 3 || i == _white - 1 || i == _white + 1 || i == _white + 3)
			{
				int temp3;
				int temp4;

				temp3 = _puzzle[i].x;
				_puzzle[i].x = _puzzle[_white].x;
				_puzzle[_white].x = temp3;

				temp4 = _puzzle[i].y;
				_puzzle[i].y = _puzzle[_white].y;
				_puzzle[_white].y = temp4;

				_white = i;
			}
		}

	}

}

//여기다 그려라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::render(HDC hdc)
{
	//건들지마라
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================

	_sample->render(backDC, 950, 0);

	for (int i = 0;i < 9;i++)  // 그림 섞음. 
	{
		if (i != _white)
		{
			_background->render(backDC, _point[i].x, _point[i].y, _puzzle[i].x, _puzzle[i].y, 300, 300);
		}
	}

	//===================================================
	//딱 말했다
	this->getBackBuffer()->render(hdc, 0, 0);
}


