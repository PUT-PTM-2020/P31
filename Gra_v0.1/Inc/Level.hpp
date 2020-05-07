#pragma once

#include "Includes.hpp"
#include "Enemy.hpp"
#include "Player.hpp"
#include "Shot.hpp"

class Level {
public:
	Player player;
	std::vector<Enemy> Enemies;
	std::vector<Entity> Constructions;

	Level();
	void start();
	void end();
};
