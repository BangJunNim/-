#include "stdafx.h"
#include "playGround.h"


playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	_Start = false;
	gameNode::init();

	_BG = new image;
	_BG->init("배경.bmp", 1800, 1800, false, RGB(0, 0, 0));
	_Hall = new image;
	_Hall->init("경기장.bmp", 1400, 650, true, RGB(255, 0, 255));
	_Ball = new image;
	_Ball->init("하키공.bmp", 50, 50, true, RGB(255, 0, 255));
	_1P = new image;
	_1P->init("플레이어1.bmp", 50, 50, true, RGB(255, 0, 255));
	_2P = new image;
	_2P->init("플레이어2.bmp", 50, 50, true, RGB(255, 0, 255));
	_point = new image;
	_point->init("점수판.bmp", 50, 50, false, RGB(0, 0, 0));

	// 플레이어 초기화.
	Player.radius = 25;
	Player.speed = 0.8f;
	Player.x = WINSIZEX / 2 - 600;
	Player.y = WINSIZEY / 2;
	Player.angle = PI * 2;

	Player2.radius = 25;
	Player2.speed = 0.8f;
	Player2.x = WINSIZEX / 2 + 600;
	Player2.y = WINSIZEY / 2;
	Player2.angle = PI * 2;

	// 공 초기화.
	Ball.radius2 = 25;
	Ball.angle2 = PI * 2;
	Ball.x2 = WINSIZEX / 2;
	Ball.y2 = WINSIZEY / 2;
	Ball.speed2 = 8.0f;

	GoalPost.right = WINSIZEX / 2 - 700;
	GoalPost.top = WINSIZEY / 2 - 70;
	GoalPost.left = 30;
	GoalPost.bottom = WINSIZEY / 2 + 70;

	GoalPost2.left = WINSIZEX / 2 + 700;
	GoalPost2.top = WINSIZEY / 2 - 70;
	GoalPost2.right = WINSIZEX / 2 + 720;
	GoalPost2.bottom = WINSIZEY / 2 + 70;



	char buffer[128];
	for (int i = 1; i < 6; i++) {
		sprintf_s(buffer, "%d.bmp", i);
		_num[i-1] = new image;
		_num[i-1]->init(buffer, 25, 50, true, RGB(255, 0, 255));
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


	if (!_Start) {
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_Start = true;
		}

	}

	if (_Start) {

		// 플레이어 키 입력 함수
		KEY();
		KEY2();

		// 공 
		BallMove();

		BallGoal();
		BallCrash();

		if (Ball.speed2 > 0)
			Ball.speed2 -= 0.06f;
		else
			Ball.speed2 = 0;

	}

}

