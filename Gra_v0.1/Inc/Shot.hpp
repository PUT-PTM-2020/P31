#pragma once

#include "Includes.hpp"
#include "Character.hpp"
#include "Level.hpp"

class Shot {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t speed;
	// uint8_t power;

	Shot();
	Shot(uint8_t X, uint8_t Y, uint8_t speed);
	void setX(uint8_t X);
	void setY(uint8_t Y);
	void movement();
	Character* shooted();
};