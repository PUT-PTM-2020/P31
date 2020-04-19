#pragma once

#include "Includes.hpp"

class Entity {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t height;
	uint8_t width;
	uint8_t hp;
	std::vector<uint8_t> displayVector;

	Entity() {}
	virtual ~Entity() {};
	void setX(uint8_t x);
	void setY(uint8_t y);
	void setXY(uint8_t x, uint8_t y);
	virtual void shot() = 0;
	virtual void movement() = 0;
};