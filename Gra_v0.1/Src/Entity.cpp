#include "..\Inc\Entity.hpp"

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