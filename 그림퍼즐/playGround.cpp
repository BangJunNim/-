#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

//�ʱ�ȭ�� ����� �ض�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
HRESULT playGround::init()
{
	gameNode::init();
	
	_background = new image;
	_background->init("900.bmp", 900, WINSIZEY, false, RGB(0, 0, 0));

	_sample = new image;
	_sample->init("900.bmp", 200, 200, false, RGB(0, 0, 0));

	// 1�� �迭�ε� 2�� �迭ó�� ����ҷ��� 
	// 1�� �迭 123456789																											   	x(0)  x (300)  x(600)   900
																																// y(0)	   
	for (int i = 0; i < 9; i++)																									// y(300)  
	{																															// y(600)  
		if (i % 3 == 0)         _point[i].x = _puzzle[i].x = 0;  // ������ �� �� ������ ���� 0 ���� x �� ��ǥ 0 �� ������. 		////
		if (i % 3 == 1)         _point[i].x = _puzzle[i].x = 300;																  
		if (i % 3 == 2)         _point[i].x = _puzzle[i].x = 600;																  
																																  
		if (i < 3)            _point[i].y = _puzzle[i].y = 0;																	  // i�� 3���� ���� �� ���� �� y ��ǥ 0�� ������. 
		if (2 < i && i < 6)      _point[i].y = _puzzle[i].y = 300;																  //  i �� 2���ٴ� ũ�� 6���ٴ� ���� ���ڴ�  y��   300��ǥ�� 
		if (5 < i && i < 9)      _point[i].y = _puzzle[i].y = 600;																  //
																																  
		_puzzle[i].rc = RectMake(_point[i].x, _point[i].y, 300, 300);															  //  ��Ʈ 300x 300 ũ�� ����� . 
		//_point�� ��ǥ���� ���Ծ������� �����صа���.
	}

	for (int i=0;i < 9;i++) //���� �̹�����  ������ ������.
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

	_white = 8;  //ȭ��Ʈ�� ���� ��Ʈ 


	return S_OK;
}

//�޸� ������ ����� �ض�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::release()
{
	gameNode::release();

}

//������ ����� �ض�!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::update()
{
	gameNode::update();

	for (int i = 0;i < 9;i++)  // ȭ��Ʈ ��Ʈ ������ ���. 
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

//����� �׷���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::render(HDC hdc)
{
	//�ǵ�������
	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================

	_sample->render(backDC, 950, 0);

	for (int i = 0;i < 9;i++)  // �׸� ����. 
	{
		if (i != _white)
		{
			_background->render(backDC, _point[i].x, _point[i].y, _puzzle[i].x, _puzzle[i].y, 300, 300);
		}
	}

	//===================================================
	//�� ���ߴ�
	this->getBackBuffer()->render(hdc, 0, 0);
}


