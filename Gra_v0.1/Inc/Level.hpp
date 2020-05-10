#pragma once

#include "Enemy.hpp"
#include "Player.hpp"
#include "PointColission.hpp"
#include "Construction.hpp"

class Shot;

class Level {
private:
	
	/**
	 * If true enemies will shoot.
	 * If false they won't.
	*/
	const bool eShooting;
	
	Shot* enemyShot;
	Shot* playerShot;
	const uint8_t bulletSpeed; //TODO: bulletSpeed - Find value bigger than player speed

	/**
	 * Moves pointed shot and checks collision and apply damage form it
	 * 
	 * ARG:
	 * 	sorce - false for enemyShot; true for playerShot
	*/
	void bulletManagement(bool sorce);
	void enemyShoot();
	void playerCollision();

public:
	Player player;
	std::vector<Enemy> Enemies;
	std::vector<Construction> Constructions;

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
	void save(std::string name);
	void load(std::string name);
	void playerShoot();

};

/*
	Wzór zamysłu wywołania poziomu z plików STMa
	TODO: This is just a reminder
{
	Level lvl;
	lvl.load( args ); //load bin file
	while(!lvl.finished()){
		if (#shootButton)
			lvl.playerShoot();
		else if (#joystick)
			lvl.player.setXY();
		
		lvl.play();
		display(lvl);
	}
}
*/