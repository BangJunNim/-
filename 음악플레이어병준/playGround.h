#pragma once
#include "gameNode.h"
#include <vector>

#include <commdlg.h> //OPENFILENAME�� ���� ���

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

// ���������� ���� ����ü
struct tag_RECT
{
	RECT rc;		// ��Ʈ
	int num;		// ���� ��ȣ
};


class playGround : public gameNode
{
private:

	RECT_SET _RC;
	
	vector<tag_RECT*>	_vRC;				// �������� ���� ����
	char				_tempNum[30];		// ���ڸ� ���ڿ��� ��� ���� �ӽ÷� �������
	char				_Temp[30];
	image* bg_Image;						// ������� ����� �̹��� ��°�
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

	virtual HRESULT init();			//�ʱ�ȭ ���� �Լ�
	virtual void release();			//�޸� ���� �Լ�
	virtual void update();			//���� ���� �Լ�
	virtual void render();			//�׸��� ���� �Լ�


	void Playertime(unsigned int _Num, char* _SS);
	
	
};

