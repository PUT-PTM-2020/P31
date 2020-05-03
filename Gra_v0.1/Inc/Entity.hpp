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
	Entity();
};