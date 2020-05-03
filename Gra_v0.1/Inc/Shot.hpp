#pragma once

#include "Includes.hpp"
#include "Entity.hpp"
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
	void setSpeed(uint8_t speed);
	void movement();

	/**
	 * Finds collision between Shot object and Entity objects from level.
	 * 
	 * Searches through level's Enemies and Constructions vectors, and Player object.
	 * Checks if Shot object coordinates are in any of level's Entity area.
	 * 
	 * ARG:
	 * 	activeLevel - reference to level
	 * RET:
	 * 	poinetr to Entity object that collided with the Shot object; nullptr otherwise
	*/
	Entity* shooted(Level& activeLevel);
};