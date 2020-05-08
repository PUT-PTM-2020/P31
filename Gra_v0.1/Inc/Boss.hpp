#pragma once

#include "Includes.hpp"
#include "Enemy.hpp"

class Boss : public Character {
public:
	Boss();
	bool shot();
	void movement();
};