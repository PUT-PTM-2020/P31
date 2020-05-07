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
	this->moveInx = 0;
}

bool Enemy::shot() {}
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
				return 1;
			}
			else
			{
				positionY += spd;
				moveOverflow = 0;
				return 0;
			}
			
		}
		else if (positionY > moveVec[moveInx].second)
		{
			if (positionY - spd < moveVec[moveInx].second){
				moveOverflow = moveVec[moveInx].second - (positionY - spd);
				positionY = moveVec[moveInx].second;
				return 1;
			}
			else
			{
				positionY -= spd;
				moveOverflow = 0;
				return 0;
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
				return 1;
			}
			else
			{
				positionX += spd;
				moveOverflow = 0;
				return 0;
			}
			
		}
		else if (positionX > moveVec[moveInx].first)
		{
			if (positionX - spd < moveVec[moveInx].first){
				moveOverflow = moveVec[moveInx].first - (positionX - spd);
				positionX = moveVec[moveInx].first;
				return 1;
			}
			else
			{
				positionX -= spd;
				moveOverflow = 0;
				return 0;
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
}