#include "stdafx.h"
#include "Player.h"
#include "VilleinManager.h"


Player::Player()
{
}

Player::~Player()
{
}

HRESULT Player::init()
{

	_Wall._rc.left = 0; _Wall._rc.top = 0; _Wall._rc.right = 100; _Wall._rc.bottom = 682;  // 왼쪽 벽
	_Wall._rc2.left = 1200; _Wall._rc2.top = 0; _Wall._rc2.right = 1400; _Wall._rc2.bottom = 682; // 오른쪽 벽
	//플레이어 이미지 
	//IMAGEMANAGER->addImage("Start", "StartButton.bmp", 440, 56, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("PlayerAppear", "플레이어등장.bmp", 1320, 224, 11, 1, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Idle", "Player_N/Playeridle.bmp", 600, 224, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Run", "Player_N/PlayerRun.bmp", 1500, 224, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Dash", "Player_N/PlayerDash.bmp", 600, 245, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("WallJump", "Player_N/Player_WallJump.bmp", 600, 224, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("Ending", "Player_N/PlayerEnding.bmp", 960, 448, 8, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Jump", "Player_N/PlayerJump.bmp", 800, 224, 5, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("J_Attack", "Player_N/PlayerJump_Attack.bmp", 480, 448, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("S_Attack", "Player_N/PlayerStay_Attack.bmp", 360, 224, 2, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("R_ATTack", "Player_N/PlayerrunAttack.bmp", 1200, 448, 10, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("charging", "Player_Fire/charging.bmp", 750, 380, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("charging_1", "Player_Fire/charging1.bmp", 750, 380, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("charging_2", "Player_Fire/charging2.bmp", 750, 380, 6, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("1Fire", "Player_Fire/1.bmp", 400, 156, 4, 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("Bullet", "Villein/2.bmp", 400, 156,4,2, true, RGB(255, 0, 255));
	_usingCharging = false;
	

	//플레이어 좌표 , 크기 설정 
	Player_O._x = 160; Player_O._y = 580; 

	//초기화
	_FireCount =_count = _index = 0;  
	_currentFrameX = _currentFrameY = 0; 
	_PlayerState = Player_Idle;
	_DirectionR = RIGHT;
	_DirectionL = LEFT;

	//이펙트 이미지 초기화 
	_EffectMaxFrameX = _EffectMaxFrameY = 0;
	_EffectR = RIGHT;
	_EffectL = LEFT;

	//점프 설정 
	JumpPower = 15;
	gravity = 0.5f;
	
	// 첫 시작 이미지 
	_PLAYER = IMAGEMANAGER->findImage("Idle");
	_currentMaxFrame = IMAGEMANAGER->findImage("Idle")->getMaxFrameX();
	_currentMaxFrameY = IMAGEMANAGER->findImage("Idle")->getMaxFrameY();

	_rc = RectMake(Player_O._x, Player_O._y, _PLAYER->getFrameWidth(), _PLAYER->getFrameHeight());

	_Attack = new NomalAttack;
	_Attack->init(200, 800);
	_PlayerEffect = new image;
	// 플레이어 점프 상태 
	Player_O.Player_bool._isJump = false;

	_fireDirection = 200;

	// 체력 설정 
	_HP = new HPSetting;
	_HP->init_Player(100,300);
	_currentHP = _MaxHp = 400;
	return S_OK;
}

