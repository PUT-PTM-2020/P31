#include "..\Inc\Character.hpp"

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