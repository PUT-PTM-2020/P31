#include "..\Inc\Enemy.hpp"

Enemy::Enemy(){
	height = 8;
	width = 11;
	hp = 3;
	displayVector = {0x70, 0x18, 0x7D, 0xB6, 0xBC, 0x3C, 0xBC, 0xB6, 0x7D, 0x18, 0x70};
}

Enemy::Enemy(uint8_t x, uint8_t y, uint8_t h, uint8_t w, uint8_t hp2, std::vector<uint8_t> dispVec, bool loopMovement, std::vector<std::pair<uint8_t,uint8_t>> moveVec){
	this->positionX = x;
	this->positionY = y;
	this->height = h;
	this->width = w;
	this->hp = hp2;
	this->displayVector = dispVec;
	this->loopMovement = loopMovement;
	this->moveVec = moveVec;
	this->movePtr = &this->moveVec.at(0);
}

bool Enemy::shot() {}
void Enemy::movement() {
	if (move(speed)){
		while (move(moveOverflow)){}
	}
}
bool Enemy::move(uint8_t spd){
	if (positionX == movePtr->first){
		if (positionY < movePtr->second){
			if (positionY + spd > movePtr->second){
				moveOverflow = positionY + spd - movePtr->second;
				positionY = movePtr->second;
				return 1;
			}
			else
			{
				positionY += spd;
				moveOverflow = 0;
				return 0;
			}
			
		}
		else if (positionY > movePtr->second)
		{
			if (positionY - spd < movePtr->second){
				moveOverflow = movePtr->second - (positionY - spd);
				positionY = movePtr->second;
				return 1;
			}
			else
			{
				positionY -= spd;
				moveOverflow = 0;
				return 0;
			}
		}

		if (positionY == movePtr->second){
			movePtr++;
		}
	}
	else if (positionY == movePtr->second){
		if (positionX < movePtr->first){
			if (positionX + spd > movePtr->first){
				moveOverflow = positionX + spd - movePtr->first;
				positionX = movePtr->first;
				return 1;
			}
			else
			{
				positionX += spd;
				moveOverflow = 0;
				return 0;
			}
			
		}
		else if (positionX > movePtr->first)
		{
			if (positionX - spd < movePtr->first){
				moveOverflow = movePtr->first - (positionX - spd);
				positionX = movePtr->first;
				return 1;
			}
			else
			{
				positionX -= spd;
				moveOverflow = 0;
				return 0;
			}
		}

		if (positionX == movePtr->first){
			movePtr++;
		}
	}
}