#include "..\Inc\Enemy.hpp"

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

bool Enemy::shot() {}
void Enemy::movement() {}