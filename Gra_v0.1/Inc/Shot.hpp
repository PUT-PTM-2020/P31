#pragma once

#include "Includes.hpp"

class Shot {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t speed;
	uint8_t power;

	Shot();
	void setX();
	void setY();
	void movement();
};