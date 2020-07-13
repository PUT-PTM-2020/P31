#pragma once

#include "Enemy.hpp"
#include "Player.hpp"
#include "PointColission.hpp"
#include "Construction.hpp"
#include "Boss.hpp"

class Shot;

class Level {
private:
	
	/**
	 * If true enemies will shoot.
	 * If false they won't.
	*/
	const bool eShooting;
	

	const uint8_t bulletSpeed;

	/**
	 * Moves pointed shot and checks collision and apply damage form it
	 * 
	 * ARG:
	 * 	sorce - false for enemyShot; true for playerShot
	*/
	void bulletManagement(bool sorce);
	void enemyShoot();
	void playerCollision();
	
	void bossShoot();

public:
	Player player;
	std::vector<Enemy> Enemies;
	std::vector<Construction> Constructions;
	Shot* enemyShot;
	Shot* playerShot;
	Boss* boss_ptr;

	Level(bool eShooting);
	void play();

	/**
	 * Checks if either the player or all enemies were killed,
	 * which means that the level has ended.
	 * 
	 * RET:
	 * 	true if the level is finished
	*/
	bool finished();

	/**
	 * Saves amount of enemies, constructions, coordinates of enemies,
	 * constructions, enemies hp and constructions hp in binary file.
	 * 
	 * ARG:
	 * 	name - path or name file
	 * RET:
	 * 	Nothing
	*/
	void save(std::string name);
	void saveF(std::string path);

	/**
	 * Load amount of enemies, constructions, coordinates of enemies,
	 * constructions, enemies hp and constructions hp from binary file.
	 * 
	 * ARG:
	 * 	name - path or name file
	 * RET:
	 * 	Nothing
	*/
	void load(std::string name);
	void loadF(char buffer[], Level&l);
	bool playerShoot();

};

