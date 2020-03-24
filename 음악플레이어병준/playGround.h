#pragma once
#include "gameNode.h"
#include <vector>

#include <commdlg.h> //OPENFILENAME을 위한 헤더

struct RECT_SET
{
	RECT _rc1;
	RECT _rc2;
	RECT _BG;

	RECT Time;
	RECT Player;
	RECT Stop;
	RECT NEXT;
	RECT LAST;
	RECT Pause;
	RECT MousePointer;
	RECT Plus;
	RECT Minus;


};

// 재생목록으로 쓰일 구조체
struct tag_RECT
{
	RECT rc;		// 렉트
	int num;		// 곡의 번호
};


class playGround : public gameNode
{
private:

	RECT_SET _RC;
	
	vector<tag_RECT*>	_vRC;				// 재생목록을 담을 벡터
	char				_tempNum[30];		// 숫자를 문자열로 담기 위해 임시로 만들었다
	char				_Temp[30];
	image* bg_Image;						// 배경으로 출력할 이미지 담는곳
	image* UI_Image;

	vector<string>     _vString;
	int _CarrentPlayingIndex;

	string _Song;
	bool isPlaying;

	unsigned int _Time;
	unsigned int __Time;
	char _Len[30];
	char _Pos[30];

public:
	playGround();
	~playGround();

	virtual HRESULT init();			//초기화 전용 함수
	virtual void release();			//메모리 해제 함수
	virtual void update();			//연산 전용 함수
	virtual void render();			//그리기 전용 함수


	void Playertime(unsigned int _Num, char* _SS);
	
	
};

