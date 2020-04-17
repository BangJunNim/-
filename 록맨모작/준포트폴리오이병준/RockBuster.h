#pragma once
#include "gameNode.h"
#include <vector>

// ����ü ���� 
struct tagRockBuster
{
	image* RockBusterImage;
	RECT _rc;
	float _x, _y;   // �߻�ü  ũ�� 
	float _angle;   // ���� 
	float _speed;  // ���ǵ� 
	float _radius;
	float _FireX, _FireY; // ù �߻� ��ġ  / �÷��̾����� �� ��ġ ���� 
	bool _isFire;
	int count, currentFrameX, currentFrameY;
};


//��� �߻�ü ���� 
class RockBuster : public gameNode
{
protected:
	

private:
	vector<tagRockBuster>				vRockBuster;
	vector<tagRockBuster> ::iterator	viRockBuster;

	const char* _ImageName;
	float _Range; 
	int _RockBusterMax;
	

public:
	RockBuster();
	~RockBuster();

	HRESULT init(const char* ImageName, int RockBusterMax, float Range);
	void release(); 
	void update();
	void render();

	// �߻� ���� �Լ� 
	void RockBusterFire(float x, float y, float angle, float speed);
	

	void RockBusterMove();
	void RemoveRockBuster(int arrNum);

	vector<tagRockBuster>	getVABuster() { return vRockBuster; }
	vector<tagRockBuster> ::iterator getViABuster() { return viRockBuster; }
};


class NomalAttack : public gameNode
{
private : 
	vector<tagRockBuster>				vRockBuster;
	vector<tagRockBuster> ::iterator	viRockBuster;
	int _BullerMax;
	float _Range;  // ��Ÿ� 



public :

	NomalAttack() {};
	~NomalAttack() {};
	HRESULT init(int BulletMax, float range);
	void release();
	void update();
	void render();

	void fire(float x, float y,int Dir);
	void Move(); 
	void Remove(int arrNum);

	vector<tagRockBuster> getRock() { return vRockBuster; }
	vector<tagRockBuster> ::iterator getiRock() { return viRockBuster; }

};

