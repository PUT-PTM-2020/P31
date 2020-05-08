#pragma once

#include "Entity.hpp"

class Boss : public Entity {
public:
	Boss();
	bool shot();
	void movement();
	std::vector<uint8_t> getDisplayVec();
	uint8_t getHeight();
	uint8_t getWidth();
};