void Player::release()
{

}
void Player::update()
{
	KeySetting();
	PlayerMoveFrame();
	SwitchImage();
	collision();
	// 점프 
	if (Player_O.Player_bool._isJump)  // 점프 
	{
		Player_O._y -= JumpPower;
		JumpPower -= gravity;
		if (Player_O._y > 580)  // 바닥 닿았을 때 
		{
			Player_O._y = 580;
			JumpPower = 15;
			Player_O.Player_bool._isJump = false;
			_PlayerState = Player_Idle;   // 플레이어 아이들 상태로 꺼내고 
			_currentMaxFrame = IMAGEMANAGER->findImage("Idle")->getMaxFrameX(); // 이미지 불러오고 
			if (_Direction == RIGHT) { //오른쪽 아이들 프레임 읽을 꺼 꺼내고
				_currentFrameY = 0;
				_currentFrameX = 0;
			}
			else if (_Direction == LEFT) { // 마찬가지로 왼쪽 아이들 프렘 읽을 꺼 설정 하고 
				_currentFrameY = 1;
				_currentFrameX = _currentMaxFrame;
			}
		}


	}
	//_RockBuster->update();
	_Attack->update();
	_HP->SetX(50);
	_HP->SetY(WINSIZEY / 2 - 400 );
	_HP->update();
	_HP->SetGauge(_currentHP, _MaxHp);
	
}
void Player::render()
{
	if (_PlayerState == Player_Wall_Jump)
	{
		if (_Direction == RIGHT)
		{
			_PLAYER->frameRender(getMemDC(), Player_O._x, Player_O._y, 3, 1);
		}
		else if (_Direction ==LEFT)
		{
			_PLAYER->frameRender(getMemDC(), Player_O._x, Player_O._y, 0, 0);
		}
	}
	else 
	{
	_PLAYER->frameRender(getMemDC(), Player_O._x, Player_O._y, _currentFrameX, _currentFrameY);
	}
	if (_usingCharging)
		_PlayerEffect->frameRender(getMemDC(), Player_O._x+22, Player_O._y - 49, _FrameX, _FrameY);

	// 벽 잡기
	Player_O.L_rc = RectMakeCenter(Player_O._x - 5, Player_O._y + _PLAYER->getFrameHeight() / 2, 15, 15);
	Player_O.R_rc = RectMakeCenter(Player_O._x + 165, Player_O._y + _PLAYER->getFrameHeight() / 2, 15, 15);

	//_RockBuster->render();
	_Attack->render();
	_HP->Render_Player();

}

void Player::KeySetting()
{

	// 방향 
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_fireDirection = 0;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_fireDirection = 1;
	}
	// 왼쪽 벽 충돌 
	if (Player_O._x >= 100) {
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT)) {
			_currentMaxFrame = IMAGEMANAGER->findImage("Run")->getMaxFrameX();
			_currentFrameY = 1;
			_currentFrameX = _currentMaxFrame;  
		}
		if (KEYMANAGER->isStayKeyDown(VK_LEFT) && !KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
			_PlayerState = Player_Run;
			Player_O._x -= 5;
			_Direction = LEFT;
		}
		if (KEYMANAGER->isOnceKeyUp('S')) {
			_currentMaxFrame = IMAGEMANAGER->findImage("Dash")->getMaxFrameX();
			_currentFrameY = 1;
			_currentFrameX = _currentMaxFrame;
			_PlayerState = Player_Dash;;
			Player_O._x -= Player_O._x / 2;
			_Direction = LEFT;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && !KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
		_PlayerState = Player_Idle;
		_currentMaxFrame = IMAGEMANAGER->findImage("Idle")->getMaxFrameX();
		_currentFrameY = 1;
		_currentFrameX = _currentMaxFrame;
		_Direction = LEFT;
	}
	if (KEYMANAGER->isOnceKeyUp('S')) {
		_PlayerState = Player_Idle;
		_currentMaxFrame = IMAGEMANAGER->findImage("Idle")->getMaxFrameX();
		_currentFrameY = 1;
		_currentFrameX = _currentMaxFrame;
		_Direction = LEFT;
	}
	// 오른쪽 벽 충돌
	if (Player_O._x <= 1050) {
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT)) {
			_currentMaxFrame = IMAGEMANAGER->findImage("Run")->getMaxFrameX();
			_currentFrameY = 0;
			_currentFrameX = 0;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
			_PlayerState = Player_Run;
			Player_O._x += 5;
			_Direction = RIGHT;
	
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
		_PlayerState = Player_Idle;
		_currentMaxFrame = IMAGEMANAGER->findImage("Idle")->getMaxFrameX();
		_currentFrameY = 0;
		_currentFrameX = 0;
		_Direction = RIGHT;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		if (!Player_O.Player_bool._isJump)
		{
			_PlayerState = Player_Jump; 
			_currentMaxFrame = IMAGEMANAGER->findImage("Jump")->getMaxFrameX();
			if (_Direction == RIGHT) { 
				_currentFrameY = 0;
				_currentFrameX = 0;
			}
			else if (_Direction == LEFT) { 
				_currentFrameY = 1;
				_currentFrameX = _currentMaxFrame;
			}
			Player_O.Player_bool._isJump = true;
		}
		else
		{
			if (Player_O.L_rc.right < _Wall._rc.right || Player_O.R_rc.left > _Wall._rc2.left)
			{
			JumpPower = 15;
			Player_O.Player_bool._isJump = false;
			_PlayerState = Player_Wall_Jump;
			_currentMaxFrame = IMAGEMANAGER->findImage("WallJump")->getMaxFrameX();
			if (_Direction == RIGHT) {
				_currentFrameY = 0;
				_currentFrameX = 0;
			}
			else if (_Direction == LEFT) {
				_currentFrameY = 1;
				_currentFrameX = _currentMaxFrame;
			}
			}
		}
	}
	// 공격 
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		_usingCharging = true;
		_FireCount++;

		EffectFramemove();
		_PlayerState = Player_Attack;
		if (_FireCount >= 100)
		{
			_PlayerEffect = IMAGEMANAGER->findImage("charging_2");
		}
		else if (_FireCount >= 50)
		{
			_PlayerEffect = IMAGEMANAGER->findImage("charging_1");
		}
		else if (_FireCount > 0)
		{
			_PlayerEffect = IMAGEMANAGER->findImage("charging");
			_currentMaxFrame = IMAGEMANAGER->findImage("S_Attack")->getMaxFrameX();

			if (_Direction == RIGHT) {
			}
			else if (_Direction == LEFT) {
			}
		}
		// 원스 키업으로 발사 설정 하자
	}
	if (KEYMANAGER->isOnceKeyDown('A'))
	{
		if (_Direction == RIGHT)
			_Attack->fire(Player_O._x + 200, Player_O._y + 23, RIGHT);
		else
			_Attack->fire(Player_O._x - 30, Player_O._y + 23, LEFT);
	}
	if (KEYMANAGER->isOnceKeyUp('A'))
	{
		_usingCharging = false;
		_PlayerState = Player_Idle;
		_FireCount = 0;
	}
}

