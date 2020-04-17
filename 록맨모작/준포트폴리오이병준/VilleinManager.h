#pragma once
#include "gameNode.h"
#include "RockBuster.h"  //�߻�ü 
#include "First_Villein.h"
#include "MiniBoss.h"

#include <vector>

class Player; //�浹 ������ 

class VilleinManager : public gameNode
{
private:

	typedef vector<Villein*>			  vFVillein;
	typedef vector<Villein*> ::iterator viFVillein;

private:
	
	vFVillein _vF_villein;
	viFVillein _viF_villein;

	// ������ ������ ī��Ʈ 
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

	// �� ���� �Լ�
	void SettingVillein();
	void SettingBoss();

	// ��  �Ѿ� �߻� ��� �Լ� 
	void VilleinFire();

	// �߻�ü�� ���� �� ���� �Լ� 
	void removeMop(int arrNum);

	// �� �� ����
	void ReMop();
	// �浹 ó�� . 
	void collisiom(); 
	void Bosscollisvion();
	void setPlayerAddressLink(Player* Player) { _Player = Player; }

	vector<Villein*> getVillein() { return  _vF_villein; }
	vector<Villein*> ::iterator getiVillein() { return _viF_villein;}

};

