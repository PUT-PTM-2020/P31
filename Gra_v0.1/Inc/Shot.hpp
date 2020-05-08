#pragma once

#include "Level.hpp"

class Shot {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t speed;
	// uint8_t power;

	Shot();
	Shot(uint8_t X, uint8_t Y, uint8_t speed);

	/**
 	 * Setter X
 	 * 
 	 * ARG:
 	 *  x - x-axis coordinate
 	 * RET:
 	 *  void
	*/
	void setX(uint8_t X);

	/**
	 * Setter Y
 	 * 
 	 * ARG:
 	 *  y - y-axis coordinate
 	 * RET:
 	 *  void
	*/
	void setY(uint8_t Y);

	/**
	 * Setter speed
 	 * 
 	 * ARG:
 	 *  speed - shot speed value
 	 * RET:
 	 *  void
	*/
	void setSpeed(uint8_t speed);

	/**
	 * Changes object horizontal position by it's speed value.
	 * Positive speed value moves object up, negative - down
	*/
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