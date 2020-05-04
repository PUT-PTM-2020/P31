#pragma once

#include "Includes.hpp"
#include "Character.hpp"

class Player : public Character {
public:
	Player();
	Player(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> vec);
	~Player() {};
	virtual bool shot() override;
	virtual void movement() override;
};