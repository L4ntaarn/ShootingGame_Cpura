#include "Player.h"

Player::Player() {
	playerImg = LoadGraph("images/Rocket.png");
}

Player::~Player() {

}

void Player::Update() {

}

void Player::Draw() {
	DrawGraph(200, 20, playerImg, false);
}