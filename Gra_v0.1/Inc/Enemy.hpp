#pragma once

#include "Includes.hpp"
#include "Character.hpp"


class Enemy : public Character {
private:
	bool move(uint8_t spd);

public:
	/**
	 * Vector of points (x,y) 
	*/
	std::vector<std::pair<uint8_t,uint8_t>> moveVec;
	bool loopMovement;
	uint8_t speed;
	unsigned int moveInx;
	uint8_t moveOverflow;

	Enemy();
	Enemy(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> dispVec, bool loopMovement, std::vector<std::pair<uint8_t,uint8_t>> moveVec);
	virtual bool shot() override;
	virtual void movement() override;
};