#pragma once

#include "Includes.hpp"
#include "Enemy.hpp"

class Boss : public Enemy {
public:
	Boss();
	virtual bool shot() override;
	virtual void movement() override;
};