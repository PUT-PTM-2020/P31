#include "gameClasses.hpp"

void Character::setX(uint8_t x) {
	positionX = x;
}
void Character::setY(uint8_t y) {
	positionY = y;
}

void Character::setXY(uint8_t x, uint8_t y) {
	positionX = x;
	positionY = y;
}

Player::Player(){
	positionX = 20;
	positionY = 39;
	height = 4;
	width = 9;
	hp = 3;
	displayVector = {0x08, 0x0C, 0x0E, 0x06, 0x07, 0x06, 0x0E, 0x0C, 0x08};
}

Player::Player(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> vec){
	positionX = x;
	positionY = y;
	height = h;
	width = w;
	hp = hp2;
	displayVector = vec;
}

void Player::shot() {}
void Player::movement() {}

Enemy::Enemy(){
	positionX = 4;
	positionY = 0;
	height = 8;
	width = 11;
	hp = 3;
	displayVector = {0x70, 0x18, 0x7D, 0xB6, 0xBC, 0x3C, 0xBC, 0xB6, 0x7D, 0x18, 0x70};
}

Enemy::Enemy(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> vec){
	positionX = x;
	positionY = y;
	height = h;
	width = w;
	hp = hp2;
	displayVector = vec;
}

void Enemy::shot() {}
void Enemy::movement() {}

Entity::Entity() {
	positionX = 40;
	positionY = 0;
	height = 8;
	width = 15;
	hp = 10;
	displayVector = {0x18, 0x3C, 0x7E, 0xFF, 0xFF, 0x7F, 0x3F, 0x1F, 0x3F, 0x7F, 0xFF, 0xFF, 0x7E, 0x3C, 0x18};
}
