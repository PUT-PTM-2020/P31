#pragma once

#include "Includes.hpp"
#include "Enemy.hpp"

class Boss : public Enemy {
public:
	Boss();
	virtual void shot() override;
	virtual void movement() override;
};