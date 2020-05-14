#include "..\Inc\Player.hpp"
#include "..\Inc\Shot.hpp"

const std::vector<uint8_t> Player::displayVector = {0x08, 0x0C, 0x0E, 0x06, 0x07, 0x06, 0x0E, 0x0C, 0x08};
const uint8_t Player::width = 9;
const uint8_t Player::height = 4;

Player::Player(){}
Player::Player(uint8_t x, uint8_t y, uint8_t hp){
	this->positionX = x;
	this->positionY = y;
	this->hp = hp;
}
Player::~Player(){}

std::vector<uint8_t> Player::getDisplayVec(){return displayVector;}
uint8_t Player::getHeight(){return height;}
uint8_t Player::getWidth(){return width;}