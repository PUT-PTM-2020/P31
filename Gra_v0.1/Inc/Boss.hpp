#pragma once

#include "Entity.hpp"

class Boss : public Entity {
private:
	static const std::vector<uint8_t> displayVector;
	static const uint8_t height;
	static const uint8_t width;
public:
	Boss();
	~Boss();
	std::vector<uint8_t> getDisplayVec();
	uint8_t getHeight();
	uint8_t getWidth();
};