void Player::PlayerMoveFrame()
{
	_count++;
	//  오른쪽 
	if (_count % 7 == 0) {
		if (_DirectionR) {
			_currentFrameX++;
			if (_currentFrameX >= _currentMaxFrame) _currentFrameX = 0;
		}
		// 왼쪽 
		else {
			_currentFrameX--;
			if (_currentFrameX <= 0) _currentFrameX = _PLAYER->getMaxFrameX();
		}
	}

}

void Player::EffectFramemove()
{
	_FrameCount++;

	if (_FrameCount % 5 == 0)
	{
		if (_EffectR == 0) {
			_FrameX++;
			if (_FrameX >= _PlayerEffect->getMaxFrameX()) _FrameX = 0;
		}

		else {
			_FrameX--;
			if (_FrameX < 0) _FrameX = _EffectMaxFrameX;
		}
	}
}

void Player::collision()
{
	for (int i = 0; i < _Vi->getVillein().size(); i++)
	{
		for (int j = 0; j < _Attack->getRock().size(); j++) {
			RECT temp;
			if (IntersectRect(&temp, &_Attack->getRock()[j]._rc, &_Vi->getVillein()[i]->getRect()))
			{
				_Vi->removeMop(i);
				_Attack->Remove(j);
				break;
			}
		}
	}
}

void Player::HitDmage(float dmage)
{
	_currentHP -= dmage;
}

void Player::SwitchImage()
{
	switch (_PlayerState) {
	case Player_Appear:
		_PLAYER = IMAGEMANAGER->findImage("PlayerAppear");
		break;
	case Player_Idle:
		_PLAYER = IMAGEMANAGER->findImage("Idle");
		break;
	case Player_Run:
		_PLAYER = IMAGEMANAGER->findImage("Run");
		break;
	case Player_Jump:
		_PLAYER = IMAGEMANAGER->findImage("Jump");
		break;
	case Player_Wall_Jump:
		_PLAYER = IMAGEMANAGER->findImage("WallJump");
		break;
	case Player_Dash:
		_PLAYER = IMAGEMANAGER->findImage("Dash");
		break;
	case Player_Attack:
		_PLAYER = IMAGEMANAGER->findImage("S_Attack");
		break;
	case Player_Run_Attack:
		_PLAYER = IMAGEMANAGER->findImage("R_ATTack");
		break;
	case Player_Jump_Attack:
		_PLAYER = IMAGEMANAGER->findImage("J_ATTack");
		break;
	case Player_Next_Stage:
		_PLAYER = IMAGEMANAGER->findImage("Ending");
		break;
	case Player_charging:
		_PLAYER = IMAGEMANAGER->findImage("charging");
		break;
	case Player_charging1:
		_PLAYER = IMAGEMANAGER->findImage("charging_1");
		break;
	case Player_charging2:
		_PLAYER = IMAGEMANAGER->findImage("charging_2");
		break;
	
	}
}


