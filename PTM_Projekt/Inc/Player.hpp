#pragma once

#include "Entity.hpp"

class Player : public Entity {
private:
	static const std::vector<uint8_t> displayVector;
	static const uint8_t height;
	static const uint8_t width;

public:
	Player();
	Player(uint8_t x, uint8_t y, uint8_t hp);
	~Player();
	std::vector<uint8_t> getDisplayVec();
	uint8_t getHeight();
	uint8_t getWidth();
};