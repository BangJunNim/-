#pragma once
#include "gameNode.h"
#include "RockBuster.h"  //발사체 
#include "First_Villein.h"
#include "MiniBoss.h"

#include <vector>

class Player; //충돌 때문에 

class VilleinManager : public gameNode
{
private:

	typedef vector<Villein*>			  vFVillein;
	typedef vector<Villein*> ::iterator viFVillein;

private:
	
	vFVillein _vF_villein;
	viFVillein _viF_villein;

	// 빌런이 나오는 카운트 
	int _Villein_Count;  

	Player* _Player;
	RockBuster* _RockBuster;

	char testHP[256];

public:
	VilleinManager();
	~VilleinManager();

	HRESULT init();
	void release();
	void update();
	void render();

	// 몹 셋팅 함수
	void SettingVillein();
	void SettingBoss();

	// 몹  총알 발사 명령 함수 
	void VilleinFire();

	// 발사체에 맞은 몹 제거 함수 
	void removeMop(int arrNum);

	// 몹 재 생성
	void ReMop();
	// 충돌 처리 . 
	void collisiom(); 
	void Bosscollisvion();
	void setPlayerAddressLink(Player* Player) { _Player = Player; }

	vector<Villein*> getVillein() { return  _vF_villein; }
	vector<Villein*> ::iterator getiVillein() { return _viF_villein;}

};