void playGround::render(HDC hdc)
{
\	HDC backDC = this->getBackBuffer()->getMemDC();
	PatBlt(backDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================================================

\	_BG->render(backDC, 0, 0);  // 바깥

\	_Hall->render(backDC, WINSIZEX/2 - 700, WINSIZEY / 2 - 325 );
	// SelectObject(backDC, oldbrush2);
	// DeleteObject(brush2);

	//HBRUSH brush3, oldbrush3;   //
	//brush3 = CreateSolidBrush(RGB(102, 102, 153));
	//oldbrush3 = (HBRUSH)SelectObject(backDC, brush3);
	//
	//EllipseMakeCenter(backDC, WINSIZEX / 2, WINSIZEY / 2, 200, 200);  // 경기장 중간  
	//
	//SelectObject(backDC, oldbrush3);
	//DeleteObject(brush3);

	// LineMake(backDC, WINSIZEX / 2, 75, WINSIZEX / 2, 725); // 경기장 중간 라인 
	
	
	//	LineMake(backDC, WINSIZEX / 2 - 200, 75, WINSIZEX / 2 - 200, 725); // 1Player Ground;
	//	
	//
	//	LineMake(backDC, WINSIZEX / 2 + 200, 75, WINSIZEX / 2 + 200, 725); // 2Player Ground;



	HBRUSH brush4, oldbrush4;   //
	brush4 = CreateSolidBrush(RGB(255, 255, 255));
	oldbrush4 = (HBRUSH)SelectObject(backDC, brush4);
	//RectangleMakeCenter(backDC, WINSIZEX / 2 - 690, WINSIZEY / 2, 20, 120); // 1Player Goal Post
	//RectangleMakeCenter(backDC, WINSIZEX / 2 + 690, WINSIZEY / 2, 20, 120); // 2Player Goal Post
	Rectangle(backDC, GoalPost.left, GoalPost.top, GoalPost.right, GoalPost.bottom);
	Rectangle(backDC, GoalPost2.left, GoalPost2.top, GoalPost2.right, GoalPost2.bottom);

	SelectObject(backDC, oldbrush4);
	DeleteObject(brush4);

	//======================================================================================================//

	//HBRUSH brush5, oldbrush5;   //
	//brush5 = CreateSolidBrush(RGB(200, 0, 0));
	//oldbrush5 = (HBRUSH)SelectObject(backDC, brush5);

	//EllipseMakeCenter(backDC, Player.x, Player.y, Player.radius * 2, Player.radius * 2);  // 1Player
	_1P->render(backDC, Player.x - 25, Player.y - 25);
	//EllipseMakeCenter(backDC, Player2.x, Player2.y, Player2.radius * 2, Player2.radius * 2); // 2Player
	_2P->render(backDC, Player2.x - 25, Player2.y - 25);
	//SelectObject(backDC, oldbrush5);
	//DeleteObject(brush5);

//	HBRUSH brush6, oldbrush6;   //
//	brush6 = CreateSolidBrush(RGB(102, 102, 102));
//	oldbrush6 = (HBRUSH)SelectObject(backDC, brush6);

//	EllipseMakeCenter(backDC, Ball.x2, Ball.y2, Ball.radius2 * 2, Ball.radius2 * 2); // BALL
	_Ball->render(backDC, Ball.x2 - 25, Ball.y2 - 25);
//	SelectObject(backDC, oldbrush6);
//	DeleteObject(brush6);

	if (!_Start) {

		HBRUSH brush9, oldbrush9;   // 백 그라운드 색깔;
		brush9 = CreateSolidBrush(RGB(25, 25, 25));
		oldbrush9 = (HBRUSH)SelectObject(backDC, brush9);

		RectangleMakeCenter(backDC, WINSIZEX - 800, WINSIZEY, 1800, 1800);  //  바깥

		SelectObject(backDC, oldbrush9);
		DeleteObject(brush9);

		TextOut(backDC, WINSIZEX / 2 - 100, WINSIZEY / 2, "스페이바를 눌러 게임 시작", strlen("스페이바를 눌러 게임 시작"));

	}
	if (Ball.x2 - Ball.radius2 <= GoalPost.left)
	{

	}
	
	// RectangleMakeCenter(backDC, WINSIZEX / 2 - 100, 40, 50, 50); // 1Player Point;
	// RectangleMakeCenter(backDC, WINSIZEX / 2 + 100, 40, 50, 50); // 2Player Point;
	_point->render(backDC, WINSIZEX / 2 - 125,15);
	_point->render(backDC, WINSIZEX / 2 + 75,15);

	int one = Player.score % 10;
	int one2 = Player2.score % 10;
	
	_num[one]->render(backDC, WINSIZEX / 2 - 115, 15);

	_num[one2]->render(backDC, WINSIZEX / 2 + 85, 15);

	//sprintf_s(buf, "%d", Player.score);
	//
	//TextOut(backDC, WINSIZEX / 2 - 100, 40, buf, strlen(buf));
	//
	//sprintf_s(buf, "%d", Player2.score);
	//TextOut(backDC, WINSIZEX / 2 + 100, 40, buf, strlen(buf));



	//===================================================
	this->getBackBuffer()->render(hdc, 0, 0);
}

void playGround::KEY()
{
	if (KEYMANAGER->isStayKeyDown('A')) Player.x -= 7;
	if (KEYMANAGER->isStayKeyDown('D')) Player.x += 7;
	if (KEYMANAGER->isStayKeyDown('W')) Player.y -= 7;
	if (KEYMANAGER->isStayKeyDown('S')) Player.y += 7;
	// if (KEYMANAGER->isOnceKeyDown('E'))  보류 
	if (Player.x + Player.radius >= WINSIZEX / 2 - 200) {
		//Player.x -= Player.radius -8;
		Player.x = WINSIZEX / 2 - 200 - Player.radius;
	}
	if (Player.x - Player.radius <= WINSIZEX / 2 - 700) {
		//Player.x += Player.radius -8;
		Player.x = WINSIZEX / 2 - 700 + Player.radius;
	}
	if (Player.y - Player.radius <= WINSIZEY / 2 - 320) {
		//Player.y += Player.radius - 8;
		Player.y = WINSIZEY / 2 - 325 + Player.radius;
	}
	if (Player.y + Player.radius >= WINSIZEY / 2 + 320) {
		//Player.y -= Player.radius - 8;
		Player.y = WINSIZEY / 2 + 325 - Player.radius;
	}
}

void playGround::KEY2()
{
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD8)) Player2.y -= 7;
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD5)) Player2.y += 7;
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD4)) Player2.x -= 7;
	if (KEYMANAGER->isStayKeyDown(VK_NUMPAD6)) Player2.x += 7;
	// if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD7))  보류 
	if (Player2.x - Player2.radius <= WINSIZEX / 2 + 200) {
		//	Player2.x += Player2.radius - 8; 
		Player2.x = WINSIZEX / 2 + 200 + Player2.radius;
	}
	if (Player2.x + Player2.radius >= WINSIZEX / 2 + 700) {
		//	Player2.x -= Player2.radius - 8;
		Player2.x = WINSIZEX / 2 + 700 - Player2.radius;
	}
	if (Player2.y - Player2.radius <= WINSIZEY / 2 - 325) {
		//	Player2.y += Player2.radius - 8;
		Player2.y = WINSIZEY / 2 - 325 + Player2.radius;
	}
	if (Player2.y + Player2.radius >= WINSIZEY / 2 + 325) {
		//	Player2.y -= Player2.radius - 8;
		Player2.y = WINSIZEY / 2 + 325 - Player2.radius;
	}
}

