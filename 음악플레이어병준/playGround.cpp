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
	gameNode::init(true);
	//�뷡 �̹��� 
	IMAGEMANAGER->addImage("a1", "Image/Song1.bmp",250, 50,true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a2", "Image/Song2.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a3", "Image/Song3.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a4", "Image/Song4.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a5", "Image/Song5.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a6", "Image/Song6.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a7", "Image/Song7.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a8", "Image/Song8.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a9", "Image/Song9.bmp", 250, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("a10", "Image/Song10.bmp", 250, 50, true, RGB(255, 0, 255));
	
	// ui �̹��� 
	IMAGEMANAGER->addImage("Pause", "Image/Pause.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Start", "Image/Player.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Next", "Image/Next.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Last", "Image/Last.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Plus", "Image/Plus.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Minus", "Image/Minus.bmp", 50, 50, true, RGB(255, 0, 255));
	//��� �̹���
	IMAGEMANAGER->addImage("0", "Image/BackGround.bmp", 600, 400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("1", "BackGround/1.bmp",600,400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("2", "BackGround/2.bmp",600,400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("3", "BackGround/3.bmp",600,400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("4", "BackGround/4.bmp",600,400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("5", "BackGround/5.bmp",600,400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("6", "BackGround/6.bmp",600,400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("7", "BackGround/7.bmp",600,400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("8", "BackGround/8.bmp", 600, 400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("9", "BackGround/9.bmp", 600, 400, false, RGB(0, 0, 0));
	IMAGEMANAGER->addImage("10", "BackGround/10.bmp", 600, 400, false, RGB(0, 0, 0));
	// ����
	SOUNDMANAGER->addSound("BGM1", "BGM/ȣ��������.mp3", true, false);
	SOUNDMANAGER->addSound("BGM2", "BGM/�̴��߻�.mp3", true, false);
	SOUNDMANAGER->addSound("BGM3", "BGM/�ǿ�Ʈ.mp3", true, false);
	SOUNDMANAGER->addSound("BGM4", "BGM/�ǾƳ뵵��.mp3", true, false);
	SOUNDMANAGER->addSound("BGM5", "BGM/��.mp3", true, false);
	SOUNDMANAGER->addSound("BGM6", "BGM/����������������Ѱ���.mp3", true, false);
	SOUNDMANAGER->addSound("BGM7", "BGM/���̴ٰ�.mp3", true, false);
	SOUNDMANAGER->addSound("BGM8", "BGM/�ܿ�ձ�.mp3", true, false);
	SOUNDMANAGER->addSound("BGM9", "BGM/��Ŀ.mp3", true, false);
	SOUNDMANAGER->addSound("BGM10", "BGM/Panda.mp3", true, false);

	
	// ��Ʈ 
	
	_RC.MousePointer = RectMakeCenter(_ptMouse.x, _ptMouse.y, 20, 20);
	_RC.LAST = RectMakeCenter(100, 350, 50, 50);
	_RC.NEXT = RectMakeCenter(500, 350, 50, 50);
	_RC.Player = RectMakeCenter(300, 350, 50, 50);
	_RC.Pause = RectMakeCenter(300, 350, 50, 50);
	_RC.Plus = RectMakeCenter(30, 300, 50, 50);
	_RC.Minus = RectMakeCenter(30, 370, 50, 50);
	//
	
	_RC.Time = RectMakeCenter(150, 340,240,50);
	//_RC.Song1 = RectMakeCenter(450, 50, 250, 50);
	//_RC.Song2 = RectMakeCenter(450, 100, 250, 50);
	//_RC.Song3 = RectMakeCenter(450, 150, 250, 50);
	//_RC.Song4 = RectMakeCenter(450, 200, 250, 50);
	//_RC.Song5 = RectMakeCenter(450, 250, 250, 50);
	//_RC.Song6 = RectMakeCenter(450, 300, 250, 50);
	//_RC.Song7 = RectMakeCenter(450, 350, 250, 50);

	//_rc = RectMakeCenter(WINSIZEX / 2, WINSIZEY / 2, 100, 100);

	bg_Image = new image;						// ������� ���� �̹����� ������� ���� �Ҵ�
	bg_Image = IMAGEMANAGER->findImage("0");	// �� ������ ���� �ʾ����� �⺻���� ���� �̹����� �־��

	UI_Image = new image;
	UI_Image = IMAGEMANAGER->findImage("Start");

	isPlaying = false;


	// ��Ʈ�� ��ġ�� ���� ��ȣ�� ������ ���Ϳ� �߰����ش�.
	for (int i = 1; i < 11; ++i)
	{
		tag_RECT* _tRC;
		_tRC = new tag_RECT;

		_tRC->num = i;
		_tRC->rc = RectMakeCenter(725,25+ ((i - 1) * 50), 250, 50);

		_vRC.push_back(_tRC);
	}

	//�뷡 ������ �ʱ�ȭ
	_CarrentPlayingIndex = 1; 

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
	//�������� ã�� 
	/*if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&_rc, _ptMouse))
		{
			OPENFILENAME ofn;
			char filePathSize[1028] = "";
			ZeroMemory(&ofn, sizeof(OPENFILENAME));

			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = NULL;
			ofn.lpstrFile = filePathSize;
			ofn.nMaxFile = sizeof(filePathSize);
			ofn.nFilterIndex = true;
			ofn.lpstrFileTitle = NULL;
			ofn.nMaxFileTitle = NULL;
			ofn.lpstrInitialDir = NULL;
			ofn.lpstrFilter = ("�������ϸ��־����");
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

			if (GetOpenFileName(&ofn) == FALSE) return;

			char temp[1028];
			strncpy_s(temp, strlen(ofn.lpstrFile) + 1, ofn.lpstrFile, strlen(ofn.lpstrFile));

			char* context = NULL;
			char* token = strtok_s(temp, "\\", &context);
			while (strlen(context))
			{
				token = strtok_s(NULL, "\\", &context);
			}

			SOUNDMANAGER->addSound(token, ofn.lpstrFile, true, false);
		}

		SOUNDMANAGER->play("�巡�ﺼGT ������.mp3");
	}*/
	//���� ����
	/*
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		SOUNDMANAGER->play("�㷹�պ�", 0.1f);
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		SOUNDMANAGER->stop("�㷹�պ�");  //
	}
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		SOUNDMANAGER->pause("�㷹�պ�");  // ��� ���� ����
	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		SOUNDMANAGER->resume("�㷹�պ�");  // �ٽ� ���� 
	}

*/
	
	_RC.MousePointer = RectMakeCenter(_ptMouse.x, _ptMouse.y, 20, 20);

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		for (int i = 0; i < _vRC.size(); ++i)
		{

			if (PtInRect(&_vRC[i]->rc, _ptMouse))
			{
				sprintf_s(_tempNum, "BGM%d", i + 1);
				SOUNDMANAGER->stop(_Song);
				SOUNDMANAGER->play(_tempNum, 0.5f);

				_Song = _tempNum;

			}
			if (PtInRect(&(_RC.Plus), _ptMouse)) {
				SOUNDMANAGER->setVolume(_Song, SOUNDMANAGER->getVolume(_Song) + 0.1f);
			}
			if (PtInRect(&(_RC.Minus), _ptMouse)) {
				SOUNDMANAGER->setVolume(_Song, SOUNDMANAGER->getVolume(_Song) - 0.1f);
			}
			if (PtInRect(&_vRC[i]->rc, _ptMouse))
			{
				sprintf_s(_Temp, "%d", i + 1);
				bg_Image = IMAGEMANAGER->findImage(_Temp);
			}

		}
	}
	Playertime(SOUNDMANAGER->getSongLen(_Song), _Len);
	Playertime(SOUNDMANAGER->getSongPos(_Song), _Pos);
	if (PtInRect(&_RC.Player, _ptMouse) && !isPlaying) {
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON) )  //|| KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			UI_Image = IMAGEMANAGER->findImage("Pause");

			isPlaying = true;
		}
	}
	if (PtInRect(&_RC.Player, _ptMouse) && isPlaying) {

		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			UI_Image = IMAGEMANAGER->findImage("Start");
			isPlaying = false;
		}
	}



	// ������(�������� �׸��� ) �� �����̰� �ؾ��ϴ� �������� ������Ʈ ������.
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		for (int i = 1; i < 11; ++i)
		{
			_vRC[i - 1]->rc.bottom -= 5;
			_vRC[i - 1]->rc.top -= 5;
		}
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		for (int i = 1; i < 11; ++i)
		{
			_vRC[i - 1]->rc.bottom += 5;
			_vRC[i - 1]->rc.top += 5;
		}
	}


}

//����� �׷���!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
void playGround::render()
{
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================
	
	bg_Image->render(getMemDC(), 0, 0);
	UI_Image->render(getMemDC(), _RC.Player.left, _RC.Player.top);
	
	for (int i = 1; i < 11; ++i)
	{
		Rectangle(getMemDC(), _vRC[i-1]->rc);
		sprintf_s(_tempNum, "a%d", i);
		IMAGEMANAGER->findImage(_tempNum)->render(getMemDC(), _vRC[i - 1]->rc.left, _vRC[i - 1]->rc.top);
	}
	
	//IMAGEMANAGER->findImage("Start")->render(getMemDC(), _RC.Player.left, _RC.Player.top);
	IMAGEMANAGER->findImage("Next")->render(getMemDC(), _RC.NEXT.left, _RC.NEXT.top);
	IMAGEMANAGER->findImage("Last")->render(getMemDC(), _RC.LAST.left, _RC.LAST.top);
	IMAGEMANAGER->findImage("Plus")->render(getMemDC(), _RC.Plus.left, _RC.Plus.top);
	IMAGEMANAGER->findImage("Minus")->render(getMemDC(), _RC.Minus.left, _RC.Minus.top);
	//Rectangle(getMemDC(), _RC.Plus);
	//Rectangle(getMemDC(), _RC.Minus);

	TextOut(getMemDC(), WINSIZEX / 2 - 100, WINSIZEY / 2, _Len, strlen(_Len));
	
	//===================================================
	//�� ���ߴ�
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::Playertime(unsigned int _Num, char* _SS)
{
	int Min = _Num / 60;
	int Sec = _Num % 60;
	sprintf_s(_SS, 30, "%d : %d", Min, Sec);
}

