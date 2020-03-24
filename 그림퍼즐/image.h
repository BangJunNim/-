#pragma once
//=========================================
// ## 2019.11.15 ## Image ##
//=========================================


class image
{
public:
	enum IMAGE_LOAD_KIND
	{
		LOAD_RESOURCE,
		LOAD_FILE,
		LOAD_EMPTY,
		LOAD_END
	};


	typedef struct tagImageInfo
	{
		DWORD resID;
		HDC hMemDC;
		HBITMAP hBit;
		HBITMAP hOBit;
		float x;			//이미지 뿌려질 곳의 X(left)
		float y;			//이미지 뿌려질 곳의 Y(top)
		int width;
		int height;
		BYTE loadType;

		tagImageInfo()
		{
			resID = 0;
			hMemDC = NULL;
			hBit = NULL;
			hOBit = NULL;
			width = 0;
			height = 0;
			loadType = LOAD_RESOURCE;
		}
	}IMAGE_INFO, *LPIMAGE_INFO;
private:
	LPIMAGE_INFO	_imageInfo;
	CHAR*			_fileName;
	BOOL			_trans;
	COLORREF		_transColor;

public:
	image();
	~image();

	HRESULT init(int width, int height);
	HRESULT init(const char* fileName, int width, int height,
		BOOL trans = FALSE, COLORREF transColor = FALSE);

	void release();

	void setTransColor(BOOL trans, COLORREF transColor);

	void render(HDC hdc, int destX, int destY);

	//렌더함수 뿌려질DC, 뿌릴좌표X(left),뿌릴좌표Y(top), 잘라올곳X(left), 잘라올곳Y(top), 잘라올 가로크기, 잘라올 세로크기
	void render(HDC hdc, int destX, int destY, int sourX, int sourY, int sourWidth, int sourHeight);

	inline HDC getMemDC() { return _imageInfo->hMemDC; }
};

