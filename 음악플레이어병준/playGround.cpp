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
	gameNode::init(true);
	//노래 이미지 
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
	
	// ui 이미지 
	IMAGEMANAGER->addImage("Pause", "Image/Pause.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Start", "Image/Player.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Next", "Image/Next.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Last", "Image/Last.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Plus", "Image/Plus.bmp", 50, 50, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("Minus", "Image/Minus.bmp", 50, 50, true, RGB(255, 0, 255));
	//배경 이미지
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
	// 사운드
	SOUNDMANAGER->addSound("BGM1", "BGM/호랑수월가.mp3", true, false);
	SOUNDMANAGER->addSound("BGM2", "BGM/이누야샤.mp3", true, false);
	SOUNDMANAGER->addSound("BGM3", "BGM/피에트.mp3", true, false);
	SOUNDMANAGER->addSound("BGM4", "BGM/피아노도둑.mp3", true, false);
	SOUNDMANAGER->addSound("BGM5", "BGM/욤.mp3", true, false);
	SOUNDMANAGER->addSound("BGM6", "BGM/내가죽으려고생각한것은.mp3", true, false);
	SOUNDMANAGER->addSound("BGM7", "BGM/스미다강.mp3", true, false);
	SOUNDMANAGER->addSound("BGM8", "BGM/겨울왕국.mp3", true, false);
	SOUNDMANAGER->addSound("BGM9", "BGM/조커.mp3", true, false);
	SOUNDMANAGER->addSound("BGM10", "BGM/Panda.mp3", true, false);

	
	// 렉트 
	
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

	bg_Image = new image;						// 배경으로 쓰일 이미지를 담기위해 공간 할당
	bg_Image = IMAGEMANAGER->findImage("0");	// 곡 선택을 하지 않았을때 기본으로 쓰일 이미지를 넣어둠

	UI_Image = new image;
	UI_Image = IMAGEMANAGER->findImage("Start");

	isPlaying = false;


	// 렉트의 위치와 곡의 번호를 저장해 백터에 추가해준다.
	for (int i = 1; i < 11; ++i)
	{
		tag_RECT* _tRC;
		_tRC = new tag_RECT;

		_tRC->num = i;
		_tRC->rc = RectMakeCenter(725,25+ ((i - 1) * 50), 250, 50);

		_vRC.push_back(_tRC);
	}

	//노래 재생목록 초기화
	_CarrentPlayingIndex = 1; 

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
	//음악파일 찾기 
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
			ofn.lpstrFilter = ("음악파일만넣어줘라");
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

		SOUNDMANAGER->play("드래곤볼GT 오프닝.mp3");
	}*/
	//음악 실행
	/*
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		SOUNDMANAGER->play("쥐레겐볼", 0.1f);
	}

	if (KEYMANAGER->isOnceKeyDown('W'))
	{
		SOUNDMANAGER->stop("쥐레겐볼");  //
	}
	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		SOUNDMANAGER->pause("쥐레겐볼");  // 잠시 정시 멈춤
	}
	if (KEYMANAGER->isOnceKeyDown('R'))
	{
		SOUNDMANAGER->resume("쥐레겐볼");  // 다시 시작 
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



	// 고정값(랜더에서 그리는 ) 이 움직이게 해야하니 랜더에서 업데이트 데려옴.
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

//여기다 그려라!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
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
	//딱 말했다
	_backBuffer->render(getHDC(), 0, 0);
}

void playGround::Playertime(unsigned int _Num, char* _SS)
{
	int Min = _Num / 60;
	int Sec = _Num % 60;
	sprintf_s(_SS, 30, "%d : %d", Min, Sec);
}

