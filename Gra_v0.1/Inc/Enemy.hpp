#pragma once

#include "Entity.hpp"


class Enemy : public Entity {
private:

	static const std::vector<uint8_t> displayVector;
	static const uint8_t height;
	static const uint8_t width;
	
	/**
	 * Changes Enemy object coordinates according to moveInx, sets Overflow and moveInx.
	 * 
	 * Changes Enemy object coordinates in one dimention, but no further than point
	 * set by moveInx. If object reaches the point before it uses all it's move distance,
	 * the moveOverflow is set to the ammount of distance that was left.
	 * It changes the moveInx after reaching pointed point form moveVec.
	 * 
	 * ARG:
	 * 	spd - the maximum value that an object can move
	 * RET:
	 * 	true if it didn't used all avaible distance; false otherwise
	*/
	bool move(uint8_t spd);
	
	/**
	 * Variable set by move() and used for movement(). Set to 0 after every call of movement().
	*/
	uint8_t moveOverflow;

public:

	/**
	 * Vector of points (x,y) creating a movement path.
	*/
	std::vector<std::pair<uint8_t,uint8_t>> moveVec;

	/**
	 * If true, moveInx will return to 0 after reaching maximum moveVec index.
	*/
	bool loopMovement;
	
	/**
	 * The disctance an object can move with one movement function.
	*/
	uint8_t speed;

	/**
	 * moveVec index of next point to reach by an object.
	*/
	unsigned int moveInx;


	Enemy();
	Enemy(uint8_t x, uint8_t y, uint8_t hp, bool loopMovement, std::vector<std::pair<uint8_t,uint8_t>> moveVec);

	/**
	 * Moves object by the speed value as a distance.
	 * 
	 * ARG:
	 * 	None
	 * RET:
	 * 	Nothing
	*/
	void movement();

	std::vector<uint8_t> getDisplayVec();
	uint8_t getHeight();
	uint8_t getWidth();

};