#pragma once

#include "Includes.hpp"

class Entity {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t hp;
	Entity();
	~Entity();
	virtual std::vector<uint8_t> getDisplayVec() = 0;
	virtual uint8_t getHeight()=0;
	virtual uint8_t getWidth()=0;
};