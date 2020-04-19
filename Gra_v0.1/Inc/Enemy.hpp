#pragma once

#include "Includes.hpp"
#include "Entity.hpp"


class Enemy : public Entity {
public:
	Enemy();
	Enemy(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> vec);
	virtual void shot() override;
	virtual void movement() override;
};