void playGround::BallMove()
{
	Ball.x2 += cosf(Ball.angle2) * Ball.speed2;   // 각도 
	Ball.y2 += -sinf(Ball.angle2) * Ball.speed2;  // 각도 
}

void playGround::BallCrash()
{
	//────────────────────────────────────────────────────────────────────//
	 // 2Player 충돌
	float x = Ball.x2 - Player2.x;
	float y = Ball.y2 - Player2.y;

	h = sqrtf(pow(x, 2) + pow(y, 2));

	if (Ball.radius2 + Player2.radius >= h) {
		Ball.angle2 = getAngle(Player2.x, Player2.y, Ball.x2, Ball.y2);
		Ball.speed2 += 5.5f;
	}
	//────────────────────────────────────────────────────────────────────//
	 // 1Player 충돌 
	x = Ball.x2 - Player.x;
	y = Ball.y2 - Player.y;

	h = sqrtf(pow(x, 2) + pow(y, 2));
	// 벽 충돌 
	if (Ball.radius2 + Player.radius >= h) {
		Ball.angle2 = getAngle(Player.x, Player.y, Ball.x2, Ball.y2);
		Ball.speed2 += 5.5f;
	}
	//────────────────────────────────────────────────────────────────────//

	// x축 왼쪾
	if (Ball.x2 + Ball.radius2 <= WINSIZEX / 2 - 650 && (Ball.y2 - Ball.radius2 <= GoalPost.top || Ball.y2 + Ball.radius2 >= GoalPost.bottom)) {
		sprintf_s(buf, "%f,%lld,%d", Ball.x2 - Ball.radius2, GoalPost.left, Ball.x2 - Ball.radius2 <= GoalPost.right);

		Ball.x2 = Ball.radius2 + WINSIZEX / 2 - 650;

		Ball.angle2 = PI - Ball.angle2;
		Ball.speed2 -= 1.0f;
	}
	// x축 오른쪽
	if (Ball.x2 - Ball.radius2 >= WINSIZEX / 2 + 650 && (Ball.y2 - Ball.radius2 <= GoalPost.top || Ball.y2 + Ball.radius2 >= GoalPost.bottom)) {
		Ball.x2 = Ball.radius2 + WINSIZEX / 2 + 650;
		Ball.angle2 = PI - Ball.angle2;
		Ball.speed2 -= 1.0f;
	}
	// y 축 위 
	if (Ball.y2 - Ball.radius2 <= WINSIZEY / 2 - 325) {
		Ball.y2 = Ball.radius2 + WINSIZEY / 2 - 325;
		Ball.angle2 = 2 * PI - Ball.angle2;
		Ball.speed2 += 0.9f;
	}

	// y 축 아래
	if (Ball.y2 + Ball.radius2 >= WINSIZEY / 2 + 325) {
		Ball.y2 = -Ball.radius2 + WINSIZEY / 2 + 325;
		Ball.angle2 = 2 * PI - Ball.angle2;
		Ball.speed2 += 0.09f;
	}
}

void playGround::BallGoal()
{
	if (Ball.x2 - Ball.radius2 <= GoalPost.left)  // 1 Player 골 먹혔을 때
	{
		Player2.score++;
		Ball.speed2 = 8.0f;
		Ball.x2 = WINSIZEX / 2;
		Ball.y2 = WINSIZEY / 2;
		_Start = false;
	}
	if (Ball.x2 + Ball.radius2 >= GoalPost2.right) // 2 Player 골 먹혔을 때,
	{
		Player.score++;

		Ball.speed2 = 8.0f;
		Ball.x2 = WINSIZEX / 2;
		Ball.y2 = WINSIZEY / 2;
		_Start = false;
	}
}
