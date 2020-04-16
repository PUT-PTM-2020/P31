#include "gameClasses.hpp"

void Entity::setX(uint8_t x) {
	positionX = x;
}
void Entity::setY(uint8_t y) {
	positionY = y;
}

void Entity::setXY(uint8_t x, uint8_t y) {
	positionX = x;
	positionY = y;
}

Player::Player(){
	positionX = 20;
	positionY = 39;
	height = 8;
	width = 11;
	hp = 3;
	displayVector = {0x70, 0x18, 0x7D, 0xB6, 0xBC, 0x3C, 0xBC, 0xB6, 0x7D, 0x18, 0x70};
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
