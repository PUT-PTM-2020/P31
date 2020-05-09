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

	/**
	 * Substract 1 from object hp
	 * 
	 * RET:
	 * 	true if object hp reached 0 or less; false otherwise
	*/
	bool hit();
};