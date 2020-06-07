#include "..\Inc\Enemy.hpp"

const uint8_t Enemy::width = 11;
const uint8_t Enemy::height = 8;
const std::vector<uint8_t> Enemy::displayVector = {0x70, 0x18, 0x7D, 0xB6, 0xBC, 0x3C, 0xBC, 0xB6, 0x7D, 0x18, 0x70};


Enemy::Enemy(){}
Enemy::Enemy(uint8_t x, uint8_t y, uint8_t hp, bool loopMovement, std::vector<std::pair<uint8_t,uint8_t>> moveVec){
	this->positionX = x;
	this->positionY = y;
	this->hp = hp;
	this->loopMovement = loopMovement;
	this->moveVec = moveVec;
	this->moveInx = 0;
	this->moveOverflow = 0;
	this->speed = 1;
}

std::vector<uint8_t> Enemy::getDisplayVec(){return displayVector;}
uint8_t Enemy::getHeight(){return height;}
uint8_t Enemy::getWidth(){return width;}

void Enemy::movement() {
	if (move(speed)){
		while (move(moveOverflow)){}
	}
}

bool Enemy::move(uint8_t spd){
	if (positionX == moveVec[moveInx].first){
		if (positionY < moveVec[moveInx].second){
			if (positionY + spd > moveVec[moveInx].second){
				moveOverflow = positionY + spd - moveVec[moveInx].second;
				positionY = moveVec[moveInx].second;
				return true;
			}
			else
			{
				positionY += spd;
				moveOverflow = 0;
				return false;
			}
			
		}
		else if (positionY > moveVec[moveInx].second)
		{
			if (positionY - spd < moveVec[moveInx].second){
				moveOverflow = moveVec[moveInx].second - (positionY - spd);
				positionY = moveVec[moveInx].second;
				return true;
			}
			else
			{
				positionY -= spd;
				moveOverflow = 0;
				return false;
			}
		}

		if (positionY == moveVec[moveInx].second){
			if ((moveInx == moveVec.size()-1) && (loopMovement == 1)){
				moveInx = 0;
			}
			else if (moveInx < moveVec.size()-1){
				moveInx++;
			}
		}
	}
	else if (positionY == moveVec[moveInx].second){
		if (positionX < moveVec[moveInx].first){
			if (positionX + spd > moveVec[moveInx].first){
				moveOverflow = positionX + spd - moveVec[moveInx].first;
				positionX = moveVec[moveInx].first;
				return true;
			}
			else
			{
				positionX += spd;
				moveOverflow = 0;
				return false;
			}
			
		}
		else if (positionX > moveVec[moveInx].first)
		{
			if (positionX - spd < moveVec[moveInx].first){
				moveOverflow = moveVec[moveInx].first - (positionX - spd);
				positionX = moveVec[moveInx].first;
				return true;
			}
			else
			{
				positionX -= spd;
				moveOverflow = 0;
				return false;
			}
		}

		if (positionX == moveVec[moveInx].first){
			if ((moveInx == moveVec.size()-1) && (loopMovement == 1)){
				moveInx = 0;
			}
			else if (moveInx < moveVec.size()-1){
				moveInx++;
			}
		}
	}
	return false;
}
