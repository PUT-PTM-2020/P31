#pragma once

#include "Includes.hpp"

class Level;
class Shot {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t speed;
	// uint8_t power;

	Shot();
	Shot(uint8_t X, uint8_t Y, uint8_t speed);
	//Shot(uint8_t X, uint8_t Y);

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
	 * 	a pair of the name of the vector ("Enemies"/Constructions") or "Player" of
	 * 	the shooted entity and it's index if it's a vector (0 otherwise)
	*/
	std::pair<std::string, uint8_t> shooted(Level& activeLevel);
};
