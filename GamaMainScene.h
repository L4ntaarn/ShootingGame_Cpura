#pragma once
#include "AbstractScene.h"
#include "DxLib.h"

class GameMainScene
{
private:
	int player;
	int life;
	int* enemy[3];
	int* Ballet[5];

public:
	void HitCheck();
	void SpawnBallet();


};
