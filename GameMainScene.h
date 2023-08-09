#pragma once
#include "AbstractScene.h"
#include "DxLib.h"

class GameMainScene : public AbstractScene
{
private:
	int player;
	int life;
	int* enemy[3];
	int* Ballet[5];

public:
	GameMainScene();
	~GameMainScene();

	void HitCheck();
	void SpawnBallet();

	
	virtual AbstractScene* Update() override;
	void Draw() const override;
	AbstractScene* Change() override;
};
