#include "..\Inc\Player.hpp"
#include "..\Inc\Shot.hpp"

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

bool Player::shot() {
	Shot projectile();
}
void Player::movement() {}