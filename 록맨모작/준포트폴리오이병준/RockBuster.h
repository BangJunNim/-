#pragma once
#include "gameNode.h"
#include <vector>

// 구조체 설정 
struct tagRockBuster
{
	image* RockBusterImage;
	RECT _rc;
	float _x, _y;   // 발사체  크기 
	float _angle;   // 각도 
	float _speed;  // 스피드 
	float _radius;
	float _FireX, _FireY; // 첫 발사 위치  / 플레이어한테 줄 위치 설정 
	bool _isFire;
	int count, currentFrameX, currentFrameY;
};


//모든 발사체 설정 
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

	// 발사 관련 함수 
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
	float _Range;  // 사거리 



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

