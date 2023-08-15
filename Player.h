#pragma once
#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"

class Player {
private:
	int playerImg;

public:
	Player();
	~Player();

	void Update();
	void Draw();
};