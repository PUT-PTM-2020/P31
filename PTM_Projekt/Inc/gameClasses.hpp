#pragma once

#include "stm32f4xx_hal.h"
#include "spi.h"
#include "gpio.h"
#include "display.h"
#include <vector>

class Character {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t height;
	uint8_t width;
	uint8_t hp;
	std::vector<uint8_t> displayVector;

	Character() {}
	virtual ~Character() {};
	void setX(uint8_t x);
	void setY(uint8_t y);
	void setXY(uint8_t x, uint8_t y);
	virtual void shot() = 0;
	virtual void movement() = 0;
};

class Player : public Character {
public:
	Player();
	Player(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> vec);
	~Player() {};
	virtual void shot() override;
	virtual void movement() override;
};

class Enemy : public Character {
public:
	Enemy();
	Enemy(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> vec);
	virtual void shot() override;
	virtual void movement() override;
};

class Boss : public Enemy {
public:
	Boss();
	virtual void shot() override;
	virtual void movement() override;
};

class Entity {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t height;
	uint8_t width;
	uint8_t hp;
	std::vector<uint8_t> displayVector;
	Entity();
};

class Shot {
public:
	uint8_t positionX;
	uint8_t positionY;
	uint8_t speed;
	uint8_t power;

	Shot();
	void setX();
	void setY();
	void movement();
};

class Level {
public:
	Player player;
	std::vector<Enemy> Enemies;
	std::vector<Entity> Constructions;

	Level();
	void start();
	void end();
};
